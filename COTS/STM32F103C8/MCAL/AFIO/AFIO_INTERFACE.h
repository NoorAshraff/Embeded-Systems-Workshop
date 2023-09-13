/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : AFIO_INTERFACE.h    *******/
/*************************************************/

# ifndef AFIO_INTERFACE_H
# define AFIO_INTERFACE_H

#define AFIO_PORTA   0b0000
#define AFIO_PORTB   0b0001
#define AFIO_PORTC   0b0010

Std_ReturnType MCAL_AFIO_SetEXTIConfiguration( u8 Copy_Line, u8 Copy_PortMap);













#endif