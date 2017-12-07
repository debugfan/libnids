#ifndef NETINET_UDP_H
#define NETINET_UDP_H

#include "ip.h"

/*
* UDP protocol header.
* Per RFC 768, September, 1981.
*/
struct udphdr {    
 	u_short	source;
	u_short	dest;
	u_short	len;
	u_short	uh_sum;   
};

#endif
