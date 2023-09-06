
# embeded systems workshop - IEEE ASUSB 
## MC: stm32f103c8
### duration : 5 weeks
## **prerequisites:**
##### * Prior experience with C programming language.
##### * Basic knowledge of number systems and logic design.

# sessions structure:
##### In this workshop, sessions were be conducted offline at the Faculty of Engineering, Ain Shams University. Each session covered essential topics and provided hands-on experience with ARM Cortex-based microcontrollers.
# covered topics so far:
##### 1) Quick Recap about C-language Basics 
##### 2) Discuss Important Advanced Topics in C	
##### 3) ARM Architecture Basics	
##### 4) RCC Peripheral	
##### 5) GPIO Peripheral

# Project Proposal: PWM Drawer with Real-Time Display on Graphical LCD
## Project Overview:
##### The PWM Drawer project aims to develop a real-time PWM signal measurement and visualization tool. The system will capture PWM signals using hardware input capture, calculate the PWM frequency and duty cycle, and display the waveform in real-time on a graphical LCD. This project will provide valuable insights into PWM signals' characteristics and allow users to observe and analyze PWM waveforms quickly and accurately.

## Features:
##### 1) Hardware Input Capture: Utilize the hardware input capture capability of the ATmega32 (AVR) microcontroller to accurately measure the PWM signal pulse width and calculate the frequency.
##### 2) Graphical LCD Interface: Interface with a graphical LCD (e.g., ST7735, SSD1306) using a suitable graphical LCD library (e.g., u8g2) to draw real-time PWM waveforms.
##### 3) Real-Time Display: Continuously update the graphical LCD with the latest PWM measurements, providing real-time visualization of the PWM waveform.
##### 4) Frequency and Duty Cycle Calculation: Implement algorithms to calculate the PWM frequency and duty cycle based on the captured pulse width.
##### 5) User Interface: Develop a user interface to control the PWM measurements and display settings. Use buttons or a touchscreen to start/stop measurements, switch between PWM channels, and adjust display parameters.
##### 6) Data Logging (Optional): Add an optional feature to log captured PWM data to external storage (e.g., SD card) for further analysis or export to a computer.

## Hardware Requirements:
##### 1) ATmega32 (AVR) Development Board.
##### 2) Graphical LCD Module (e.g., ST7735, SSD1306) with appropriate interface (SPI/I2C).
##### 3) Potentiometer (optional) to simulate variable PWM input.
##### 4) User Input Components (e.g., buttons, touchscreen) for the user interface.
##### 5) External Storage (e.g., SD card) if data logging is implemented.

## Software Components:
##### 1) STM32 HAL Library: Use the STM32 HAL library to configure the microcontroller's GPIO, TIM, and other peripherals.
##### 2) Graphical LCD Library: Utilize a graphical LCD library (e.g., u8g2) to draw PWM waveforms and text on the graphical LCD.
##### 3) Input Capture and PWM Measurement: Implement interrupt-driven code to capture PWM signals using hardware input capture and calculate frequency and duty cycle.
##### 4) User Interface: Create a user interface to control PWM measurements and display settings.
##### 5) Data Logging (Optional): If data logging is required, implement code to write captured data to external storage.

## Milestones:
##### 1) Hardware and Software Setup: Configure the ATmega32 (AVR) development board and establish communication with the graphical LCD module.
##### 2) PWM Measurement: Implement hardware input capture to measure PWM signals and calculate frequency and duty cycle.
##### 3) Real-Time Display: Create a real-time display loop to continuously update the graphical LCD with PWM waveforms.
##### 4) User Interface: Develop a user interface to control PWM measurements and display settings.
##### 5) Data Logging (Optional): Implement data logging functionality if required.
##### 6) Testing and Debugging: Test the system thoroughly, identify and fix any bugs, and optimize performance.
##### 7) Documentation and Presentation: Document the project thoroughly, including hardware connections, code explanations, and user instructions. Prepare a presentation to demonstrate the project's functionality.

## Conclusion:
##### The PWM Drawer with Real-Time Display project aims to provide a valuable tool for measuring and visualizing PWM waveforms. By using hardware input capture and graphical LCD interface, the system will offer accurate and real-time representation of PWM signals. The user-friendly interface and optional data logging make it suitable for various applications, including debugging PWM-controlled  systems, testing motor control, and analyzing power circuits.


## About IEEE
### The Institute of Electrical and Electronics Engineers (IEEE) is the world's largest technical professional organization dedicated to  advancing technology for the benefit of humanity. IEEE and its members inspire a global community to innovate for a better tomorrow  through its highly-cited publications, conferences, technology standards, and professional and educational activities.

For more information about IEEE, visit  [IEEE Official Website](https://www.ieee.org/).


