/**
******************************************************************************
* @file    			main.c
* @author  			WIZnet Software Team
* @version 			V1.0
* @date    			2015-02-14
* @brief   			��3.5.0�汾�⽨�Ĺ���ģ��
* @attention  	ʵ��ƽ̨��Ұ�� iSO-MINI STM32 ������ + Ұ��W5500���������
*
*               Ĭ��ʹ��Ұ�𿪷����SPI1�ӿڣ���Ͽ���J10��A4��cs��Ķ̽�ñ
*							
*               �������ԣ��뱣֤W5500��IP�����PC����ͬһ�����ڣ��Ҳ���ͻ
*               ����������߸�PC��ֱ����������PC���������ӵ�ַIPΪ��̬IP

*               ���Ա������뽫w5500_conf.c�ļ��е�local_port����Ϊ����
*               ʹ�õļ����˿�,Ĭ��Ϊ5000
* 
* ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
* ��̳    :http://www.chuxue123.com
* �Ա�    :http://firestm32.taobao.com
******************************************************************************
*/ 
#include <stdio.h>
#include <string.h>
#include "stm32f10x.h"
#include "bsp_usart1.h"

#include "w5500.h"
#include "W5500_conf.h"
#include "socket.h"
#include "utility.h"
/*app����ͷ�ļ�*/
#include "tcp_demo.h"
#include "dns.h"
#include "smtp.h"
//http webserver
#include "httputil.h"
#include "webpge.h"
#include "utility.h"
//ntp
#include "ntp.h"


uint8 reboot_flag = 0;

int main(void)
{ 	  
    systick_init(72);				            /*��ʼ��Systick����ʱ��*/
    USART2_Config(); 				            /*��ʼ������ͨ��:115200@8-n-1*/

    printf(" Ұ����������� TCP Server demo V1.0 \r\n");

    gpio_for_w5500_config();	         	/*��ʼ��MCU�������*/
    reset_w5500();					            /*Ӳ��λW5500*/
    set_w5500_mac();                    /*����MAC��ַ*/
    set_w5500_ip();                     /*����IP��ַ*/

    socket_buf_init(txsize, rxsize);    /*��ʼ��8��Socket�ķ��ͽ��ջ����С*/

    printf(" Ұ�������������ΪTCP �������������������ȴ�PC��ΪTCP Client�������� \r\n");
    printf(" W5500�����˿�Ϊ�� %d \r\n",local_port);
    printf(" ���ӳɹ���TCP Client�������ݸ�W5500��W5500�����ض�Ӧ���� \r\n");

    ntp_client_init();                  /*NTP��ʼ��*/
    while(1)                            /*ѭ��ִ�еĺ���*/ 
    {
//       do_tcp_server();                  /*TCP_Client ���ݻػ����Գ���*/
//       do_tcp_client();
        
//        do_udp();   //udp����
//        do_dhcp();
//        do_dns();   delay_ms(1000); /*�����������Գ���*/      
//        do_https(); if(reboot_flag==1)  reboot();   /*Web server���Գ���*/
        do_ntp_client();    /* NTP���Գ��� */
    }
}
