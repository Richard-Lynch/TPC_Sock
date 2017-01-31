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

class device{
protected:
    struct sockaddr Addr;
    socklen_t Addrlen;
    int Socketfd;
public:
    int Buffer_size;
    char * Buffer;

    void readFromSocket();
    void writeToSocket();

    device(struct sockaddr addr, socklen_t addrlen, int buffer_size);
    ~device();
};

#endif