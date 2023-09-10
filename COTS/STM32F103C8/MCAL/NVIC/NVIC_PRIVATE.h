/*******************************************/
/*******Author : Noor Ashraf      **********/
/*******date : 26 august 2023     **********/
/*******version : 0.1             **********/
/******file name : NVIC_PRIVATE.h **********/
/*******************************************/


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASEADRESS                0xE000E100

#define NVIC_ISER0                     *((volatile u32 *)(NVIC_BASEADRESS))
#define NVIC_ISER01                    *((volatile u32 *)((NVIC_BASEADRESS)+0x004))
#define NVIC_ISER02                    *((volatile u32 *)((NVIC_BASEADRESS)+0x008))


#define NVIC_ICER0                     *((volatile u32 *)((NVIC_BASEADRESS)+0x080))
#define NVIC_ICER01                    *((volatile u32 *)((NVIC_BASEADRESS)+0x084))
#define NVIC_ICER02                    *((volatile u32 *)((NVIC_BASEADRESS)+0x088))


#define NVIC_ISPR0                    *((volatile u32 *)((NVIC_BASEADRESS)+0x100))
#define NVIC_ISPR1                    *((volatile u32 *)((NVIC_BASEADRESS)+0x104))
#define NVIC_ISPR2                    *((volatile u32 *)((NVIC_BASEADRESS)+0x108))


#define NVIC_ICPR0                   *((volatile u32 *)((NVIC_BASEADRESS)+0x180))
#define NVIC_ICPR1                   *((volatile u32 *)((NVIC_BASEADRESS)+0x184))
#define NVIC_ICPR2                   *((volatile u32 *)((NVIC_BASEADRESS)+0x188))


#define NVIC_IABR0                   *((volatile u32 *)((NVIC_BASEADRESS)+0x200))
#define NVIC_IABR1                   *((volatile u32 *)((NVIC_BASEADRESS)+0x204))
#define NVIC_IABR2                   *((volatile u32 *)((NVIC_BASEADRESS)+0x208))


#define NVIC_IPR_BASE_ADDRESS          (volatile u8 *)0xE000E400 

#define NVIC_16GROUP_0SUB            0x05FA0300U
#define NVIC_8GROUP_2SUB             0x05FA0400U
#define NVIC_4GROUP_4SUB             0x05FA0500U
#define NVIC_2GROUP_8SUB             0x05FA0600U
#define NVIC_0GROUP_16SUB            0x05FA0700U


#define SCB_AIRCR                    0xE000ED0C








#endif
