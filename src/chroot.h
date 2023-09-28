#ifndef _CHROOT_H
#define _CHROOT_H
#include "types.h"

typedef struct {
    String from, to, fs;
    const unsigned long flags;
    String msg;
} Mount;

void remove_directory(String);
MString chroot_setup(String);
MString chroot_destroy(String);
#endif /* _CHROOT_H */
