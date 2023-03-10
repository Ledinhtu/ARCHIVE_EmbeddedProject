#ifndef __HANDLE_H
#define __HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

typedef uint16_t handle_err_t;
#define HANDLE_OK 0
#define HANDLE_RX_UART_NOT_FOUND_CMD 0x101
#define HANDLE_ERR_UART_DMA 0x102
#define HANDLE_ERR_TOO_FEW_ARG 0x103
#define HANDLE_ERR_TOO_MUCH_ARG 0x104
#define HANDLE_ERR_INVALID_ARG 0x105

#define RX_DATA_SIZE 50
#define TX_ARRAY_SIZE 50


#define NUMBER_LEVELS 4
#define REQUEST_COMMAND_NUMBERS 4
#define SET_MODE "SM"	// `SM <1, 2 or 3>\n`
#define SET_TEMPERATURE_LEVEL "STL"	//`STL <temp levels> <speeds>\n`
#define SET_HUMIDITY_LEVEL "SHL"	//`STL <humi levels> <speeds>\n`
#define SET_MOTOR_SPEED "SS"	//`SS <speed>\n`

#define SET_UART_Q 0x101
#define SET_DHT_Q 0x102
#define SET_HUMI_Q 0x103
#define SET_SPEED_Q 0x104


#define DEBUG

typedef enum
{
	TEMPERATURE_MODE = 1,
	HUMIDITY_MODE,
	MANUAL_MODE,
	MOTOR_STOP_MODE
} MODE;

//typedef struct {
//	uint16_t ID;
//	uint16_t value;
//} queue_Msg;


#ifdef __cplusplus
}
#endif

#endif /* __HANDLE_H */
