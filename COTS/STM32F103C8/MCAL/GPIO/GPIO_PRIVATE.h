/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : GPIO_PRIVATE.h    *******/
/*************************************************/

# ifndef GPIO-PRIVATE_H
# define GPIO_PRIVATE_H

# define GPIO_PORTA_BASEADRESS  0x4001 0800U
# define GPIO_PORTB_BASEADRESS  0x4001 0C00U
# define GPIO_PORTC_BASEADRESS  0x4001 1000U 
# define GPIO_PORTD_BASEADRESS  0x4001 1400U 
# define GPIO_PORTE_BASEADRESS  0x4001 1800U 
# define GPIO_PORTF_BASEADRESS  0x4001 1C00U 
# define GPIO_PORTG_BASEADRESS  0x4001 2000U 


# define  GPIOA_CRL     *((volatile u8 *) GPIO_PORTA_BASEADRESS)
# define  GPIOA_CRH     *((volatile u8 *) (GPIO_PORTA_BASEADRESS+ 0X04))
# define  GPIOA_IDR     *((volatile u8 *) (GPIO_PORTA_BASEADRESS+ 0X08))
# define  GPIOA_ODR     *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X0C))
# define  GPIOA_BSRR    *((volatile u8 *) (GPIO_PORTA_BASEADRESS+ 0X10))
# define  GPIOA_BRR     *((volatile u8 *) (GPIO_PORTA_BASEADRESS+ 0X14))
# define  GPIOA_LCKR    *((volatile u8 *) (GPIO_PORTA_BASEADRESS+ 0X18))



# define  GPIOB_CRL     *((volatile u8 *) GPIO_PORTB_BASEADRESS)
# define  GPIOB_CRH     *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X04))
# define  GPIOB_IDR     *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X08))
# define  GPIOB_ODR     *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X0C))
# define  GPIOB_BSRR    *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X10))
# define  GPIOB_BRR     *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X14))
# define  GPIOB_LCKR    *((volatile u8 *) (GPIO_PORTB_BASEADRESS+ 0X18))



# define  GPIOC_CRL     *((volatile u8 *) GPIO_PORTC_BASEADRESS)
# define  GPIOC_CRH     *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X04))
# define  GPIOC_IDR     *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X08))
# define  GPIOC_ODR     *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X0C))
# define  GPIOC_BSRR    *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X10))
# define  GPIOC_BRR     *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X14))
# define  GPIOC_LCKR    *((volatile u8 *) (GPIO_PORTC_BASEADRESS+ 0X18))


# define  GPIOD_CRL     *((volatile u8 *) GPIO_PORTD_BASEADRESS)
# define  GPIOD_CRH     *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X04))
# define  GPIOD_IDR     *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X08))
# define  GPIOD_ODR     *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X0C))
# define  GPIOD_BSRR    *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X10))
# define  GPIOD_BRR     *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X14))
# define  GPIOD_LCKR    *((volatile u8 *) (GPIO_PORTD_BASEADRESS+ 0X18))


# define  GPIOE_CRL     *((volatile u8 *) GPIO_PORTE_BASEADRESS)
# define  GPIOE_CRH     *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X04))
# define  GPIOE_IDR     *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X08))
# define  GPIOE_ODR     *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X0C))
# define  GPIOE_BSRR    *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X10))
# define  GPIOE_BRR     *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X14))
# define  GPIOE_LCKR    *((volatile u8 *) (GPIO_PORTE_BASEADRESS+ 0X18))


# define  GPIOF_CRL     *((volatile u8 *) GPIO_PORTF_BASEADRESS)
# define  GPIOF_CRH     *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X04))
# define  GPIOF_IDR     *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X08))
# define  GPIOF_ODR     *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X0C))
# define  GPIOF_BSRR    *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X10))
# define  GPIOF_BRR     *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X14))
# define  GPIOF_LCKR     *((volatile u8 *) (GPIO_PORTF_BASEADRESS+ 0X18))


# define  GPIOG_CRL     *((volatile u8 *) GPIO_PORTG_BASEADRESS)
# define  GPIOG_CRH     *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X04))
# define  GPIOG_IDR     *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X08))
# define  GPIODG_ODR    *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X0C))
# define  GPIOG_BSRR    *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X10))
# define  GPIOG_BRR     *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X14))
# define  GPIOG_LCKR    *((volatile u8 *) (GPIO_PORTG_BASEADRESS+ 0X18))







# endif