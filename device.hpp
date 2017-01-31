#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>

#ifndef DEVICE_H
#define DEVICE_H

struct sockaddr_in {
	__uint8_t	sin_len;
	sa_family_t	sin_family;
	in_port_t	sin_port;
	    in_addr sin_addr;
	char		sin_zero[8];
};

class device{
protected:
    sockaddr_in Addr;
    socklen_t Addrlen;
    int Socketfd;
public:
    int Buffer_size;
    char * Buffer;

    void readFromSocket();
    void writeToSocket();

    device(sockaddr_in addr, socklen_t addrlen, int buffer_size);
    ~device();
};

#endif