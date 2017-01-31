#include "device.hpp"

class client: public device{
public:
    const char* sentance;

    void receiveMSG();
    void sendMSG();
    void test();
    client(sockaddr_in addr, socklen_t addrlen, int buffer_size):device(addr, addrlen, buffer_size){}
};