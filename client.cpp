#include "client.hpp"

// client::client(struct sockaddr addr, socklen_t addrlen, int buffer_size){
//     device()
// }

void client::receiveMSG(){
    readFromSocket();
    printf("Message received by client: %s\nLength: %d", Buffer, Buffer_size);
}
void client::sendMSG(){
    // Buffer_size = strlen(sentance);
    writeToSocket();
}
void client::test(){
    sentance = "This is from the client\n";
    strcpy(Buffer, sentance);
    while(1){
        sendMSG();
    }
}