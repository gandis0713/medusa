

#ifndef MEDUSA_UTIL_H
#define MEDUSA_UTIL_H

#include <xf86drm.h>
static inline int
medusa_ioctl(int fd, unsigned long request, void* arg)
{
    return drmIoctl(fd, request, arg);
}

#endif // MEDUSA_UTIL_H
