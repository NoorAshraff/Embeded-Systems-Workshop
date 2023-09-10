/*********************************************/
/*******Author : Noor Ashraf        **********/
/*******date : 26 august 2023       **********/
/*******version : 0.1               **********/
/******file name : NVIC_INTERFACE.h **********/
/*********************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef  u8   IRQn_TYPE;

#define NONE            ((INVALID_VALUE)-1) 


/**
 * @name Group 1 Interrupts
 * @note vetor table represents hardware priority of the interrupts
 * @{
 */
#define WWDG_IRQn               0   /**< WWDG Window Watchdog interrupt */
#define PVD_IRQn                1   /**< PVD PVD through EXTI Line detection interrupt */
#define TAMPER_IRQn             2   /**< TAMPER Tamper interrupt */
#define RTC_IRQn                3   /**< RTC RTC global interrupt */
#define FLASH_IRQn              4   /**< FLASH Flash global interrupt */
#define RCC_IRQn                5   /**< RCC RCC global interrupt */
#define EXTI0_IRQn              6   /**< EXTI0 EXTI Line0 interrupt */
#define EXTI1_IRQn              7   /**< EXTI1 EXTI Line1 interrupt */
#define EXTI2_IRQn              8   /**< EXTI2 EXTI Line2 interrupt */
#define EXTI3_IRQn              9   /**< EXTI3 EXTI Line3 interrupt */
#define EXTI4_IRQn              10  /**< EXTI4 EXTI Line4 interrupt */
#define DMA1_Channel1_IRQn      11  /**< DMA1_Channel1 DMA1 Channel1 global interrupt */
#define DMA1_Channel2_IRQn      12  /**< DMA1_Channel2 DMA1 Channel2 global interrupt */
#define DMA1_Channel3_IRQn      13  /**< DMA1_Channel3 DMA1 Channel3 global interrupt */
#define DMA1_Channel4_IRQn      14  /**< DMA1_Channel4 DMA1 Channel4 global interrupt */
#define DMA1_Channel5_IRQn      15  /**< DMA1_Channel5 DMA1 Channel5 global interrupt */
#define DMA1_Channel6_IRQn      16  /**< DMA1_Channel6 DMA1 Channel6 global interrupt */
#define DMA1_Channel7_IRQn      17  /**< DMA1_Channel7 DMA1 Channel7 global interrupt */
#define ADC1_2_IRQn             18  /**< ADC1_2 ADC1 and ADC2 global interrupt */
#define CAN1_TX_IRQn            19  /**< CAN1_TX CAN1 TX interrupts */
#define CAN1_RX0_IRQn           20  /**< CAN1_RX0 CAN1 RX0 interrupts */
#define CAN1_RX1_IRQn           21  /**< CAN1_RX1 CAN1 RX1 interrupt */
#define CAN1_SCE_IRQn           22  /**< CAN1_SCE CAN1 SCE interrupt */
#define EXTI9_5_IRQn            23  /**< EXTI9_5 EXTI Line[9:5] interrupts */
#define TIM1_BRK_IRQn           24  /**< TIM1_BRK TIM1 Break interrupt */
#define TIM1_UP_IRQn            25  /**< TIM1_UP TIM1 Update interrupt */
#define TIM1_TRG_COM_IRQn       26  /**< TIM1_TRG_COM TIM1 Trigger and Commutation interrupts */
#define TIM1_CC_IRQn            27  /**< TIM1_CC TIM1 Capture Compare interrupt */
/** @} */

/**
 * @name Group 2 Interrupts
 * @{
 */
#define TIM2_IRQn               28  /**< TIM2 TIM2 global interrupt */
#define TIM3_IRQn               29  /**< TIM3 TIM3 global interrupt */
#define TIM4_IRQn               30  /**< TIM4 TIM4 global interrupt */
#define I2C1_EV_IRQn            31  /**< I2C1_EV I2C1 event interrupt */
#define I2C1_ER_IRQn            32  /**< I2C1_ER I2C1 error interrupt */
#define I2C2_EV_IRQn            33  /**< I2C2_EV I2C2 event interrupt */
#define I2C2_ER_IRQn            34  /**< I2C2_ER I2C2 error interrupt */
#define SPI1_IRQn               35  /**< SPI1 SPI1 global interrupt */
#define SPI2_IRQn               36  /**< SPI2 SPI2 global interrupt */
#define USART1_IRQn             37  /**< USART1 USART1 global interrupt */
#define USART2_IRQn             38  /**< USART2 USART2 global interrupt */
#define USART3_IRQn             39  /**< USART3 USART3 global interrupt */
#define EXTI15_10_IRQn          40  /**< EXTI15_10 EXTI Line[15:10] interrupts */
#define RTCAlarm_IRQn           41  /**< RTCAlarm RTC alarm through EXTI line interrupt */
#define OTG_FS_WKUP_IRQn        42  /**< OTG_FS_WKUP USB On-The-Go FS Wakeup through EXTI line interrupt */
#define Reserved_IRQn           43  /**< Reserved interrupt */
#define Reserved_IRQn           44  /**< Reserved interrupt */
#define Reserved_IRQn           45  /**< Reserved interrupt */
#define Reserved_IRQn           46  /**< Reserved interrupt */
#define TIM5_IRQn               47  /**< TIM5 TIM5 global interrupt */
#define SPI3_IRQn               48  /**< SPI3 SPI3 global interrupt */
#define UART4_IRQn              49  /**< UART4 UART4 global interrupt */
#define UART5_IRQn              50  /**< UART5 UART5 global interrupt */
#define TIM6_IRQn               51  /**< TIM6 TIM6 global interrupt */
#define TIM7_IRQn               52  /**< TIM7 TIM7 global interrupt */
#define DMA2_Channel1_IRQn      53  /**< DMA2_Channel1 DMA2 Channel1 global interrupt */
#define DMA2_Channel2_IRQn      54  /**< DMA2_Channel2 DMA2 Channel2 global interrupt */
#define DMA2_Channel3_IRQn      55  /**< DMA2_Channel3 DMA2 Channel3 global interrupt */
#define DMA2_Channel4_IRQn      56  /**< DMA2_Channel4 DMA2 Channel4 global interrupt */
#define DMA2_Channel5_IRQn      57  /**< DMA2_Channel5 DMA2 Channel5 global interrupt */
#define ETH_IRQn                58  /**< ETH Ethernet global interrupt */
#define ETH_WKUP_IRQn           59  /**< ETH_WKUP Ethernet Wakeup through EXTI line interrupt */
#define CAN2_TX_IRQn            60  /**< CAN2_TX CAN2 TX interrupts */
#define CAN2_RX0_IRQn           61  /**< CAN2_RX0 CAN2 RX0 interrupts */
#define CAN2_RX1_IRQn           62  /**< CAN2_RX1 CAN2 RX1 interrupt */
#define CAN2_SCE_IRQn           63  /**< CAN2_SCE CAN2 SCE interrupt */
#define OTG_FS_IRQn             64  /**< OTG_FS USB On The Go FS global interrupt */
/** @} */

/**
 * @} (end of NVIC_Interrupts NVIC Interrupt Numbers)
 */



Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn);


Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn);


Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn);


Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn);


Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag);


Std_ReturnType MCAL_NVIC_GetActiveIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnActiveFlag);


Std_ReturnType MCAL_NVIC_SetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);


Std_ReturnType MCAL_NVIC_GetPriority(IRQn_Type Copy_IRQn, u8 *Copy_Priority);












#endif
