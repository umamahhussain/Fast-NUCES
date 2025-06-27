#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr;
        char server_message[2000], client_message[2000];
        char filecontent[500];

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);

        if (socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }

        printf("Socket Created\n");

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


        if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }

        printf("Connected\n");
        FILE *f;

        char temp[100];
        f = fopen("input.txt", "r");
       

        while (fgets(temp, sizeof(temp), f) != NULL)
        {
                strcat(filecontent, temp);
        }
        
        strcpy(client_message,filecontent);

        // Send the message to Server
        if (send(socket_desc, client_message, strlen(client_message), 0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }

        // Receive the message back from the server
        if (recv(socket_desc, server_message, sizeof(server_message), 0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Server Message: %s\n", server_message);

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        // Closing the Socket
        close(socket_desc);

        return 0;
}
