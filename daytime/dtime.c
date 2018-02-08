#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT  13
#define QUEUE 10

int main(int argc, char **argv, char **envp) {

    int 		s, c;
    struct sockaddr_in	servaddr, clntaddr;
    socklen_t		clntlen;
    char		buf[1000], clntName[INET_ADDRSTRLEN];
    time_t		ticks;


    s = socket(AF_INET, SOCK_STREAM, 0);
    
    memset(&servaddr, '0', sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    bind(s, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(s, QUEUE);

    fprintf(stdout, "Daytime server started.\n");

    for (;;) {
	c = accept(s, (struct sockaddr *) &clntaddr, &clntlen);
        if (inet_ntop(AF_INET, &clntaddr.sin_addr.s_addr, clntName, sizeof(clntName)) != NULL) {
	    fprintf(stdout, "Connection from: %s%c%d\n", clntName, '/', ntohs(clntaddr.sin_port));
	    fflush(stdout);
	} else {
	    fprintf(stderr, "Connection from unknown source.\n");
	    fflush(stderr);
	}
	ticks = time(NULL);
	snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
	write(c, buf, strlen(buf));
	close(c);
    }
}
