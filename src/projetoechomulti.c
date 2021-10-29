/**
 * @file projetoechomulti.c
 * @author rafael (you@domain.com)
 * @brief
 * @version hollow
 * @date 2021-10-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../inc/foo/opcoes.h"

#define PORT 4456

void main() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("$SERVIDOR CRIADO.\n");
    memset(&server, '\0', sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // could be INADDR_ANY

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    printf("$bind na porta %d.\n", PORT);

    listen(sockfd, 5);
    printf("$listen...\n");

    conexaoforever(sockfd);

    printf("Fechando a connection.\n");
}

