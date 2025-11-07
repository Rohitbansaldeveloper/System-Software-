/*
 * Banking Management System - Client
 * Connects to server and provides user interface
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF 1024
#define IP "127.0.0.1"

int main() {
    int s;
    struct sockaddr_in addr;
    char buf[BUF], input[BUF];
    int n;
    
    // Create socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0) {
        perror("Socket failed");
        exit(1);
    }
    
    // Setup server address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);
    
    // Connect to server
    printf("Connecting to %s:%d...\n", IP, PORT);
    if(connect(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Connection failed");
        printf("Make sure server is running!\n");
        close(s);
        exit(1);
    }
    
    // Display header
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║     BANKING MANAGEMENT SYSTEM          ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    // Communication loop - receive and send messages
    while(1) {
        memset(buf, 0, BUF);
        n = recv(s, buf, BUF - 1, 0);
        
        // Check if disconnected
        if(n <= 0) {
            printf("\n╔════════════════════════════════════════╗\n");
            printf("║       DISCONNECTED FROM SERVER         ║\n");
            printf("╚════════════════════════════════════════╝\n\n");
            break;
        }
        
        // Display server message
        buf[n] = 0;
        printf("%s", buf);
        fflush(stdout);
        
        // If server is asking for input (prompts end with ': ' or '> ')
        if(strstr(buf, ": ") || strstr(buf, "> ")) {
            if(fgets(input, BUF, stdin)) {
                send(s, input, strlen(input), 0);
            }
        }
    }
    
    close(s);
    return 0;
}