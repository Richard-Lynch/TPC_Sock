#include "server.hpp"

void server::receiveMSG(){
    readFromSocket();
    printf("Message received by server: %s\nLength: %d", Buffer, Buffer_size);
}
void server::sendMSG(){
    // Buffer_size = strlen(sentance);
    writeToSocket();
}
void server::test(){
    sentance = "This is from the server\n";
    strcpy(Buffer, sentance);
    while(1){
        receiveMSG();
    }
}