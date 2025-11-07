
/*
========================================================================================================
Name : Q33Server.c
Author : Rohit Bansal
Description : Write a program to communicate between two machines using socket.
Date: 30 Sept, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *response = "Hello from server";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    listen(server_fd, 3);
    printf("Server is listening on port %d\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
  
    read(new_socket, buffer, 1024);
    printf("Received from client: %s\n", buffer);

    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client\n");

    close(new_socket);
    close(server_fd);

    return 0;
}
/*
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# ./server 
Server is listening on port 8080
Received from client: Hello from client
Response sent to client
root@LAPTOP-6DS5S9T7:/home/iiitb/Handsonlist2# 
*/