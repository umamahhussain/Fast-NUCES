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
        char server_message[2000], client_message[2000], cnic[50];

        // Cleaning the Buffers
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
        memset(cnic, '\0', sizeof(cnic));

        // Creating Socket

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);

        if (socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }

        printf("Socket Created\n");

        // Specifying the IP and Port of the server to connect

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        // Now connecting to the server accept() using connect() from client side

        if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }

        printf("Connected\n");
        int step = 0;
        char arr[] = "0123456789";

        // Get Input from the User
        while (1)
        {
                if (step == 0)
                {
                        printf("Enter Name: ");
                        fflush(stdin);
                        fgets(client_message, sizeof(client_message), stdin);
                        step = 1;
                }

                if (step == 1)
                {
                        int check = 0;
                        for (int i = 0; i < strlen(client_message) - 1; i++)
                        {
                                if (client_message[i] >= 'A' && client_message[i] <= 'Z' ||
                                    client_message[i] >= 'a' && client_message[i] <= 'z' || client_message[i] == ' ')
                                {
                                        continue;
                                }
                                else
                                {
                                        check = 1;
                                }
                        }

                        if (check == 1)
                        {
                                step = 0;
                                printf("\nEnter Correct Name\n");
                                memset(client_message, '\0', sizeof(client_message));
                        }
                        else
                                step = 2;
                }

                if (step == 2)
                {
                        printf("Enter CNIC: ");
                        fflush(stdin);
                        fgets(cnic, sizeof(cnic), stdin);
                        step = 3;
                }

                if (step == 3)
                {
                        int check = 0;

                        if (cnic[5] != '-' && cnic[13] != '-' || strlen(cnic) - 1 != 15)
                        {
                                check = 1;
                        }
                        else
                        {
                                for (int i = 0; i < strlen(cnic) - 1; i++)
                                {
                                        if (i == 5 || i == 13)
                                                continue;

                                        if (cnic[i] >= '0' && cnic[i] <= '9')
                                                continue;
                                        else
                                        {
                                                check = 1;
                                        }
                                }
                        }

                        if (check == 1)
                        {
                                printf("\nPlease enter the CNIC in the correct format\n");
                                step = 2;
                        }
                        else
                                step = 4;
                }

                if (step == 4)
                {
                        char a[] = "/";
                        size_t len = strlen(client_message);
                        if (len > 0 && client_message[len - 1] == '\n')
                        {
                                client_message[len - 1] = '\0';
                        }

                        strcat(client_message, a);
                        strcat(client_message, cnic);
                        break;
                }
        }

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

        if(strcmp(server_message,"Sorry. Your Data does not exist in the Database")!=0
        && strcmp(server_message,"Sorry. You have already casted your vote")!=0)
        {
        char ans[100];
        scanf("%s",ans);

        if (send(socket_desc, ans, strlen(ans), 0) < 0)
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
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        // Closing the Socket
        close(socket_desc);

        return 0;
}