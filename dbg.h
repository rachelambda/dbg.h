#ifndef __DBG_H
#define __DBG_H

#include <stdio.h>

#ifdef ENABLE_DBG_H

# define DEBUG(fmt, ...) fprintf(stderr, "[%s:%s:%d]: " fmt "\n", \
	__FILE__, __func__, __LINE__, __VA_ARGS__)

# define VALFMTS "[%s:%s():%d] %s: "
# define VALFMTP "\n"

# define VAL(X) fprintf(stderr, _Generic((X), \
    char:           VALFMTS "%c"   VALFMTP, \
    unsigned char:  VALFMTS "%hhu" VALFMTP, \
    short:          VALFMTS "%h"   VALFMTP, \
    unsigned short: VALFMTS "%hu"  VALFMTP, \
    int:            VALFMTS "%d"   VALFMTP, \
    unsigned int:   VALFMTS "%u"   VALFMTP, \
    long:           VALFMTS "%l"   VALFMTP, \
    unsigned long:  VALFMTS "%lu"  VALFMTP, \
    char*:          VALFMTS "'%s'" VALFMTP, \
    default:        VALFMTS "0x%x" VALFMTP\
	), __FILE__, __func__, __LINE__, #X, X)
#else
# define DEBUG(...)
# define VAL(_)
#endif

#endif
