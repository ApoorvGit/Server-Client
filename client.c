// C client code to send string to reverse
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8090

// Driver code
int main()
{
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char str[100];

	printf("\nInput the string:");
	scanf("%[^\n]s", str);

	char buffer[1024] = { 0 };

	// Creating socket file descriptor
	sock = socket(AF_INET,SOCK_STREAM, 0);

	//memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from
	// text to binary form 127.0.0.1 is local
	// host IP address, this address should be
	// your system local host IP address
	//inet_pton(AF_INET, "127.0.0.1",&serv_addr.sin_addr);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	// connect the socket
	connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

	int l = strlen(str);

	// send string to server side
	write(sock, str, sizeof(str));

	// read string sent by server
	//valread = read(sock, str, l);
recv(sock, str, l,0);
        
	printf("%s\n", str);
	printf("%s\n", str);

	return 0;
}
