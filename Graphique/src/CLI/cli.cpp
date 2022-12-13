#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib> 
   
char *cli(int port)
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[] = "mtc";
    char *buffer = (char*) malloc(sizeof(char)* 1024);
    char *buffer1 = (char*) malloc(sizeof(char)* 1024);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
       
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    
    send(sock , hello ,strlen(hello) , 0 );
    valread = read( sock , buffer, 1024);
    printf("Hello message sent\n");
    printf("%s\n",buffer);
    send(sock , hello ,strlen(hello) , 0 );
    valread = read( sock , buffer1, 1024);
    //buffer[valread-1] = '\0' ;
    printf("%s\n",buffer1 );
    return (buffer1);
}