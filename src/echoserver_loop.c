/**
 * @file servercho.c
 * @author rafael (you@domain.com)
 * @brief
 * @version saudade
 * @date 2021-10-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "echoserver.h"

/**
 * @brief Create a echo from what is received
 *
 * @param csock
 * @return int
 */
int echo_lines(int csock) {
    int r, i;
    char buf[BUF_TAM];

    memset(&buf, 0, sizeof(buf));
    while ((r = read(csock, buf, BUF_TAM)) > 0) {
        write(csock, buf, r);
        // Caso receba exit fecha a conexao
        if (strstr(buf, "exit")) {
            close(sockfd);
            printf("Conexao Fechada!");
            break;
        }
    }

    conexaoforever(sockfd);
}

/**
 * @brief Accepts the socket and stay listening
 *
 * @param sockfd
 */
void conexaoforever(int sockfd) {
    for (;;) {
        int csock, ok;

        csock = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if (csock == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        ok = echo_lines(csock);  // chama a funçao para imprimir o que for enviado de volta
        if (ok = 1) {
            close(sockfd);
            exit(0);
        }
        printf("saindo do programa '-'\n");
    }
}
