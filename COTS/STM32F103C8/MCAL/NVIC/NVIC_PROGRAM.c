/********************************************************************/
/*******Author : Noor Ashraf    *************************************/
/*******date : 26 august 2023   *************************************/
/*******version : 0.1           *************************************/
/******file name : NVIC_PROGRAM *************************************/
/********************************************************************/
/*******************************< lib *******************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*******************************< MCAL*******************************/
#include "NVIC_PRIVATE.h"
#include "NVIC_CONFIG.h"
#include "NVIC_INTERFACE.h"

/********************< function implementation  *********************/



Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn)
{

Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if(Copy_IRQn <32)
{
NVIC_ISER0 = 1<< Copy_IRQn;
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{
NVIC_ISER1 = 1<<( COPY_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{
NVIC_ISER2 = 1<< (COPY_IRQn-64);  //atomic access method to save time and power!!
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


return LOCAL_FUNCTIONSTATUS;


}

Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn)
{

Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if(Copy_IRQn <32)
{
NVIC_ICER0 = 1<< Copy_IRQn;
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{
NVIC_ICER1 = 1<<( COPY_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{
NVIC_ICER2 = 1<< (COPY_IRQn-64);  //atomic access method to save time and power!!
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


return LOCAL_FUNCTIONSTATUS;


}


Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)
{

Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if(Copy_IRQn <32)
{
NVIC_ISPR0 = 1<< Copy_IRQn;
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{
NVIC_ISPR1 = 1<<( COPY_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{
NVIC_ISPR2 = 1<< (COPY_IRQn-64);  //atomic access method to save time and power!!
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


return LOCAL_FUNCTIONSTATUS;



}

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn)
{

Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if(Copy_IRQn <32)
{
NVIC_ICPR0 = 1<< Copy_IRQn;
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{
NVIC_ICPR1 = 1<<( COPY_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{
NVIC_ICPR2 = 1<< (COPY_IRQn-64);  //atomic access method to save time and power!!
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


return LOCAL_FUNCTIONSTATUS;

}

Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag)

{
Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if (Copy_ReturnPendingFlag !=NULL)
{
if(Copy_IRQn <32)
{

*Copy_GetPendingFlag= GET_BIT(NVIC_ISPR0, Copy_IRQn);
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{

*Copy_GetPendingFlag= GET_BIT(NVIC_ISPR1, Copy_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{

*Copy_GetPendingFlag= GET_BIT(NVIC_ISPR2, Copy_IRQn-64);
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


}
return LOCAL_FUNCTIONSTATUS;

}


Std_ReturnType MCAL_NVIC_GetActiveIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnActiveFlag)
{


Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if (Copy_ReturnActiveFlag !=NULL)
{
if(Copy_IRQn <32)
{

*Copy_GetActiveFlag= GET_BIT(NVIC_IABR0, Copy_IRQn);
LOCAL_FUNCTIONSTATUS= E_OK;
}

else if(Copy_IRQn <= 64)
{

*Copy_GetActiveFlag= GET_BIT(NVIC_IABR1, Copy_IRQn-32);
LOCAL_FUNCTIONSTATUS= E_OK;
}


else if(Copy_IRQn <96)
{

*Copy_GetActiveFlag= GET_BIT(NVIC_IABR2, Copy_IRQn-64);
LOCAL_FUNCTIONSTATUS= E_OK;
}

else
LOCAL_FUNCTIONSTATUS= E_NOT_OK;


}
return LOCAL_FUNCTIONSTATUS;



}


Std_ReturnType MCAL_NVIC_SetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority)


{

Std_ReturnType LOCAL_FUNCTIONSTATUS =E_NOT_OK;
u8 MAX_GROUP_PRIORITY;
u8 MAX_SUB_PRIORITY;
#if (PRIORITY_GROUPING == NVIC_16GROUP_0SUB)
     MAX_GROUP_PRIORITY = 15;
     MAX_SUB_PRIORITY = 0;
#elif (PRIORITY_GROUPING == NVIC_8GROUP_2SUB)
     MAX_GROUP_PRIORITY = 7;
     MAX_SUB_PRIORITY = 1;
#elif (PRIORITY_GROUPING == NVIC_4GROUP_4SUB)
     MAX_GROUP_PRIORITY = 3;
     MAX_SUB_PRIORITY = 3;
#elif (PRIORITY_GROUPING == NVIC_2GROUP_8SUB)
     MAX_GROUP_PRIORITY = 1;
     MAX_SUB_PRIORITY = 7;
#elif (PRIORITY_GROUPING == NVIC_0GROUP_16SUB)
     MAX_GROUP_PRIORITY = 0;
     MAX_SUB_PRIORITY = 15;
#else 
  #error "please chech your configuration considering priority grouping"
#endif
if(Copy_GroupPriority > MAX_GROUP_PRIORITY || Copy_SubPriority > MAX_SUB_PRIORITY || Copy_IRQn >NUMBER_OF_INTERRUPTS)
 return LOCAL_FUNCTIONSTATUS;

u8 LOCAL_PRIORITY =Copy_SubPriority | ((Copy_GroupPriority)<< ((PRIORITY_GROUPING-0x05FA0300U)/0X100));

NVIC_IPR_BASE_ADDRESS[Copy_IRQn]=LOCAL_PRIORITY<<4;
LOCAL_FUNCTIONSTATUS= E_OK;
SCB_AIRCR = PRIORITY_GROUPING;


return LOCAL_FUNCTIONSTATUS;

}

Std_ReturnType MCAL_NVIC_GetPriority(IRQn_Type Copy_IRQn, u8 *Copy_Priority)
{
Std_ReturnType LOCAL_FUNCTIONSTATUS= E_NOT_OK;
if( Copy_Priority !=NULL)


{
*Copy_Priority=(NVIC_IPR_BASE_ADDRESS[Copy_IRQn] & (ob1111 << 4)) >>4;

Std_ReturnType LOCAL_FUNCTIONSTATUS= E_OK;
}


return LOCAL_FUNCTIONSTATUS;


}





/*************************< end of function implementation ********************/







