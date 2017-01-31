#include "device.hpp"

class server: public device{
public:
    const char* sentance;

    void receiveMSG();
    void sendMSG();
    void test();
};