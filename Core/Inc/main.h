/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct Coordinates {
	int x, y;
} Coordinate;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void	Error_Handler(void);

/* USER CODE BEGIN EFP */

int		Random(int n);

// Print a pixel at a give position
void	PrintXY(int x, int y);
int		isUpKey();
int		isDownKey();
int		isLeftKey();
int		isRightKey();
int		isAnyKeyPressed();
void	Colour(int n);
int		isUSERKey();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

// Define the size of the box in which
// the snake lives
#define SNAKE_BOX_SIZE_X 	40
#define SNAKE_BOX_SIZE_Y 	30
#define TETRIS_BOX_SIZE_X 	14
#define TETRIS_BOX_SIZE_Y 	28

#define DIRECTION_UP    	1
#define DIRECTION_DOWN  	2
#define DIRECTION_LEFT  	3
#define DIRECTION_RIGHT 	4

#define SNAKE_PIXEL 		LCD_COLOR_GREEN
#define FOOD_PIXEL 			LCD_COLOR_RED
#define BLANK_PIXEL 		LCD_COLOR_BLACK
#define SNAKE 				1
#define FOOD 				0
#define BLANK 				-1

// How long it takes for the snake to move without
// user's inputs
#define SNAKE_DELAY 		20

#define PIXEL_SPACE 		1
#define PIXEL_SIZE 			5
#define SCREEN_X 			BSP_LCD_GetXSize()
#define SCREEN_Y 			BSP_LCD_GetYSize()

// How long a key is held to be registered as it's being held
#define KEY_HOLD_TIME		500000

// A variable determines which game should be active
// 0 for TETRIS and 1 for Snake
extern int TETRIS_Snake;

// A variable timer to count how long a button needs to
// stay pressed to be determined as being held
extern int isKeyHold;

// Global variables for two games
// randomNum contains a random Number
// seed contains an initial seed for the Random Number Generator (RNG)
extern uint32_t randomNum, seed;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
