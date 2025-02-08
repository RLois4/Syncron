#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "include/server.h"

#define PORT 7050 	
#define BACKLOG 5
#define BUFFER_SiZE 200


struct sockaddr_in	serveraddr, clientaddr;
char client_buffer[BUFFER_SIZE];
char server_buffer[BUFFER_SIZE];

start_server(const unsigned short)

