/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : STK_PRIVATE.h   *******/
/*************************************************/

# ifndef STK_PRIVATE_H
# define STK_PRIVATE_H

#define STK_BASEADDRESS             0xE000E010U


typedef struct {
   volatile     u32 CTRL;
   volatile     u32 LOAD;
   volatile     u32 VAL;
   volatile     u32 CALIB;



}SyTK_RegDef_t;



#define  STK      ((STK_RegDef_t*)STK_BASEADDRESS)



#define STK_CTRL_ENABLE_MASK             0x00000001      /**< Bit 0 : Counter Enable */
#define STK_CTRL_TICKINT_MASK            0x00000002      /**< Bit 1 : Interrupt Enable */
#define STK_CTRL_CLKSOURCE_MASK          0x00000004      /**< Bit 2 : Clock Source */
#define STK_CTRL_COUNTFLAG_MASK          0x00010000      /**< Bit 16: Count Flag */


#define STK_CTRL_CLKSOURCE_1             1
#define STK_CTRL_CLKSOURCE_8             0



#define STK_CTRL_TICKINT_ENABLE          1
#define STK_CTRL_TICKINT_DISABLE         0

#if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
    #define STK_AHB_CLK       1000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif



#endif