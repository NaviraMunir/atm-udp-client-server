// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int sockfd;
	
	struct sockaddr_in servaddr, cliaddr;
	//char fname[]="";
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int check=0;
	while(1)
	{
		if(fork())
		{
			int len, n;
			char movie[200];
			char buffer[MAXLINE]="";
			char hello[200] = "";
			len = sizeof(cliaddr); //len is value/resuslt

			n = recvfrom(sockfd, (char *)buffer, MAXLINE,
						0, ( struct sockaddr *) &cliaddr,
						&len);
			int count=0;
			 printf("%d",count); 
			for(int i=0;i<strlen(buffer);i++)
			{
				if(buffer[i]=='}')
				break;
				movie[i]=buffer[i];
			}
			printf("Movie Name: %s\n",movie);
			char arr[50];
			for(int i=0;i<60;i++)
			{
				if(buffer[i]=='}')
				{
					int j=i+1;
					int k=0;
					while(buffer[j]!='\0')
					{
						arr[k]=buffer[j];
						j++;
						k++;
					}
					
				}
			}			
			printf("Attribute: %s\n",arr);
			char b[100000];
            long length;
            char fname[200]="../Q2/";
            
            strcat(fname,movie);
            strcat(fname,"/");
            strcat(fname,arr);
           
            FILE * f = fopen (fname, "r");//from stackover flow
            if (f){
                fseek (f, 0, SEEK_END);
                length = ftell (f);
                fseek (f, 0, SEEK_SET);
                if (b){
                    fread (b, 1, length, f);
                }
             }
               
         
			
			//fgets(hello, 100, stdin);
			sendto(sockfd, (const char *)b, strlen(b),
				0, (const struct sockaddr *) &cliaddr,
					len);
					
               
            }
			
			
		}
	
	return 0;
}
