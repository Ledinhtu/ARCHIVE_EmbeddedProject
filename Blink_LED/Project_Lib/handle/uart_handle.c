#include "uart_handle.h"

handle_err_t Check_Commad(char* Rx_data, uint8_t* Rx_data_begin, uint8_t* Rx_data_end,  uint8_t Rx_data_size) {

	for (uint8_t i = *Rx_data_begin, cnt = 0; cnt < Rx_data_size; cnt ++, i++) {
		if(Rx_data[i] == '\n') {
			*Rx_data_end = i;
			return HANDLE_OK;
		}
		if (i == Rx_data_size-1) {i = 0;}
	}
	return HANDLE_RX_UART_NOT_FOUND_CMD;
}

handle_err_t Handle_Command(char* Rx_data, uint8_t* Rx_data_begin, uint8_t* Rx_data_end,  uint8_t Rx_data_size) {

}
