/*
 * task.h
 *
 *  Created on: Mar 8, 2023
 *      Author: DinhTU
 */

#ifndef __HANDLE_TASK_H
#define __HANDLE_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "dht.h"
#include "delay_timer.h"
#include "LiquidCrystal_I2C.h"
#include "uart_handle.h"
#include "dc_motor.h"
#include "handle.h"

#define TX_UART_TIMEOUT 50
#define TX_DATA_SIZE 50

/** read DHT11 */
void TASK_1();
/** handle RX uart */
void TASK_2();
/** TX uart */
void TASK_3();
/** display LCD temperature & relative humidity of DHT11*/
void TASK_4();
/** Control speed motor*/
void TASK_5();


#ifdef __cplusplus
}
#endif

#endif /* __HANDLE_TASK_H */
