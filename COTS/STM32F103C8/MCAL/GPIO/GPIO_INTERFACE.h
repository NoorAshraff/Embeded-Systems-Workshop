/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : GPIO_INTERFACE.h    *******/
/*************************************************/

# ifndef GPIO-INTERFACE_H
# define GPIO_INTERFACE_H
 
# define GPIO_INPUT    0
# define GPIO_OUTPUT   1

Std_ReturnType MCAL_GPIO_SetPinDirection (u8 copy_PortId,u8 copy_PinId, u8 copy_Pindirection);










# endif