#include "dc_motor.h"

void DC_Motor_Init(DC_Motor_HandleTypeDef* MOTOR, TIM_HandleTypeDef* Timer, uint32_t TIMChanel, GPIO_TypeDef* Port_IN1, uint16_t Pin_IN1, GPIO_TypeDef* Port_IN2,uint16_t Pin_IN2) {
	MOTOR->Timer = Timer;
	MOTOR->TIMChanel = TIMChanel;
	MOTOR->Pin_IN1 = Pin_IN1;
	MOTOR->Port_IN1 = Port_IN1;
	MOTOR->Pin_IN2 = Pin_IN2;
	MOTOR->Port_IN2 = Port_IN2;
}
