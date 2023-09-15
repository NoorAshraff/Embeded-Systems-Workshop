/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : STK_PROGRAM.c   *******/
/*************************************************/
/********************** < LIB*********************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************** < MCAL********************/

#include "STK_INTERFACE.h"
#include "STK_CONFIG.h"
#include "STK_PRIVATE.h"

/***************< function implementation***********/


void STK_Init(u32 Copy_Ticks)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Configure SysTick timer to use the processor clock */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;              /**< Clear bit 2 to use the processor clock/8 */
    #else 
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif

    /**< Generate interrupt when it reaches zero */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~STK_CTRL_TICKINT_MASK;     /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif

    /**< Load the initial value into the SysTick timer */
    STK->LOAD = Copy_Ticks;  
}

void STK_Start(void)
{
    /**< Enable SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void STK_Stop(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
}

void STK_Reset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Clear the current value */
    STK->VAL = 0;

    /**< Set the reload value to 0 */
    STK->LOAD = 0;

    /**< Clear the count flag */
    STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}


u32 STK_GetRemainingCounts(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

u32 STK_GetElapsedCounts(void)
{
    static u32 Local_PreviousValue = 0;  /**< Store the previous SysTick timer value */ 
    u32 Local_CurrentValue = STK->VAL;   /**< Get the current SysTick timer value */ 
    u32 Local_ElapsedTicks;

    /**< Check if the timer has wrapped around (current value is less than the previous value) */ 
    if (Local_CurrentValue < Local_PreviousValue) 
    {
        /**< Calculate elapsed ticks considering timer overflow */ 
        Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
    } 
    else 
    {
        /**< Calculate elapsed ticks without timer overflow */ 
        Local_ElapsedTicks = STK->LOAD - (Local_CurrentValue - Local_PreviousValue);
    }

    /**< Update the previous value for the next call */ 
    Local_PreviousValue = Local_CurrentValue;

    return Local_ElapsedTicks;
}

Std_ReturnType STK_SetBusyWait(u32 Copy_Microseconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    u32 TicksRequired = (Copy_Microseconds * (STK_AHB_CLK / 1000000));

    if (TicksRequired <= 0x00FFFFFF) 
    {
        STK->LOAD = TicksRequired;

        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        STK->VAL = 0;

        Local_FunctionStatus = E_OK;
    }
    else if(TicksRequired> 0X00FFFFFF)
    {   
     
      while(TicksRequired> 0X00FFFFFF) 
      {
      STK->LOAD =0X00FFFFFF ;

      STK->CTRL |= STK_CTRL_ENABLE_MASK;

        
      while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

      TicksRequired -=0X00FFFFFF;
     
   
      }
      if (TicksRequired ==0)
      Local_FunctionStatus=E_OK;

      else 
       {
        STK->LOAD = TicksRequired;

        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        STK->VAL = 0;
       }
        Local_FunctionStatus = E_OK;


    }


    return Local_FunctionStatus;
}
  
Std_ReturnType STK_SetDelay_ms(f32 Copy_Milliseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of milliseconds */
    u32 Local_u32Ticks = (u32)((Copy_Milliseconds * STK_AHB_CLK) / 1000.0);

    /**< Check if TicksRequired is within the valid range */
    if (Local_u32Ticks <= 0x00FFFFFF)
    {
        /**< Configure SysTick timer with the calculated number of ticks */
        STK->LOAD = Local_u32Ticks;

        /**< Enable SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the SysTick timer reaches zero */
        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable SysTick timer */
        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Return success status */
        return E_OK;
    }
    else
    { 
        /**< Return error status */
        return E_NOT_OK;
    }
}

















/**********< end of function implementation*********/
