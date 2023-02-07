#ifndef _DLFCN_H
#define _DLFCN_H

#include <features.h>

#define RTLD_LAZY   0x00001
#define RTLD_NOW    0x00002
#define RTLD_BINDING_MASK   0x3
#define RTLD_NOLOAD    0x00004
#define RTLD_DEEPBIND  0x00008

#ifdef __cplusplus
extern "C" {
#endif

void *dlopen (const char *__file, int __mode);

void *dlsym (void *__restrict __handle,
       const char *__restrict __name);

int dlclose (void *__handle);

char *dlerror (void);

#ifdef __cplusplus
}
#endif

#endif
