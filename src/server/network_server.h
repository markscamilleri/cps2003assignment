/**
 * @file
 * @author Mark Said Camilleri
 * @version 20170521
 */

#ifndef ASSIGNMENT_NETWORK_SERVER_H
#define ASSIGNMENT_NETWORK_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "listnode.h"
#include "../../deps/zf_log/zf_log.h"
#include "../config.h"

void init_server_and_accept_connections(int *start_sending);

void accept_connection(struct sockaddr *cli_addr, socklen_t *clilen);

void close_all_connections(ListNode * node);

void close_all(void);

void close_server(void);

void send_message_to_client(ListNode *node, char *message);

void send_message_to_list(ListNode * node, char* message);

void broadcast_message(char * message);

ListNode * get_connection_list(void);

pthread_mutex_t *get_connection_mutex();

void receive_message(int newsockfd);

void disconnect(int clientsockfd);
#endif  //ASSIGNMENT_NETWORK_SERVER_H
