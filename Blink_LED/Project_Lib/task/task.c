#include "task.h"
#include <string.h>
#include <stdio.h>
#include "main.h"

extern DHT_HandleTypeDef DHT11;
extern LiquidCrystal_I2C hlcd;
extern DC_Motor_HandleTypeDef MOTOR_1;
extern UART_HandleTypeDef huart2;
extern MODE controll_mode;
extern DHT_HandleTypeDef DHT11;
extern int8_t Temp_levels[NUMBER_LEVELS + 1];
extern uint8_t RHumi_levels[NUMBER_LEVELS + 1];
extern char Rx_data[RX_DATA_SIZE];

extern uint8_t Speed_Temp_mode[NUMBER_LEVELS];
extern uint8_t Speed_RHumi_mode[NUMBER_LEVELS];

static char buff[TX_DATA_SIZE];
static uint32_t time = 0; // test
extern TIM_HandleTypeDef htim2; // test

/** read DHT11 */
void TASK_1(){
	DHT_ReadTempHum(&DHT11);
}

/** handle RX uart */
void TASK_2(){
//	HAL_TIM_Base_Start(&htim2); // test
	uint16_t ret = Check_Request(Rx_data);
	if(!ret) {
		ret = Get_Arg(Rx_data);
	}
	if(!ret) {
		ret = Handle_Request();
	}

//	HAL_TIM_Base_Stop(&htim2);
//		sprintf(buff, "Timre task 2 : %ld us\n", htim2.Instance->CNT); // test
//		HAL_UART_Transmit(&huart2,(uint8_t* )buff, strlen(buff), TX_UART_TIMEOUT ); // test
}

/** TX uart */
void TASK_3(){
//	sprintf(buff, "Speed %d\nDHT_status 0x%#03x\n", MOTOR_1.speed, DHT11.Error);
//	sprintf(buff, "Speed %d\nDHT_status %d\n", MOTOR_1.speed, DHT11.Error);
//	sprintf(buff, "DHT status %d\n", DHT11.Error);
//	sprintf(buff, "Speed %d\nDHT_status 0x%#03x\n", MOTOR_1.speed, DHT11.Error);

	if(DHT11.Error) {
//		sprintf(buff, "Speed %d\nDHT_status %#03x\n\n", MOTOR_1.speed, DHT11.Error);
		sprintf(buff, "DHT_status %#03x\n\n", DHT11.Error);

	} else {
//		sprintf(buff, "Speed %d\nDHT_status %d\nTemp %.2f\nHumi %.2f\n\n", MOTOR_1.speed, DHT11.Error, DHT11.Temp, DHT11.Humi);
		sprintf(buff, "DHT_status %d\nTemp %.2f\nHumi %.2f\n\n", DHT11.Error, DHT11.Temp, DHT11.Humi);
	}
	HAL_UART_Transmit(&huart2,(uint8_t* )buff, strlen(buff), TX_UART_TIMEOUT );

//	sprintf(buff, "Speed %d\n", MOTOR_1.speed);
//	HAL_UART_Transmit(&huart2,(uint8_t* )buff, strlen(buff), TX_UART_TIMEOUT );

}

/** display LCD temperature & relative humidity of DHT11*/
void TASK_4(){

	if(DHT11.Error) {
//		lcd_clear_display(&hlcd);
		lcd_set_cursor(&hlcd, 0, 0);
		lcd_printf(&hlcd, "Temp : __.__ %cC ",(char)223);
		lcd_set_cursor(&hlcd, 1,0);
		lcd_printf(&hlcd, "Humi : __.__ %%");
	} else {
		lcd_set_cursor(&hlcd, 0, 0);
		lcd_printf(&hlcd, "Temp : %.2f %cC ", DHT11.Temp, (char)223);
		lcd_set_cursor(&hlcd, 1,0);
		lcd_printf(&hlcd, "Humi : %.2f %%", DHT11.Humi );

	}



}

/** Control speed motor*/
void TASK_5(){
//	HAL_TIM_Base_Start(&htim2); // test
	switch (controll_mode) {
		case TEMPERATURE_MODE:
			HAL_GPIO_WritePin(MOTOR_1.Port_IN1, MOTOR_1.Pin_IN1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_1.Port_IN2, MOTOR_1.Pin_IN2, GPIO_PIN_SET);
			for (uint8_t i = 0; i < NUMBER_LEVELS; i++) {
//				mul = DHT11.Temp;
				if (DHT11.Temp >= Temp_levels[i] && DHT11.Temp <= Temp_levels[i+1]){
//					__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, 900);
//					__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, Speed_Temp_mode[i]* MOTOR_1.Timer->Instance->ARR/100);

					__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, Speed_Temp_mode[i]* MOTOR_1.Timer->Instance->ARR/100);
//					HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 1);
//					HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 1);
//					HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_GPIO_Port, 1);

					switch (i) {
						case 0:
							HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_Pin, 0);
							break;
						case 1:
							HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 1);
							HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_Pin, 0);
							break;
						case 2:
							HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 1);
							HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_Pin, 0);
							break;
						case 3:
							HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_Pin, 1);
							break;
						default:
							HAL_GPIO_WritePin(Green_Alarm_LED_GPIO_Port, Green_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Yellow_Alarm_LED_GPIO_Port, Yellow_Alarm_LED_Pin, 0);
							HAL_GPIO_WritePin(Red_Alarm_LED_GPIO_Port, Red_Alarm_LED_GPIO_Port, 0);
							break;
					}

					break;
				}

			}
			break;
		case HUMIDITY_MODE:
			HAL_GPIO_WritePin(MOTOR_1.Port_IN1, MOTOR_1.Pin_IN1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_1.Port_IN2, MOTOR_1.Pin_IN2, GPIO_PIN_SET);
			for (uint8_t i = 0; i < NUMBER_LEVELS; ++i) {
				if (DHT11.Humi >= RHumi_levels[i] && DHT11.Humi <= RHumi_levels[i+1]){
					__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, Speed_RHumi_mode[i]* MOTOR_1.Timer->Instance->ARR/100);
					break;
				}
			}
			break;
		case MANUAL_MODE:
//			__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, (int)MOTOR_1.setSpeed*MOTOR_1.Timer->Instance->ARR/100);
//			__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, 900);

			HAL_GPIO_WritePin(MOTOR_1.Port_IN1, MOTOR_1.Pin_IN1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_1.Port_IN2, MOTOR_1.Pin_IN2, GPIO_PIN_SET);

			__HAL_TIM_SetCompare(MOTOR_1.Timer,MOTOR_1.TIMChanel, (int)MOTOR_1.setSpeed*MOTOR_1.Timer->Instance->ARR/100);
			break;
		case MOTOR_STOP_MODE:
			HAL_GPIO_WritePin(MOTOR_1.Port_IN1, MOTOR_1.Pin_IN1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_1.Port_IN2, MOTOR_1.Pin_IN2, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(MOTOR_1.Port_IN1, MOTOR_1.Pin_IN1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_1.Port_IN2, MOTOR_1.Pin_IN2, GPIO_PIN_RESET);
			break;
	}

//	HAL_TIM_Base_Stop(&htim2);
//	sprintf(buff, "Timre task 5 : %ld us\n", htim2.Instance->CNT); // test
//	HAL_UART_Transmit(&huart2,(uint8_t* )buff, strlen(buff), TX_UART_TIMEOUT ); // test

}
