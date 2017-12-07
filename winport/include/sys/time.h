#ifndef SYS_TIME_H
#define SYS_TIME_H

#include <winsock2.h>
#include <windows.h>

int gettimeofday(struct timeval * tp, struct timezone * tzp);

#endif
