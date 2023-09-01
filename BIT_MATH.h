/*****************************************/
/*******Author : Noor Ashraf   ***********/
/*******date : 26 august 2023  ***********/
/*******version : 0.1          ***********/
/******file name : BIT_MATH.h  ***********/
/*****************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT_NO)  REG|= (1<<BIT_NO)
#define CLR_BIT(REG, BIT_NO)  REG&= ~(1<<BIT_NO)
#define TOG_BIT(REG, BIT_NO)  REG^= (1<<BIT_NO)
#define GET_BIT(REG, BIT_NO)  ((REG& (1<<BIT_NO))>>BIT_NO)





#endif