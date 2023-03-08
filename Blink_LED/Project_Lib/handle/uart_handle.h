#ifndef __UART_HANDLE_H
#define __UART_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "handle.h"

handle_err_t Check_Commad(char* Rx_data, uint8_t* Rx_data_begin, uint8_t* Rx_data_end,  uint8_t Rx_data_size);

#ifdef __cplusplus
}
#endif

#endif /* __UART_HANDLE_H */
