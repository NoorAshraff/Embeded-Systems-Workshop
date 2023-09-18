/*************************************************/
/************ Author : Noor Ashraf         *******/
/************ Date : 29 August 2023        *******/
/************ version : 0.1                *******/
/************ file name : LED_INTERFACE.h    *******/
/*************************************************/

# ifndef LED_INTERFACE_H
# define LED_INTERFACE_H


/**
 * @brief Initializes the LED peripheral.
 *
 * This function initializes the LED peripheral with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to initialize.
 *
 * @return None.
 */
void HAL_LED_Init(u8 LedId);

/**
 * @brief Turns on the specified LED.
 *
 * This function turns on the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn on.
 *
 * @return None.
 */
void HAL_LED_On(u8 LedId);

/**
 * @brief Turns off the specified LED.
 *
 * This function turns off the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn off.
 *
 * @return None.
 */
void HAL_LED_Off(u8 LedId);

/**
 * @brief Toggles the specified LED.
 *
 * This function toggles the state of the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to toggle.
 *
 * @return None.
 */
void HAL_LED_Tog(u8 LedId);

/**
 * @brief Blinks the specified LED once.
 *
 * This function blinks the LED with the specified identifier once.
 *
 * @param[in] LedId The identifier of the LED to blink once.
 *
 * @return None.
 */
void HAL_LED_BlinkOnce(u8 LedId);

/**
 * @brief Blinks the specified LED twice.
 *
 * This function blinks the LED with the specified identifier twice.
 *
 * @param[in] LedId The identifier of the LED to blink twice.
 *
 * @return None.
 */
void HAL_LED_BlinkTwice(u8 LedId);




#endif