#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/mount.h>
#include <sys/stat.h>

#include "types.h"
#include "chroot.h"

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

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
    char filepath[PATH_MAX + 1];

    if ((dir = opendir(path)) == NULL)
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(filepath, path);
        strcat(filepath, "/");
        strcat(filepath, entry->d_name);

        if (entry->d_type == DT_DIR)
            remove_directory(filepath);
        else
            unlink(filepath);
    }

    closedir(dir);
    rmdir(path);
}

Str chroot_setup(String name) {
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

Str chroot_destroy(String name) {
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
