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
Std_ReturnType HAL_LED_Init(LED_TYPE Copy_LEDPortId , LED LED_TYPE Copy_LEDPinId);

/**
 * @brief Turns on the specified LED.
 *
 * This function turns on the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn on.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_On(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId);

/**
 * @brief Turns off the specified LED.
 *
 * This function turns off the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to turn off.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_Off(LED_TYPE Copy_LEDPortId , LED_TYPE Copy_LEDPinId);

/**
 * @brief Toggles the specified LED.
 *
 * This function toggles the state of the LED with the specified identifier.
 *
 * @param[in] LedId The identifier of the LED to toggle.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_Tog(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId);

/**
 * @brief Blinks the specified LED once.
 *
 * This function blinks the LED with the specified identifier once.
 *
 * @param[in] LedId The identifier of the LED to blink once.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_BlinkOnce(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId,LED_DELAY_ms_TYPE Copy_BlinkTime);

/**
 * @brief Blinks the specified LED twice.
 *
 * This function blinks the LED with the specified identifier twice.
 *
 * @param[in] LedId The identifier of the LED to blink twice.
 *
 * @return None.
 */
Std_ReturnType HAL_LED_BlinkTwice(LED_TYPE Copy_LEDPortId ,  LED_TYPE Copy_LEDPinId, LED_DELAY_ms_TYPE Copy_BlinkTime);




#endif