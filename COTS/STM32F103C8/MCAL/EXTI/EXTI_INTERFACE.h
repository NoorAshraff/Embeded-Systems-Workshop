/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : EXTI_INTERFACE.h    *******/
/*************************************************/

# ifndef EXTI_INTERFACE_H
# define EXTI_INTERFACE_H

#define EXTI_RISING_EDGE  0   
#define EXTI_FALLING_EDGE 1   
#define EXTI_BOTH_EDGES   2   




#define EXTI_LINE0  0   
#define EXTI_LINE1  1   
#define EXTI_LINE2  2   
#define EXTI_LINE3  3   
#define EXTI_LINE4  4   
#define EXTI_LINE5  5   
#define EXTI_LINE6  6   
#define EXTI_LINE7  7  
#define EXTI_LINE8  8   
#define EXTI_LINE9  9   
#define EXTI_LINE10 10  
#define EXTI_LINE11 11  
#define EXTI_LINE12 12  
#define EXTI_LINE13 13  
#define EXTI_LINE14 14  
#define EXTI_LINE15 15  



void EXTI_Init(void);

Std_ReturnType MCAL_EXTI_EnableLine(u8 Copy_Line);

Std_ReturnType MCAL_EXTI_DisableLine(u8 Copy_Line);

Std_ReturnType MCAL_EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Mode);










# endif