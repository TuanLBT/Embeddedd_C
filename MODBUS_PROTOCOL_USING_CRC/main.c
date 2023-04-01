/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include <stdlib.h> 
#include <stdint.h> //can thiet de su dung kieu du lieu uint_t
#include <stdbool.h>  // can thiet de co the su dung ham kieu du lieu bool
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
unsigned short CRC16_Check_A(unsigned char data[], int Num);
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
volatile char buffer = 0x00;
volatile unsigned char data_buff_0_R[8],crc[2],BUFF_2_T[6],announce[20]={"Valid data!"};
volatile uint8_t count_R = 0,flag=0;
unsigned short crc_16bit;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
bool getbit_low(unsigned char byte, int thutu_bit) //ham dung de lay gia tri bit 1 tu vi tri bat ky trong byte
{
	bool bit = (byte & (1 << (thutu_bit-1))) != 0; // tra ra gia tri la 0 (doi thanh 1 thi ==)
	return bit;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
	if(huart->Instance == huart2.Instance) // check interrupt of serial port 2
	{
		flag = 0;
		if (buffer==0x7E) //~
		{
			count_R=0;
			char data_buff_0_R[8] =""; // clear received buffer
		}
		else
		{
			++count_R;
			data_buff_0_R[count_R-1] = buffer;
			if(count_R ==0x08)
			{
			flag=1;
			for(int k=0;k<sizeof(data_buff_0_R)-2;k++)
				{
					BUFF_2_T[k] =  data_buff_0_R[k];
				}
					
			crc_16bit = CRC16_Check_A((uint8_t*)BUFF_2_T,sizeof(BUFF_2_T));
			crc[0] = (uint8_t)(crc_16bit & 0xFF); // L?y byte th?p c?a giá tr? CRC
			crc[1] = (uint8_t)((crc_16bit >> 8) & 0xFF); // L?y byte cao c?a giá tr? CRC 
			count_R =0;
			}
			if(flag==1 && crc[0] == data_buff_0_R[6] && crc[1] == data_buff_0_R[6])
			{
				HAL_UART_Transmit(&huart2, (uint8_t*) &announce[20], 1, 20);
			}
		}

		HAL_UART_Receive_IT(&huart2, (uint8_t*)&buffer, 1); // dia chi cua buffer duoc ep theo kieu du lieu con tro la uint8_t*
		
	}
}

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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_UART_Receive_IT(&huart2,(uint8_t*)&buffer,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
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
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led1_Pin|led2_Pin|led5_Pin|led6_Pin
                          |led7_Pin|led8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led1_Pin led2_Pin led5_Pin led6_Pin
                           led7_Pin led8_Pin */
  GPIO_InitStruct.Pin = led1_Pin|led2_Pin|led5_Pin|led6_Pin
                          |led7_Pin|led8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//CRC functions
unsigned short CRC16_Check_A(unsigned char data[], int Num) //CRC 16 function
 {
    int x,y,i; unsigned short Crc; //Bien Cuc Bo
    Crc=0xFFFF; //Init
   
    for(x=0;x<Num;x++) //Lap Vong
    {        
       y = data[x]; //Lay Byte Trong Bo Dem CRC 16
       Crc=Crc^y; //Calculate the CRC
       
       for(i=0;i<8;i++) //Shift Right
       {
          if((Crc&0x01)==1) //If the LSB is set
          {
             Crc = (unsigned short)((Crc >> 1)^0xA001); //Shift right and XOR 0xA001
          }
          else //Else LSB is not set  
          {
             Crc = (unsigned short)(Crc >> 1); //Just shift right
          }  
       }
    }    
    //Swapping of the high and low CRC bytes      
    return Crc; //Tra Ve CRC_16 Tinh Duoc
 } 
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
