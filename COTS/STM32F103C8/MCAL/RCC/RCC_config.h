/*****************************************/
/*******Author : Noor Ashraf    **********/
/*******date : 26 august 2023   **********/
/*******version : 0.1           **********/
/******file name : RCC_CONFIG.h **********/
/*****************************************/


#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
* @brief select system clock source.
* @note choose one of the following options
* .RCC_HSI
* .RCC_HSE
* .RCC_PLL
*/
#define RCC_CLKSYSTEM    RCC_HSE
#if RCC_CLKSYSTEM == RCC_HSE
 /*
 * @brief select type of external clock
 * @note select one of the following options
 * .RCC_RC_CLK
 * .RCC_CRYSTAL_CLK
 */
   #define RCC_BYPASS_CLK    RCC_RC_CLK
#elif RCC_CLKSYSTEM == RCC_PLL
/*
 * @brief select type of PLL clock
 * @note select one of the following options
 * .RCC_PLL_HSE
 * .RCC_PLL_HSI
 */
   # define RCC_PLL_STATE     RCC_PLL_HSE
   # if RCC_PLL_STATE == RCC_PLL_HSE
/*
 * @brief select type of external PLL clock
 * @note select one of the following options
 * .RCC_PLL_RC
 * .RCC_PLL_CRYSTAL
 */
      # define RCC_PLL_BYPASS        RCC_PLL_RC

   #endif

/*
*@brief selct the required multiplication factor
*@note select from 0 to 16 in binary
*/
# define RCC_PLL_MUL  0101

#endif

#endif