
#ifndef __GS_COMMON_H__
#define __GS_COMMON_H__ 1

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <inttypes.h>
#include <signal.h>
#include <libgen.h>		/* basename() */
#include <openssl/srp.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#ifndef MAX
# define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
#endif

#ifndef MIN
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#endif

#define D_RED(a)	"\033[0;31m"a"\033[0m"
#define D_GRE(a)	"\033[0;32m"a"\033[0m"
#define D_YEL(a)	"\033[0;33m"a"\033[0m"
#define D_BLU(a)	"\033[0;34m"a"\033[0m"
#define D_MAG(a)	"\033[0;35m"a"\033[0m"
#define D_BRED(a)	"\033[1;31m"a"\033[0m"
#define D_BGRE(a)	"\033[1;32m"a"\033[0m"
#define D_BYEL(a)	"\033[1;33m"a"\033[0m"
#define D_BBLU(a)	"\033[1;34m"a"\033[0m"
#define D_BMAG(a)	"\033[1;35m"a"\033[0m"
#ifdef DEBUG
# define DEBUGF(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(stderr, a); }while(0)
# define DEBUGF_R(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(gs_dout, "\033[1;31m"); fprintf(gs_dout, a); fprintf(gs_dout, "\033[0m"); }while(0)
# define DEBUGF_G(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(gs_dout, "\033[1;32m"); fprintf(gs_dout, a); fprintf(gs_dout, "\033[0m"); }while(0)
# define DEBUGF_B(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(gs_dout, "\033[1;34m"); fprintf(gs_dout, a); fprintf(gs_dout, "\033[0m"); }while(0)
# define DEBUGF_Y(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(gs_dout, "\033[1;33m"); fprintf(gs_dout, a); fprintf(gs_dout, "\033[0m"); }while(0)
# define DEBUGF_M(a...) do{ if (gs_dout == NULL) break; fprintf(gs_dout, D_BLU("LIB")" %s:%d: ", __func__, __LINE__); fprintf(gs_dout, "\033[1;35m"); fprintf(gs_dout, a); fprintf(gs_dout, "\033[0m"); }while(0)
#else
# define DEBUGF(a...)
# define DEBUGF_R(a...)
# define DEBUGF_G(a...)
# define DEBUGF_B(a...)
# define DEBUGF_Y(a...)
# define DEBUGF_M(a...)
#endif

#define XFREE(ptr)  do{if(ptr) free(ptr); ptr = NULL;}while(0)

#ifdef DEBUG
# define ERREXIT(a...)   do { \
	fprintf(stderr, "ERROR "); \
        fprintf(stderr, "%s():%d ", __func__, __LINE__); \
        fprintf(stderr, a); \
        exit(255); \
} while (0)
#else
# define ERREXIT(a...)   do { \
	fprintf(stderr, "ERROR: "); \
        fprintf(stderr, a); \
        exit(255); \
} while (0)
#endif

#ifndef XASSERT
# define XASSERT(expr, a...) do { \
	if (!(expr)) { \
		fprintf(stderr, "%s:%d:%s() ASSERT(%s) ", __FILE__, __LINE__, __func__, #expr); \
		fprintf(stderr, a); \
		fprintf(stderr, " Exiting...\n"); \
		exit(255); \
	} \
} while (0)
#endif

#ifdef DEBUG
# define HEXDUMP(a, len)        do { \
        int n = 0; \
        fprintf(gs_dout, D_BLU("LIB")" %s:%d HEX ", __FILE__, __LINE__); \
        while (n < len) fprintf(gs_dout, "%2.2x", ((unsigned char *)a)[n++]); \
        fprintf(gs_dout, "\n"); \
} while (0)

# define HEXDUMPF(a, len, m...) do{fprintf(gs_dout, m); HEXDUMP(a, len);}while(0)
#else
# define HEXDUMP(a, len)
# define HEXDUMPF(a, len, m...)
#endif

#endif /* !__GS_COMMON_H__ */
