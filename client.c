#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sendMessage(int socket, char * query){
    int nb = nb = send(socket, query, strlen(query)+1, 0);
    if(nb == -1){
        perror("Erreur send");
        exit(0);
    }
    return sizeof(query);
}

int connectToServer(char * ip, int port){
    struct sockaddr_in sa;
    sa.sin_family = AF_INET ;
    sa.sin_port = htons(port) ;
    sa.sin_addr.s_addr = (long)inet_addr(ip) ;

    int sd = socket(PF_INET, SOCK_STREAM, 0);
    if(sd == -1){
        printf("Erreur de socket");
        return -1;
    }

    int connexion = connect(sd, (struct sockaddr *)&sa, sizeof(sa));
    if(connexion == -1){
        perror("Erreur de connexion");
        return -1;
    }

    return sd;
}

int main()
{
    int socket = connectToServer("0.0.0.0", 5000);
    sendMessage(socket, "test");
}


