/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
unsigned char A[] = {0b10001000,0b10001000,0b10001000,0b10001000,0b11111000,0b10001000,0b10001000,0b01110000};
unsigned char B[] = {0b11111000,0b10001000,0b10001000,0b10001000,0b11110000,0b10001000,0b10001000,0b01111000};
unsigned char C[] = {0b01111000,0b10000000,0b10000000,0b10000000,0b10000000,0b10000000,0b10000000,0b01111000};
unsigned char D[] = {0b11110000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b11110000};
unsigned char E[] = {0b11111000,0b10000000,0b10000000,0b10000000,0b11110000,0b10000000,0b10000000,0b11111000};
unsigned char F[] = {0b10000000,0b10000000,0b10000000,0b10000000,0b11110000,0b10000000,0b10000000,0b11111000};
unsigned char G[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b10110000,0b10000000,0b10000000,0b01111000};
unsigned char H[] = {0b10001000,0b10001000,0b10001000,0b10001000,0b11111000,0b10001000,0b10001000,0b10001000};
unsigned char I[] = {0b11111000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b11111000};
unsigned char J[] = {0b11100000,0b00010000,0b00010000,0b00010000,0b00010000,0b00010000,0b00010000,0b00111000};
unsigned char K[] = {0b10001000,0b10010000,0b10100000,0b11000000,0b11000000,0b10100000,0b10010000,0b10001000};
unsigned char L[] = {0b11111000,0b10000000,0b10000000,0b10000000,0b10000000,0b10000000,0b10000000,0b10000000};
unsigned char M[] = {0b10001000,0b10001000,0b10001000,0b10001000,0b10101000,0b10101000,0b11011000,0b10001000};
unsigned char N[] = {0b10001000,0b10001000,0b10001000,0b10001000,0b10011000,0b10101000,0b11001000,0b10001000};
unsigned char O[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b01110000};
unsigned char P[] = {0b10000000,0b10000000,0b10000000,0b10000000,0b11110000,0b10001000,0b10001000,0b11110000};
unsigned char Q[] = {0b00001000,0b01110000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b01110000};
unsigned char R[] = {0b10001000,0b10010000,0b10100000,0b11000000,0b11110000,0b10010000,0b10010000,0b11110000};
unsigned char S[] = {0b01110000,0b10001000,0b00001000,0b00001000,0b01110000,0b10000000,0b10001000,0b01110000};
unsigned char T[] = {0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b11111000};
unsigned char U[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000};
unsigned char V[] = {0b00100000,0b01010000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000};
unsigned char W[] = {0b01010000,0b10101000,0b10101000,0b10001000,0b10001000,0b10001000,0b10001000,0b10001000};
unsigned char X[] = {0b00000000,0b00000000,0b10001000,0b01010000,0b00100000,0b01010000,0b10001000,0b00000000};
unsigned char Y[] = {0b01110000,0b10001000,0b00001000,0b00001000,0b01111000,0b10001000,0b10001000,0b10001000};
unsigned char Z[] = {0b11111000,0b10000000,0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b11111000};
unsigned char ONE[] = {0b11111000,0b00100000,0b00100000,0b00100000,0b00100000,0b10100000,0b01100000,0b00100000};
unsigned char TWO[] = {0b11111000,0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b10001000,0b01110000};
unsigned char THREE[] = {0b01110000,0b10001000,0b00001000,0b00001000,0b01110000,0b00001000,0b10001000,0b01110000};
unsigned char FOUR[] = {0b00010000,0b00010000,0b00010000,0b11111000,0b10010000,0b01010000,0b00110000,0b00010000};
unsigned char FIVE[] = {0b01110000,0b10001000,0b00001000,0b00001000,0b11110000,0b10000000,0b10000000,0b11111000};
unsigned char SIX[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b11110000,0b10000000,0b10001000,0b01110000};
unsigned char SEVEN[] = {0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00010000,0b00001000,0b11111000};
unsigned char EIGHT[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b01110000,0b10001000,0b10001000,0b01110000};
unsigned char NINE[] = {0b01110000,0b10001000,0b00001000,0b01111000,0b10001000,0b10001000,0b10001000,0b01110000};
unsigned char ZERO[] = {0b01110000,0b10001000,0b10001000,0b10001000,0b11001000,0b10101000,0b10011000,0b01110000};
unsigned char SMILE[] = {0b01110000,0b10001000,0b10001000,0b00100000,0b00100000,0b0000000,0b01010000,0b00000000};
unsigned char EYELEFT[] = {0b00000000,0b00000000,0b00010000,0b00110000,0b00110000,0b00110000,0b00000000,0b00000000};
unsigned char EYELEFTUP[] = {0b00000000,0b00000000,0b00000000,0b00010000,0b00110000,0b00110000,0b00110000,0b00000000};
unsigned char EYERIGHTUP[] = {0b00000000,0b00000000,0b00000000,0b00100000,0b01100000,0b01100000,0b01100000,0b00000000};
unsigned char EYERIGHT[] = {0b00000000,0b00000000,0b00100000,0b01100000,0b01100000,0b01100000,0b00000000,0b00000000};
unsigned char EYERIGHTDOWN[] = {0b00000000,0b00100000,0b01100000,0b01100000,0b01100000,0b00000000,0b00000000,0b00000000};
unsigned char EYELEFTDOWN[] = {0b00000000,0b00010000,0b00110000,0b00110000,0b00110000,0b00000000,0b00000000,0b00000000};
unsigned char TREE[] = {0b00011000,0b00011000,0b00011000,0b00011000,0b11111111,0b01111110,0b00111100,0b00011000};
unsigned char BIGHART[] = {0b00011000,0b00111100,0b011111110,0b11111111,0b11111111,0b11111111,0b01100110,0b00000000};
unsigned char MIDHART[] = {0b00000000,0b00011000,0b01111110,0b01111110,0b01111110,0b00100100,0b00000000,0b00000000};
unsigned char MIDSMALLHART[] = {0b00000000,0b00000000,0b00011000,0b00111100,0b00111100,0b00100100,0b00000000,0b00000000};
unsigned char SMALLHART[] = {0b00000000,0b00000000,0b00000000,0b00011000,0b00011000,0b00000000,0b00000000,0b00000000};
unsigned char *Alphabet[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
unsigned char *Numeric[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
unsigned char AlphabetCharactersLower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void WriteWord(char* Word[],int arrSize);
void tree();
void EYE();
void HARTBIT();
void Write2Word(char* Word[],char* Word2[],int arrSize);
static uint8_t data[4] = {0x0, 0x0, 0x0, 0x0};  // defined a data matrix

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  unsigned char* w[10] = {N,Y,TWO,ZERO};
	  //unsigned char* w2[10] = {EYELEFT,EYELEFTUP,EYERIGHTUP,EYERIGHT,EYERIGHTDOWN,EYELEFTDOWN};
	  HARTBIT();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
void EYE()
{
	unsigned char* w[10] = {O,O,O,O,O,O};
	unsigned char* w2[10] = {EYELEFT,EYELEFTUP,EYERIGHTUP,EYERIGHT,EYERIGHTDOWN,EYELEFTDOWN};
	for(int j=0;j<6;j++)
	  {
	    for(int z=0;z<500;z++)
	    {
	      for (int i = 0; i < 8; i++)
	      {


	          data[0] =~0;
	          data[1] =~w[j][i];        // color blue
	          data[2] =~w2[j][i];

	        data[3] = 0x1<<i;
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	              HAL_SPI_Transmit(&hspi1,&data[0],1,10);
	              HAL_SPI_Transmit(&hspi1,&data[1],1,10);
	              HAL_SPI_Transmit(&hspi1,&data[2],1,10);
	              HAL_SPI_Transmit(&hspi1,&data[3],1,10);
	              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	        //delay(100);
	      }
	    }
	  }
}
void Write2Word(char* Word[],char* Word2[],int arrSize)
{
  for(int j=0;j<arrSize;j++)
  {
    for(int z=0;z<500;z++)
    {
      for (int i = 0; i < 8; i++)
      {


          data[0] =~0;
          data[1] =~Word[j][i];        // color blue
          data[2] =~Word2[j][i];

        data[3] = 0x1<<i;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
              HAL_SPI_Transmit(&hspi1,&data[0],1,10);
              HAL_SPI_Transmit(&hspi1,&data[1],1,10);
              HAL_SPI_Transmit(&hspi1,&data[2],1,10);
              HAL_SPI_Transmit(&hspi1,&data[3],1,10);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
        //delay(100);
      }
    }
  }
}
void HARTBIT()
{
	unsigned char* w[10] = {SMALLHART,MIDSMALLHART,MIDHART,BIGHART};
  for(int j=0;j<4;j++)
  {

	  for(int z=0;z<300;z++)
	     {
      for (int i = 0; i < 8; i++)
      {


          data[0] =~w[j][i];
          data[1] =~0;        // color blue
          data[2] =~0;

        data[3] = 0x1<<i;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
        HAL_SPI_Transmit(&hspi1,&data[0],1,10);
        HAL_SPI_Transmit(&hspi1,&data[1],1,10);
        HAL_SPI_Transmit(&hspi1,&data[2],1,10);
        HAL_SPI_Transmit(&hspi1,&data[3],1,10);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
        //delay(100);
      }
	     }
  }
}
void tree()
{
	unsigned char* w[10] = {TREE};
  for(int j=0;j<1;j++)
  {


      for (int i = 0; i < 8; i++)
      {


          data[0] =~0;
          data[1] =~0;        // color blue
          data[2] =~w[j][i];

        data[3] = 0x1<<i;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
        HAL_SPI_Transmit(&hspi1,&data[0],1,10);
        HAL_SPI_Transmit(&hspi1,&data[1],1,10);
        HAL_SPI_Transmit(&hspi1,&data[2],1,10);
        HAL_SPI_Transmit(&hspi1,&data[3],1,10);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
        //delay(100);
      }

  }
}
void WriteWord(char* Word[],int arrSize)
{
  for(int j=0;j<arrSize;j++)
  {
    for(int z=0;z<500;z++)
    {
      for (int i = 0; i < 8; i++)
      {


          data[0] =~0;
          data[1] =~Word[j][i];        // color blue
          data[2] =~0;

        data[3] = 0x1<<i;
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
        HAL_SPI_Transmit(&hspi1,&data[0],1,10);
        HAL_SPI_Transmit(&hspi1,&data[1],1,10);
        HAL_SPI_Transmit(&hspi1,&data[2],1,10);
        HAL_SPI_Transmit(&hspi1,&data[3],1,10);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
        //delay(100);
      }
    }
  }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
