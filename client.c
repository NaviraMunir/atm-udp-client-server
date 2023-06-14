// Client side implementation of UDP client-server model
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
	
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	int check=0;
	char ch='y';
	
	while(1)
	{
		char movies[10][50]={"2012","A Beautiful Mind","Amadeus","Avatar",
		"Clash of the Titans","Les Miserables",
		"Star Wars Episode I - The Phantom Menace",
		"The Expendables I","The Godfather",
		"The Matrix Revolutions"};
		char attribute[3][50]={"polarity","rating","sentiments"};
		printf("\n----------Welcome To Movies Onfo Server----------\n");
		printf("Select Movie Number: ");
		for(int i=0;i<10;i++)
		{
			printf(" %d) %s\n",i+1,movies[i]);
		}
		int n, len;
		char buffer[MAXLINE]="";
		int movieno=0,atrno=0;
		scanf("%d",&movieno);
		printf("Select Attribute Number: \n");
		for(int i=0;i<3;i++)
		{
			printf(" %d) %s\n",i+1,attribute[i]);
		}
		scanf("%d",&atrno);
		char *hello=movies[movieno-1];
		char *atrname=attribute[atrno-1];
		strcat(atrname,".txt");
		strcat(hello,"}");
		strcat(hello,atrname);
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));
		
		
		
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		
		ch='\0';
		printf("\n%s\n",buffer);
		printf("\n\nPress y to continue, Any other key to terminate: ");
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
			continue;
		
			
	}
	close(sockfd);
	return 0;
}
