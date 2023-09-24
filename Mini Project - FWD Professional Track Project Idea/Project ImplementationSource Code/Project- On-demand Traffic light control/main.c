/********************************************************************/
/******* Author    : Noor Ashraf Ahmed          *********************/
/******* Date      : 24 Sep 2023                *********************/
/******* Version   : 0.1                        *********************/
/******* SWM       : APP                        *********************/
/******* File Name : main.c                     *********************/
/********************************************************************/
/********************************LIB*********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**********************************MCAL******************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_Interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "SCB_interface.h"


int main(void)
{
/******************************void setup****************************/
MCAL_RCC_InitSysClock();
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_AFIOEN);
MCAL_STK_Init(0);

MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT_FLOATING);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);
MCAL_NVIC_vSetPriority(NVIC_EXTI0_IRQn,0,0);
MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
void EXTI_vInit(void);
EXTI_InitForGPIO( EXTI_LINE0,EXTI_PORTMAP_GPIOB);
EXTI_SetTrigger( EXTI_LINE0 , EXTI_RISING_EDGE);
EXTI_EnableLine(EXTI_LINE0);
MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	__enable_irq();
	
/******************************void loop****************************/
	

while(1)
{	
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(10000);
	MCAL_STK_Reset();
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(5000);
	MCAL_STK_Reset();
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(10000);
	MCAL_STK_Reset();
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	MCAL_STK_SetDelay_ms(5000);
	MCAL_STK_Reset();
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
	MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
		
	


}



}

void EXTI0_IRQHandler(void)
{ 

u8 PIN_CAR_STATUS_green;
u8 PIN_PEDESTRIAN_STATUS_red;

MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&PIN_CAR_STATUS_green);
MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN1,&PIN_PEDESTRIAN_STATUS_red);
	
	
u8 PIN_CAR_STATUS_yellow;
u8 PIN_PEDESTRIAN_STATUS_yellow;

MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN2,&PIN_CAR_STATUS_yellow);
MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN2,&PIN_PEDESTRIAN_STATUS_yellow);

	
if(PIN_CAR_STATUS_green == GPIO_HIGH && PIN_PEDESTRIAN_STATUS_red == GPIO_HIGH)
{
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	int i;
for( i=4000;i>0;i--)
	{
		MCAL_GPIO_TogglePin(GPIO_PORTA,GPIO_PIN2);
	
    MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN2);

  }
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
//MCAL_STK_SetDelay_ms(10000);
//MCAL_STK_Reset();
for( i=1000000; i>0 ; i--);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);	
EXTI_Exit_IRQHandler(EXTI_LINE0);
MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);

	
}
else if(PIN_CAR_STATUS_yellow == GPIO_HIGH && PIN_PEDESTRIAN_STATUS_yellow ==GPIO_HIGH)
{
	int i;
for( i=4000;i>0;i--)
	{
		MCAL_GPIO_TogglePin(GPIO_PORTA,GPIO_PIN2);
	
    MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN2);

  }
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
//MCAL_STK_SetDelay_ms(10000);
//MCAL_STK_Reset();
for( i=1000000; i>0 ; i--);	
MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);	
EXTI_Exit_IRQHandler(EXTI_LINE0);
MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);

}
	else 
 EXTI_Exit_IRQHandler(EXTI_LINE0);

 MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);

}

