#ifndef _W5500_CONF_H_
#define _W5500_CONF_H_

#include "stm32f10x.h"
#include "stdio.h"
#include "types.h"
#define __GNUC__

typedef  void (*pFunction)(void);

extern uint8  	remote_ip[4];															/*Զ��IP��ַ*/
extern uint16 	remote_port;															/*Զ�˶˿ں�*/
extern uint16		local_port;																/*���屾�ض˿�*/
extern uint8  	use_dhcp;																	/*�Ƿ�ʹ��DHCP��ȡIP*/
extern uint8  	use_eeprom;																/*�Ƿ�ʹ��EEPROM�е�IP������Ϣ*/

/* ʹ�����ݲɼ���2017 */
#define STM32F103RC

/* W5500���Ŷ��� */
#define W5500_SPI_NAME                      SPI2
#define W5500_SPI_CLK                       RCC_APB1Periph_SPI2

//W5500ģ��֮NCS,PB12
#define W5500_NCS_GPIO_PORT                 GPIOB
#define W5500_NCS_GPIO_CLK                  RCC_APB2Periph_GPIOB
#define W5500_NCS_GPIO_PIN                  GPIO_Pin_12

//W5500ģ��֮SPI_SCLK,PB13
#define W5500_SPI_SCLK_GPIO_PORT            GPIOB
#define W5500_SPI_SCLK_GPIO_CLK             RCC_APB2Periph_GPIOB
#define W5500_SPI_SCLK_GPIO_PIN             GPIO_Pin_13

//W5500ģ��֮SPI_MISO,PB14
#define W5500_SPI_MISO_GPIO_PORT            GPIOB
#define W5500_SPI_MISO_GPIO_CLK             RCC_APB2Periph_GPIOB
#define W5500_SPI_MISO_GPIO_PIN             GPIO_Pin_14

//W5500ģ��֮SPI_MOSI,PB15
#define W5500_SPI_MOSI_GPIO_PORT            GPIOB
#define W5500_SPI_MOSI_GPIO_CLK             RCC_APB2Periph_GPIOB
#define W5500_SPI_MOSI_GPIO_PIN             GPIO_Pin_15

//W5500ģ��֮RST,PB0
#define W5500_RST_GPIO_PORT                 GPIOB
#define W5500_RST_GPIO_CLK                  RCC_APB2Periph_GPIOB
#define W5500_RST_GPIO_PIN                  GPIO_Pin_0

//W5500ģ��֮INT
//#define W5500_INT_GPIO_PORT					GPIOA
//#define W5500_INT_GPIO_CLK					RCC_APB2Periph_GPIOA
//#define W5500_INT_GPIO_PIN					GPIO_Pin_0

/* ʹ�����ݲɼ��ǵ��Դ��� */
//���ݲɼ��ǵ��Դ�������
#define DEBUG_COM_NAME                          USART2
#define DEBUG_COM_CLK                           RCC_APB1Periph_USART2

//���ݲɼ��ǵ��Դ���Tx,PA2
#define DEBUG_COM_TX_GPIO_PORT                  GPIOA
#define DEBUG_COM_TX_GPIO_CLK                   RCC_APB2Periph_GPIOA
#define DEBUG_COM_TX_GPIO_PIN                   GPIO_Pin_2

//���ݲɼ��ǵ��Դ���Rx,PA3
#define DEBUG_COM_RX_GPIO_PORT                  GPIOA
#define DEBUG_COM_RX_GPIO_CLK                   RCC_APB2Periph_GPIOA
#define DEBUG_COM_RX_GPIO_PIN                   GPIO_Pin_3


#define FW_VER_HIGH                 1               
#define FW_VER_LOW                  0
#define ON	                 		1
#define OFF	                 		0
#define HIGH                        1
#define LOW                         0

#define MAX_BUF_SIZE		 				1460											 /*����ÿ�����ݰ��Ĵ�С*/
#define KEEP_ALIVE_TIME	     		30	// 30sec
#define TX_RX_MAX_BUF_SIZE      2048							 
#define EEPROM_MSG_LEN        	sizeof(EEPROM_MSG)

#define IP_FROM_DEFINE          0                /*ʹ�ó�ʼ�����IP��Ϣ*/
#define IP_FROM_DHCP            1                /*ʹ��DHCP��ȡIP��Ϣ*/
#define IP_FROM_EEPROM          2								 /*ʹ��EEPROM�����IP��Ϣ*/

extern uint8	ip_from;            /*ѡ��IP��Ϣ����Դ*/

#pragma pack(1)
/*�˽ṹ�嶨����W5500�ɹ����õ���Ҫ����*/
typedef struct _CONFIG_MSG											
{
    uint8 mac[6];           /*MAC��ַ*/
    uint8 lip[4];           /*local IP����IP��ַ*/
    uint8 sub[4];           /*��������*/
    uint8 gw[4];            /*����*/	
    uint8 dns[4];           /*DNS��������ַ*/
    uint8 rip[4];           /*remote IPԶ��IP��ַ*/
    uint8 sw_ver[2];        /*����汾��*/

}CONFIG_MSG;
#pragma pack()

#pragma pack(1)
/*�˽ṹ�嶨����eepromд��ļ����������ɰ����޸�*/
typedef struct _EEPROM_MSG	                    
{
	uint8 mac[6];																							/*MAC��ַ*/
  uint8 lip[4];																							/*local IP����IP��ַ*/
  uint8 sub[4];																							/*��������*/
  uint8 gw[4];																							/*����*/
}EEPROM_MSG_STR;
#pragma pack()

extern EEPROM_MSG_STR EEPROM_MSG;
extern CONFIG_MSG  	ConfigMsg;
extern uint8 dhcp_ok;																				/*DHCP��ȡ�ɹ�*/
extern uint32	dhcp_time;																		/*DHCP���м���*/
extern vu8	ntptimer;																				/*NPT�����*/

/*MCU������غ���*/
void gpio_for_w5500_config(void);														/*SPI�ӿ�reset ���ж�����*/
void timer2_init(void);																			/*STM32��ʱ��2��ʼ��*/
void timer2_isr(void);																			/*��ʱ���ж�ִ�еĺ���*/
void reboot(void);																					/*STM32��λ*/

/*W5500SPI��غ���*/
void IINCHIP_WRITE( uint32 addrbsb,  uint8 data);						/*д��һ��8λ���ݵ�W5500*/
uint8 IINCHIP_READ(uint32 addrbsb);													/*��W5500����һ��8λ����*/
uint16 wiz_write_buf(uint32 addrbsb,uint8* buf,uint16 len);	/*��W5500д��len�ֽ�����*/
uint16 wiz_read_buf(uint32 addrbsb, uint8* buf,uint16 len);	/*��W5500����len�ֽ�����*/

/*W5500����������غ���*/
void reset_w5500(void);																			/*Ӳ��λW5500*/
void set_w5500_mac(void);																		/*����W5500��MAC��ַ*/
void set_w5500_ip(void);																		/*����W5500��IP��ַ*/

/*��Ҫ�ö�ʱ�ĵ�Ӧ�ú���*/
void dhcp_timer_init(void);																	/*dhcp�õ��Ķ�ʱ����ʼ��*/
void ntp_timer_init(void);																	/*npt�õ��Ķ�ʱ����ʼ��*/


#endif
