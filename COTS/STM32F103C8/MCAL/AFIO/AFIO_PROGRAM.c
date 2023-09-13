/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : AFIO_PROGRAM.h   *******/
/*************************************************/
/********************** < LIB*********************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************** < MCAL********************/

#include "AFIO_INTERFACE.h"
#include "AFIO_CONFIG.h"
#include "AFIO_PRIVATE.h"

/***************< function implementation***********/


Std_ReturnType MCAL_AFIO_SetEXTIConfiguration( u8 Copy_Line, u8 Copy_PortMap)
{

Std_ReturnType Local_FunctionStatus =E_NOT_OK;
if(Copy_Line> EXTI_LINES_COUNT || Copy_PortMap> 2 )
return Local_FunctionStatus;

AFIO->EXTICR[Copy_Line/4]&=~(0b1111<<((Copy_Line%4)*4));
AFIO->EXTICR[Copy_Line/4]|=(Copy_PortMap<<((Copy_Line%4)*4));
Local_FunctionStatus= E_OK;





return Local_FunctionStatus;

}






























/**********< end of function implementation*********/