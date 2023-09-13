/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : AFIO_PRIVATE.h   *******/
/*************************************************/

# ifndef AFIO_PRIVATE_H
# define AFIO_PRIVATE_H



#define EXTI_LINES_COUNT        16

#define AFIO_BASEADDRESS             0x4001 0000

typedef struct {

u32 EVCR;
u32 MAPR;
u32 EXTICR[4];
u32 MAPR2;


} AFIO_RegDef_t;

#define AFIO      (AFIO_RegDef_t *)(AFIO_BASEADDRESS)











#endif