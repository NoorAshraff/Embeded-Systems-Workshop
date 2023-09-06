/********************************************/
/*******Author : Noor Ashraf      ***********/
/*******date : 26 august 2023     ***********/
/*******version : 0.1             ***********/
/******file name : RCC_program.c  ***********/
/********************************************/
/********************< LIB*******************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************< MCAL******************/

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"






Std_ReturnType Mcal_Rcc_InitSysClock(void)
{

Std_ReturnType Local_FunctionStatus = E_NOT_OK;

# if RCC_CLKSYSTEM == RCC_HSE
     # if RCC_BYPASS_CLK == RCC_RC_CLK
     SET_BIT(RCC_CR,RCC_CR_HSEBYP);
     # elif RCC_BYPASS_CLK == RCC_CRYSTAL_CLK
     CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
     #else
     # error "invalid choice!!"
     #endif
     SET_BIT(RCC_CR,RCC_CR_HSEON );

     while(!GET_BIT(RCC_CR,RCC_CR_HSERDY));
      RCC_CFGR = 0x00000001;
      Local_FunctionStatus = E_OK;
# elif RCC_CLKSYSTEM ==RCC_HSI
   SET_BIT(RCC_CR,RCC_CR_HSION);

   while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY));
    RCC_CFGR = 0x00000000;
    Local_FunctionStatus = E_OK;
# elif RCC_CLKSYSTEM ==RCC_PLL
    #if RCC_PLL_STATE  ==   RCC_PLL_HSE
       #if RCC_PLL_BYPASS  ==  RCC_PLL_RC
        SET_BIT(RCC_CR,RCC_CR_HSEBYP);
       #elif RCC_PLL_BYPASS  == RCC_PLL_crystal
        CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
       #else 
       #error "wrong choice!!"
       #endif
        SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
        

    #elif RCC_PLL_STATE  == RCC_PLL_HSI
     SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);


    #else 
    # error "wrong choice!!"
     #endif

RCC_CFGR &= ~(ob1111<< RCC_PLLMUL);
RCC_CFGR |=(ob(RCC_PLL_MUL-0010)<<RCC_PLLMUL)


SET_BIT(RCC_CR,RCC_CR_PLLON);
while(!(GET_BIT(RCC_CR,RCC_CR_PLLRDY)));
RCC_CFGR = 0x00000002;
Local_FunctionStatus = E_OK;


#else
  #error "wrong choice!!"

#endif
return Local_FunctionStatus;



}


Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)

{

Std_ReturnType Local_FunctionStatus= E_NOT_OK;
  
switch(Copy_BusId)

case RCC_AHB:
SET_BIT(RCC_AHBENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;


case RCC_APB1:
SET_BIT(RCC_APB1ENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;


case RCC_APB2:
SET_BIT(RCC_APB2ENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;


default:
Local_FunctionStatus= E_NOT_OK;
break;

return Local_FunctionStatus;




}


Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)
{


Std_ReturnType Local_FunctionStatus= E_NOT_OK;
  
switch(Copy_BusId)

case RCC_AHB:
CLR_BIT(RCC_AHBENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;


case RCC_APB1:
CLR_BIT(RCC_APB1ENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;


case RCC_APB2:
CLR_BIT(RCC_APB2ENR,Copy_PeripheralId);
Local_FunctionStatus= E_OK;
break;

default:
Local_FunctionStatus= E_NOT_OK;
break;


return Local_FunctionStatus;


}









