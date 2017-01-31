/*
    Created by Richard Lynch 

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <queue>
#include <errno.h>
#include <unistd.h>
#include "client.hpp"
#include "server.hpp"

pthread_mutex_t lock;

int main(int argc, char *argv[])
{
// starting
    printf("Hello\n\n");

// init mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\nlock mutex init failed\n");
        return 1;
    }

// read args
    int firstarg;
    if (argc < 2 || (firstarg = atoi(argv[1])) <= 0)
    { //convert the first arg to an int
        //if there is not arg entered
        printf("No Args Entered");
        //exit(1);
    }

// start clock
    // printf("Starting Clock\n");
    // clock_t start = clock();

// -----------------------------------MAIN-------------------------------------------
    //create socket address
    struct sockaddr_in talker_add;
    struct sockaddr_in listener_add;

    char *srvr_addr = NULL;
    srvr_addr = "127.0.0.1"; //Use default address

    memset(&listener_add, 0, sizeof listener_add);
	listener_add.sin_family = AF_INET;
	listener_add.sin_port = htons(9090);
	listener_add.sin_addr.s_addr = inet_addr(srvr_addr);
	if(listener_add.sin_addr.s_addr == INADDR_NONE)
	{
		printf("bad address.\n");
	}

    char *_addr = NULL;
    _addr = "127.0.0.1"; //Use default address

    memset(&talker_add, 0, sizeof talker_add);
	talker_add.sin_family = AF_INET;
	talker_add.sin_port = htons(9090);
	talker_add.sin_addr.s_addr = inet_addr(_addr);
	if(talker_add.sin_addr.s_addr == INADDR_NONE)
	{
		printf("bad address.\n");
	}


    client talker(talker_add, (socklen_t) sizeof(_addr), 100);
    server listener(listener_add, (socklen_t) sizeof(_addr), 100);

    listener.test();
    talker.test();

// ----------------------------------------------------------------------------------

// stop the cock
    // printf("Stoping Clock\n");
    // clock_t tdiff = clock() - start;

// destroy mutex
    pthread_mutex_destroy(&lock);

// done
    printf("Goodbye\n\n");

    return 0;
}