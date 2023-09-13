/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : SysTick_PRIVATE.h   *******/
/*************************************************/

# ifndef SysTick_PRIVATE_H
# define SysTick_PRIVATE_H

#define SysTick_BASEADDRESS             0xE000E010


typedef struct {
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;



}SysTick_RegDef_t;



#define  SysTick       ((SysTick_RegDef_t*)SysTick_BASEADDRESS)






#endif