#include "device.hpp"

void device::readFromSocket(){
    recv(Socketfd, Buffer,  Buffer_size, 0);
}
void device::writeToSocket(){
    send(Socketfd, Buffer,  Buffer_size, 0);
}

device::device(sockaddr_in addr, socklen_t addrlen, int buffer_size){
    Addr = addr;
    Addrlen = addrlen;
    Buffer_size = buffer_size;
    Buffer = (char*)malloc(sizeof(char)*Buffer_size);
    Socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(Socketfd, &(Addr.sin_addr), Addrlen);
}

device::~device(){
    free(Buffer);
}