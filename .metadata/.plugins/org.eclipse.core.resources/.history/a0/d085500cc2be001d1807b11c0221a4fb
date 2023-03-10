/*
 * dc_motor.h
 *
 *  Created on: Mar 8, 2023
 *      Author: DinhTU
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

typedef struct
{
	uint8_t speed; // %
	uint8_t setSpeed;
	TIM_HandleTypeDef* Timer;
	uint32_t TIMChanel;
	uint16_t Pin_IN1;
	GPIO_TypeDef* Port_IN1;
	uint16_t Pin_IN2;
	GPIO_TypeDef* Port_IN2;
} DC_Motor_HandleTypeDef;

void DC_Motor_Init(DC_Motor_HandleTypeDef* MOTOR, TIM_HandleTypeDef* Timer, uint32_t TIMChanel, GPIO_TypeDef* Port_IN1, uint16_t Pin_IN1, GPIO_TypeDef* Port_IN2,uint16_t Pin_IN2);

#ifdef __cplusplus
}
#endif


#endif /* DC_MOTOR_DC_MOTOR_H_ */
