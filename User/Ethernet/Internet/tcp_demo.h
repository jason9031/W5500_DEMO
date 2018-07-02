#ifndef __TCP_DEMO_H
#define __TCP_DEMO_H

#include <stdio.h>
#include <string.h>
#include "types.h"

#include "W5500_conf.h"
#include "w5500.h"
#include "socket.h"
#include "utility.h"


extern uint16 W5500_tcp_server_port;

void do_tcp_server(void);//TCP Server�ػ���ʾ����
void do_tcp_client(void);//TCP Clinet�ػ���ʾ����
void do_udp(void);

#endif 

