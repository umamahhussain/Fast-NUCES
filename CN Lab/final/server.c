#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr

int clientcount = 0;

char server_message[2000], client_message[2000],client_message2[2000];

void *handleclients(void *socket_desc_ptr)
{
        int socket_desc;
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        int client_sock = *(int *)socket_desc_ptr;
        recv(client_sock, client_message, sizeof(client_message), 0);
        int j=0;
        int index=0;
        char servermsg[]="Processed by Server";
        FILE* f;
        f=fopen("output.txt","w");
        
        
        for(int i=0;i<strlen(client_message);i++)
        {
        	if(client_message[i]>='A' && client_message[i]<='Z')
        	{
        	client_message2[index]=client_message[i]+32;
        	index++;
        	}
        	else if(client_message[i]>='a' && client_message[i]<='z')
        	{
        	client_message2[index]=client_message[i]-32;
        	index++;
        	}else if(client_message[i]=='\n')
        	{
        	strcat(client_message2,servermsg);
        	}
        	else
        	{
        	client_message2[index]=client_message[i];
        	index++;
        	}
        	
        }
        
        strcpy(server_message, client_message2);
         fprintf(f, "%s", client_message2);
         fflush(f);

        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
                printf("Send Failed. Error!!!!!\n");
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
         memset(client_message2, '\0', sizeof(client_message2));


        clientcount--;
}

int main(void)
{

        int socket_desc, client_sock, client_size;
        struct sockaddr_in server_addr, client_addr;
        pthread_t clients[5];
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        // Creating Socket
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);

        if (socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }

        printf("Socket Created\n");
        // Binding IP and Port to socket
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        // BINDING FUNCTION
        if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }

        printf("Bind Done\n");
        // Put the socket into Listening State
        if (listen(socket_desc, 1) < 0)
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }

        while (1)
        {
                if (clientcount <= 5)
                {
                        printf("\nListening for Incoming Connections.....\n");
                        // Accept the incoming Connections
                        client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);
                        printf("Client Connected with IP: %s and Port No: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                        pthread_create(&clients[clientcount], NULL, &handleclients, &client_sock);
                        clientcount++;
                }
                else
                {
                        printf("\nPlease wait for other users to leave.");
                        sleep(20);
                }
        }

        // Closing the Socket
        close(client_sock);
        close(socket_desc);
        return 0;
}
