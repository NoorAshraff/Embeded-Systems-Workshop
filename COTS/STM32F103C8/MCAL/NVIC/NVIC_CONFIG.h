/******************************************/
/*******Author : Noor Ashraf     **********/
/*******date : 26 august 2023    **********/
/*******version : 0.1            **********/
/******file name : NVIC_CONFIG.h **********/
/******************************************/


#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

#define NUMBER_OF_INTERRUPTS      67

#define NVIC_MAX_PRIORITY         15   // byte for each interrupt priority wherethe first 4 bits  are reserved and the second four gives 16 availale choice for priprity




/*
* @brief prority griuping define the mode of SCB_AIRCR 
* @note it defines the identity of the number added to the four bits of NVIC_IPR  
* @note choose one of the following options
* - NVIC_16GROUP_0SUB
* - NVIC_8GROUP_2SUB
* - NVIC_4GROUP_4SUB
* - NVIC_0GROUP_16SUB
*/

#define PRIORITY_GROUPING       NVIC_16GROUP_0SUB

#endif