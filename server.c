#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

int createServer(int port, struct sockaddr_in * sa){
    int sd = socket(PF_INET, SOCK_STREAM, 0);
    if(sd == -1){
        perror("Erreur de création du serveur");
        exit(0);
    }
    int berr = bind(sd, (struct sockaddr *)sa, sizeof(*sa));
    if(berr == -1){
        perror("Erreur bind");
        exit(0);
    }
    int lerr = listen(sd, SOMAXCONN);
    if(lerr == -1){
        perror("Erreur listen");
        exit(0);
    }
    return sd;
}

int main()
{
    struct sockaddr_in sa ;
    sa.sin_family = AF_INET ;
    sa.sin_port = htons(8080) ;
    sa.sin_addr.s_addr = INADDR_ANY ;

    createServer(8080, &sa);
}


