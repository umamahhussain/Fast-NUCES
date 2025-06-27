#include <unistd.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr

void *listenclient(void *sock) 
{
    int client_socket = *((int *)sock);
    char client_message[2000];
    memset(client_message, '\0', sizeof(client_message));

    while (1)
    {
        // Receive message from the client
        if (recv(client_socket, client_message, sizeof(client_message), 0) <= 0) {
            break;
        }

        printf("Received from client: %s", client_message);
        send(sock, client_message, strlen(client_message), 0);

        memset(client_message, '\0', sizeof(client_message));
    }

    close(client_socket);
    return NULL;
}
int main(void)
{
        socklen_t socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;         //SERVER ADDR will have all the server address
        char server_message[2000], client_message[2000];                 // Sending values from the server and receive from the server we need this
        pthread_t clientthreads[3];
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));     // Set all bits of the padding field//
        
        //Creating Socket
        
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
        //Binding IP and Port to socket
        server_addr.sin_family = AF_INET;               /* Address family = Internet */
        server_addr.sin_port = htons(2000);               // Set port number, using htons function to use proper byte order */
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");    /* Set IP address to localhost */
		
		
		
		// BINDING FUNCTION
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)    // Bind the address struct to the socket.  /
	                            	//bind() passes file descriptor, the address structure,and the length of the address structure
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        //Put the socket into Listening State
        
        while(1)
        {

        if(listen(socket_desc, 1) < 0)                               
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        int ind=0;
        //Accept the incoming Connections
        
        if(ind<3)
        {

        client_size = sizeof(client_addr);		
        client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);          // heree particular client k liye new socket create kr rhaa ha
        
        if (client_sock < 0)
        {
                printf("Accept Failed. Error!!!!!!\n");
                return -1;
        }
        
        printf("Client Connected with IP: %s and Port No: %i\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		       //inet_ntoa() function converts the Internet host address in, given in network byte order, to a string in IPv4 dotted-decimal notation
        
        //Receive the message from the client
        int *newthread = (int*)(malloc(3));
        *newthread= client_sock;
        int count=3;

            if (pthread_create(&clientthreads[count], NULL, listenclient, (void *)newthread) != 0) {
                perror("Error creating thread for client");
            }
    
        
        printf("Client Message: %s\n",client_message);

        strcpy(server_message, client_message);
        
        if (send(client_sock, server_message, strlen(client_message),0)<0)
        {
                printf("Send Failed. Error!!!!!\n");
                return -1;
        }
        ind++;
    }
        else
        cout<<"\nToo many clients";
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));
              
        //Closing the Socket
        }
        
        close(client_sock);
        close(socket_desc);
        return 0;       
}
