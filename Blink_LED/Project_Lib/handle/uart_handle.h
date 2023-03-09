#ifndef __UART_HANDLE_H
#define __UART_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "handle.h"


handle_err_t Check_Request(char* Rx_data);
handle_err_t Get_Arg(char* Rx_data);
handle_err_t Handle_Request();

#ifdef __cplusplus
}
#endif

#endif /* __UART_HANDLE_H */
