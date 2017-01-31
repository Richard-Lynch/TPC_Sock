#include "device.hpp"

class client: public device{
public:
    const char* sentance;

    void receiveMSG();
    void sendMSG();
    void test();
};