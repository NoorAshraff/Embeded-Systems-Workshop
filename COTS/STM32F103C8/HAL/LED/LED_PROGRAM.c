/*************************************************/
/************ Author    : Noor Ashraf      *******/
/************ Date      : 29 August 2023   *******/
/************ version   : 0.1              *******/
/************ file name : LED_PROGRAM.c    *******/
/*************************************************/
/********************** < LIB*********************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************** < MCAL********************/
#include "STK_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LED_CONFIG.h"
#include "LED_PRIVATE.h"

/***************< function implementation***********/

Std_ReturnType HAL_LED_Init(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId)
{

return MCAL_GPIO_SetPinMode(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId,GPIO_OUTPUT_PUSH_PULL_2MHZ);


}

Std_ReturnType HAL_LED_On(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId)
{

return MCAL_GPIO_SetPinValue(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId, GPIO_HIGH);

}

Std_ReturnType HAL_LED_Off(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId)
{

return MCAL_GPIO_SetPinValue(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId, GPIO_LOW);

}

Std_ReturnType HAL_LED_Tog(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId)
{

u8 Local_PinValue;
if(MCAL_GPIO_GetPinValue(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId,&Local_PinValue)== E_NOT_OK)
return E_NOT_OK;

if(Local_PinValue==GPIO_HIGH)
{
 return MCAL_GPIO_SetPinValue(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId, GPIO_LOW);
  
}
else 
{  
   return  MCAL_GPIO_SetPinValue(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId, GPIO_HIGH);
    
}


}

Std_ReturnType HAL_LED_BlinkOnce(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId,LED_DELAY_ms_TYPE Copy_BlinkTime)
{

if(MCAL_GPIO_SetPinValue( Copy_LEDPortId ,  Copy_LEDPinId, GPIO_HIGH)==E_NOT_OK)
 return E_NOT_OK;

if(MCAL_STK_SetDelay_ms(Copy_BlinkTime)==E_NOT_OK)
 return E_NOT_OK;

if(MCAL_GPIO_SetPinValue( Copy_LEDPortId ,  Copy_LEDPinId, GPIO_LOW)==E_NOT_OK)
 return E_NOT_OK;

return E_OK;



}

Std_ReturnType HAL_LED_BlinkTwice(LED_TYPE Copy_LEDPortId , LED_TYPE Copy_LEDPinId, LED_DELAY_ms_TYPE Copy_BlinkTime)
{
   if( HAL_LED_BlinkOnce( Copy_LEDPortId , Copy_LEDPinId, Copy_BlinkTime)==E_NOT_OK)
      return E_NOT_OK;
   if(MCAL_STK_SetDelay_ms(Copy_BlinkTime)==E_NOT_OK)
      return E_NOT_OK;
  if( HAL_LED_BlinkOnce(  Copy_LEDPortId , Copy_LEDPinId, Copy_BlinkTime)==E_NOT_OK)
      return E_NOT_OK;

return E_OK;
}

































/**********< end of function implementation*********/