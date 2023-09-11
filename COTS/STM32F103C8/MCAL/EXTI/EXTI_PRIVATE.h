/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : EXTI_PRIVATE.h   *******/
/*************************************************/

# ifndef EXTI_PRIVATE_H
# define EXTI_PRIVATE_H



/*
* @note: collecting all the peripheral's registers inside a struct
*/

#define EXTI_BASEADDRESS        0x4001 0400U

typedef struct {

volatile u32 IMR;
volatile u32 EMR;
volatile u32 RTSR;
volatile u32 FTSR;
volatile u32 SWIER;
volatile u32 PR;


}EXTI_RegDef_t;



#define EXTI   ((EXTI_RegDef_t *)EXTI_BASEADDRESS)

#define EXTI_LINES_COUNT        16
#define EXTI_LINE_ENABLED       1
#define EXTI_LINE_DISABLED      0

typedef struct {
u8 LineEnabled  :1;
u8 TriggerType  :2;
u8 :5;

}EXTI_CONFIGURATION;


extern EXTI_CONFIGURATION EXTI_CONFIGURATIONS[EXTI_LINES_COUNT];



#endif