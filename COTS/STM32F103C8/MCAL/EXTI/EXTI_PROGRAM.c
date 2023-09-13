/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : EXTI_PROGRAM.h   *******/
/*************************************************/
/********************** < LIB*********************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

/********************** < MCAL********************/

#include "EXTI_INTERFACE.h"
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"

/***************< function implementation***********/

void MCAL_EXTI_Init(void)
{
    for (u8 Line = 0; Line < EXTI_LINES_COUNT; Line++)
    {
        if (EXTI_Configurations[Line].LineEnabled == EXTI_LINE_ENABLED)
        {
            EXTI->IMR |= (1 << Line);  /**< Enable the EXTI line */ 
            switch (EXTI_Configurations[Line].TriggerType)
            {
            /**< Configure rising edge trigger */
            case EXTI_RISING_EDGE:          
                SET_BIT(EXTI->RTSR, Line);
                CLR_BIT(EXTI->FTSR, Line);
                break;
            /**< Configure falling edge trigger */ 
            case EXTI_FALLING_EDGE:
                CLR_BIT(EXTI->RTSR, Line);
                SET_BIT(EXTI->FTSR, Line);
                break;
            /**< Configure both edges trigger */
            case EXTI_BOTH_EDGES:
                SET_BIT(EXTI->RTSR, Line);
                SET_BIT(EXTI->FTSR, Line);
                break;
            }
        }
        else
        {
            EXTI->IMR &= ~(1 << Line);  /**< Disable the EXTI line */ 
        }
    }
}

Std_ReturnType MCAL_EXTI_EnableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < 16)
    {
        SET_BIT(EXTI->IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;

}

Std_ReturnType MCAL_EXTI_DisableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < EXTI_LINES_COUNT)
    {
        CLR_BIT(EXTI->IMR, Copy_Line);
        Local_FunctionStatus = E_OK;
    }
    else
    {
       Local_FunctionStatus = E_NOT_OK; 
    }
    
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Mode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_Line < EXTI_LINES_COUNT)
    {
        switch (Copy_Mode)
        {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->RTSR, Copy_Line);
            CLR_BIT(EXTI->FTSR, Copy_Line);
            Local_FunctionStatus = E_OK;
            break;

        case EXTI_FALLING_EDGE:
            CLR_BIT(EXTI->RTSR, Copy_Line);
            SET_BIT(EXTI->FTSR, Copy_Line);
            Local_FunctionStatus = E_OK;
            break;

        case EXTI_BOTH_EDGES:
            SET_BIT(EXTI->RTSR, Copy_Line);
            SET_BIT(EXTI->FTSR, Copy_Line);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}



/**********< end of function implementation*********/