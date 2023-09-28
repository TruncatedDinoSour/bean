#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/mount.h>
#include <sys/stat.h>

#include "types.h"
#include "chroot.h"

#ifndef DT_DIR
#define DT_DIR 4
#endif

static const Mount mounts[] = {
    {"none", "proc", "proc", 0, "failed to create a procfs"},
    {"none", "sys", "sysfs", 0, "failed to create a sysfs"},
    {"/dev", "dev", NULL, MS_BIND, "failed to bind /dev to dev in chroot"},
};
static const size_t mounts_sz = sizeof(mounts) / sizeof(mounts[0]);

void remove_directory(String path) {
    DIR *dir;
    struct dirent *entry;

    char *filepath;
    size_t fp_len, dn_len;

    if ((dir = opendir(path)) == NULL)
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        fp_len = strlen(path);
        dn_len = strlen(entry->d_name);

        filepath = malloc(fp_len + dn_len + 2); /* +2 for `/` and `\0` */

        strncpy(filepath, path, fp_len);
        filepath[fp_len] = '/';
        strncat(filepath, entry->d_name, dn_len);

        if (entry->d_type == DT_DIR)
            remove_directory(filepath);
        else
            unlink(filepath);

        free(filepath);
    }

    closedir(dir);
    rmdir(path);
}

MString chroot_setup(String name) {
    UChar idx;
    const Mount *m;

    if (mkdir(name, 0700) == -1)
        return "failed to make the chroot environment directory";

    chdir(name);

    for (idx = 0; idx < mounts_sz; ++idx) {
        m = &mounts[idx];

        if (mkdir(m->to, 0700) == -1 ||
            mount(m->from, m->to, m->fs, m->flags, NULL) == -1)
            return m->msg;
    }

    chdir("..");

    return NULL;
}

MString chroot_destroy(String name) {
    UChar idx;
    const Mount *m;

    if (access(name, F_OK) != 0)
        return "no such chroot environment found";

    chdir(name);

    for (idx = 0; idx < mounts_sz; ++idx) {
        m = &mounts[idx];

        if (umount(m->to) == -1)
            return m->to;
    }

    chdir("..");

    remove_directory(name);

    return NULL;
}
