/********************************************/
/******* Author : Noor Ashraf       *********/
/******* date : 26 august 2023      *********/
/******* version : 0.1              *********/
/****** file name : RCC_private.h   *********/
/********************************************/


#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define BASE_ADDRESS 0x4002 1000


#define RCC_CR            *((volatile u32 *) (BASE_ADDRESS))
#define RCC_CFGR          *((volatile u32 *) (BASE_ADDRESS +OXO4)) 
#define RCC_CIR           *((volatile u32 *) (BASE_ADDRESS +0X08))
#define RCC_APB2RSTR      *((volatile u32 *) (BASE_ADDRESS +0X0C))
#define RCC_APB1RSTR      *((volatile u32 *) (BASE_ADDRESS +0X010))
#define RCC_AHBENR        *((volatile u32 *) (BASE_ADDRESS +0X14))
#define RCC_APB2ENR       *((volatile u32 *) (BASE_ADDRESS +0X18))
#define RCC_APB1ENR       *((volatile u32 *) (BASE_ADDRESS +0X1C))
#define RCC_BDCR          *((volatile u32 *) (BASE_ADDRESS +0X20))
#define RCC_CSR           *((volatile u32 *) (BASE_ADDRESS +0X24))


#define RCC_CR_HSEON        16  
#define RCC_CR_HSEBYP       18 
#define RCC_CR_HSERDY       17
#define RCC_CR_HSION        0
#define RCC_CR_HSIRDY       1
#define RCC_CR_PLLON        24




#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2


#define RCC_RC_CLK 1
#define RCC_CRYSTAL_CLK 0



#endif