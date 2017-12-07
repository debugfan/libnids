#ifndef NETINET_IP_H
#define NETINET_IP_H

#ifdef _WIN32
#define	__packed	
#define __aligned(x) __declspec(align(x))
#else
#define	__packed	__attribute__((__packed__))
#define __aligned(x)	__attribute__((__aligned__(x)))
#endif

#include <Winsock2.h>
#include <Windows.h>

/*
* Definitions for byte order, according to byte significance from low
* address to high.
*/
#define	_PH_LITTLE_ENDIAN	1234	/* LSB first: i386, vax */
#define	_PH_BIG_ENDIAN	4321	/* MSB first: 68000, ibm, net */
#define	_PH_PDP_ENDIAN	3412	/* LSB first in word, MSW first in long */

#define	_PH_BYTE_ORDER	_PH_LITTLE_ENDIAN

#define	PH_LITTLE_ENDIAN	_PH_LITTLE_ENDIAN
#define	PH_BIG_ENDIAN	_PH_BIG_ENDIAN
#define	PH_PDP_ENDIAN	_PH_PDP_ENDIAN
#define	PH_BYTE_ORDER	_PH_BYTE_ORDER

/*
* Structure of an internet header, naked of options.
*/
struct ip {
#if PH_BYTE_ORDER == PH_LITTLE_ENDIAN
    u_char	ip_hl : 4,		/* header length */
    ip_v : 4;			/* version */
#endif
#if PH_BYTE_ORDER == PH_BIG_ENDIAN
    u_char	ip_v : 4,			/* version */
    ip_hl : 4;		/* header length */
#endif
    u_char	ip_tos;			/* type of service */
    u_short	ip_len;			/* total length */
    u_short	ip_id;			/* identification */
    u_short	ip_off;			/* fragment offset field */
#define	IP_RF 0x8000			/* reserved fragment flag */
#define	IP_DF 0x4000			/* dont fragment flag */
#define	IP_MF 0x2000			/* more fragments flag */
#define	IP_OFFMASK 0x1fff		/* mask for fragmenting bits */
    u_char	ip_ttl;			/* time to live */
    u_char	ip_p;			/* protocol */
    u_short	ip_sum;			/* checksum */
    struct	in_addr ip_src, ip_dst;	/* source and dest address */
} __packed __aligned(4);

#endif
