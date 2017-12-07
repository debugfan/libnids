#ifndef NETINET_TCP_H
#define NETINET_TCP_H

#include "ip.h"

typedef	unsigned int tcp_seq;

/*
* TCP header.
* Per RFC 793, September, 1981.
*/
struct tcphdr {
    u_short	th_sport;		/* source port */
    u_short	th_dport;		/* destination port */
    tcp_seq	th_seq;			/* sequence number */
    tcp_seq	th_ack;			/* acknowledgement number */
#if PH_BYTE_ORDER == PH_LITTLE_ENDIAN
    u_char	th_x2 : 4,		/* (unused) */
    th_off : 4;		/* data offset */
#endif
#if PH_BYTE_ORDER == PH_BIG_ENDIAN
    u_char	th_off : 4,		/* data offset */
    th_x2 : 4;		/* (unused) */
#endif
    u_char	th_flags;
#define	TH_FIN	0x01
#define	TH_SYN	0x02
#define	TH_RST	0x04
#define	TH_PUSH	0x08
#define	TH_ACK	0x10
#define	TH_URG	0x20
#define	TH_ECE	0x40
#define	TH_CWR	0x80
#define	TH_FLAGS	(TH_FIN|TH_SYN|TH_RST|TH_PUSH|TH_ACK|TH_URG|TH_ECE|TH_CWR)
#define	PRINT_TH_FLAGS	"\20\1FIN\2SYN\3RST\4PUSH\5ACK\6URG\7ECE\10CWR"

    u_short	th_win;			/* window */
    u_short	th_sum;			/* checksum */
    u_short	th_urp;			/* urgent pointer */
};

#endif
