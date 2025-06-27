#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr

int clientcount = 0;
int j = 0;
char candidates[500];
char voters[1000];
char voted[1000];
char symbols[500];
char server_message[2000], client_message[2000], client_message2[100];
FILE *f3;

void *handleclients(void *socket_desc_ptr)
{
        int socket_desc;
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        int client_sock = *(int *)socket_desc_ptr;
        recv(client_sock, client_message, sizeof(client_message), 0);
        int check = 0;
        int k = 0;

//check the client send name and CNIC in the voters list
        for (int i = 0; i < strlen(voters); i++)
        {
                while (voters[i] == client_message[k] && k < strlen(client_message))
                {
                        i++;
                        k++;
                        if (k == strlen(client_message) - 1)
                        {
                                check = 1;
                                break;
                        }
                        else if (voters[i + 1] == '@')
                        {
                                i++;
                                break;
                        }
                }
                if (check == 0)
                {
                        k = 0;
                }
                else
                        break;
        }

        k=0;
        int check2=0;

//check if the voter has voted before or not
         for (int i = 0; i < strlen(voted); i++)
        {
                while (voted[i] == client_message[k] && k < strlen(client_message))
                {
                        i++;
                        k++;
                        if (k == strlen(client_message) - 1)
                        {
                                check2 = 1;
                                break;
                        }
                        else if (voted[i + 1] == '@')
                        {
                                i++;
                                break;
                        }
                }
                if (check2 == 0)
                {
                        k = 0;
                }
                else
                        break;
        }

       
        char temp[150];
        int a=0;

        if (check2==1)
        {
                strcpy(temp, "Sorry. You have already casted your vote");
        }
        else if (check == 1)
        {
                printf("\nWelcome %s", client_message);
                printf("\nThe List of Symbols and Candidates is as follows: \n");
                printf("%s",candidates);

                char ans[100];
                
                while (1)
                {
                        strcpy(temp, "To Vote, Enter the desired name: ");
                        send(client_sock, temp, strlen(temp), 0);
                        recv(client_sock, ans, sizeof(ans), 0);

                        if (strcmp(ans, "Bat") == 0)
                        {
                                strcpy(temp, "Congrats. Your vote for Bat has been registered");
                                strcat(voted, client_message);
                                strcat(voted,"@");

                                fseek(f3, 0, SEEK_END); 
                                fprintf(f3, "%s", client_message);
                                fflush(f3);
                                fprintf(f3,"%s"," has voted for Bat\n\n");
                                fflush(f3);
                                break;
                        }
                        else if (strcmp(ans, "Tiger") == 0)
                        {
                                strcpy(temp, "Congrats. Your vote for Tiger has been registered");
                               strcat(voted, client_message);
                                strcat(voted,"@");

                                fseek(f3, 0, SEEK_END); 
                                fprintf(f3, "%s", client_message);
                                fflush(f3);
                                fprintf(f3,"%s"," has voted for Tiger\n\n");
                                fflush(f3);
                                break;
                        }
                        else if (strcmp(ans, "Arrow") == 0)
                        {
                                strcpy(temp, "Congrats. Your vote for Arrow has been registered");
                                strcat(voted, client_message);
                                strcat(voted,"@");

                                fseek(f3, 0, SEEK_END); 
                                fprintf(f3, "%s", client_message);
                                fflush(f3);
                                fprintf(f3,"%s"," has voted for Arrow\n\n");
                                fflush(f3);
                                break;
                        }
                        else if (strcmp(ans, "WeightScale") == 0)
                        {
                                strcpy(temp, "Congrats. Your vote for WeightScale has been registered");
                                strcat(voted, client_message);
                                strcat(voted,"@");

                                fseek(f3, 0, SEEK_END); 
                                fprintf(f3, "%s", client_message);
                                fflush(f3);
                                fprintf(f3,"%s"," has voted for WeightScale\n\n");
                                fflush(f3);
                                break;
                        }
                        else if (strcmp(ans, "Crane") == 0)
                        {
                                strcpy(temp, "Congrats. Your vote for Crane has been registered");
                                strcat(voted, client_message);
                                strcat(voted,"@");

                                fseek(f3, 0, SEEK_END); 
                                fprintf(f3, "%s", client_message);
                                fflush(f3);
                                fprintf(f3,"%s"," has voted for Crane\n\n");
                                fflush(f3);
                                break;
                        }
                }
        }
        else if (check == 0)
        {
                strcpy(temp, "Sorry. Your Data does not exist in the Database");
        }

        // Send the message back to client
        strcpy(server_message, temp);

        if (send(client_sock, server_message, strlen(temp), 0) < 0)
        {
                printf("Send Failed. Error!!!!!\n");
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        clientcount--;
}

int main(void)
{

        int socket_desc, client_sock, client_size;
        struct sockaddr_in server_addr, client_addr;
        FILE *f;
        FILE *f2;

        f3 = fopen("Voted_List.txt", "a");

        char temp[100];
        f = fopen("Voters_List.txt", "r");
        f2 = fopen("Candidates_List.txt", "r");
        int index = 0;
        pthread_t clients[5];

        while (fgets(temp, sizeof(temp), f) != NULL)
        {
                strcat(voters, temp);
                strcat(voters, "@");
        }

        while (fgets(temp, sizeof(temp), f2) != NULL)
        {
                strcat(candidates, temp);
        }

        for (int i = 0; i < strlen(candidates) - 1; i++)
        {
                if (candidates[i] == '/')
                {
                        i++;
                        while (candidates[i] != '\n' && i < strlen(candidates))
                        {
                                symbols[j] = candidates[i];
                                j++;
                                i++;
                        }
                        j++;
                        symbols[j] = '/';
                        j++;
                }
                else
                {
                        continue;
                }
        }

        // Cleaning the Buffers
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