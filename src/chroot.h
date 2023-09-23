#ifndef _CHROOT_H
#define _CHROOT_H
typedef struct {
    const char *from, *to, *fs;
    const unsigned long flags;
    const char *msg;
} Mount;

void remove_directory(const char *const path);
const char *chroot_setup(const char *const);
const char *chroot_destroy(const char *const);
#endif /* _CHROOT_H */
