/**
 * @file echoserver.h
 * @author @domain.com)
 * @brief
 * @version 0.1
 * @date 2021-10-15
 *
 * @copyright Copyright (c) 2021
 *
 **/
#ifndef ECHOSERVER_LOOP_H
#define ECHOSERVER_LOOP_H

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_TAM 256

int sockfd;
struct sockaddr_in server;

int newSocket;
struct sockaddr_in newAddr;

socklen_t addr_size;

void conexaoforever(int sockfd);

#endif  // ECHOSERVER_LOOP_H
