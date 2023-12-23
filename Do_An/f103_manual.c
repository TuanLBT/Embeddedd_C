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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h" 
#include "stdlib.h"
#include "stdbool.h"
#include <ctype.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define pi 3.1415
#define p2r pi/250
#define Kp 33.54
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/*motor 1*/
int32_t PosCnt,Cnttmp, do_phan_giai_encoder = 990 ;//990;;
int16_t CountValue=0,HILIM,LOLIM;
uint16_t CntVel;
uint16_t PreviousState,tick=0;
int pwm;
float kp =0.5, ki=0.2, kd, RealVel,DesiredSpeed,alpha,kb = 12;
static bool run=false, runtest=false;
static uint8_t dir = 0;
float CurVel;	
char Rx_indx, Rx_Buffer[20],Rx_data[2];
char *token;

/*motor 2*/
int32_t PosCnt_M2,Cnttmp_M2, do_phan_giai_encoder_M2 = 990 ;//990;;
int16_t CountValue_M2=0;
uint16_t CntVel_M2;
uint16_t PreviousState_M2;
int pwm_M2;
float RealVel_M2,DesiredSpeed_M2;
float CurVel_M2;
uint32_t DesiredPos;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART1_UART_Init(void);
int PI_controller_M2(float Desired, float Current, float kp, float ki, float kb);
int PI_controller_M1(float Desired, float Current, float kp, float ki,float kb);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	//------------------------------Retarget printf--------------------------------//
struct __FILE
{
  int handle;
  /* Whatever you require here. If the only file you are using is */
  /* standard output using printf() for debugging, no file handling */
  /* is required. */
};

FILE __stdout;
int fputc(int ch, FILE *f)
{
	char tempch = ch;
	
	HAL_UART_Transmit(&huart1, (uint8_t *)&	tempch,1,100);
	return ch;
}

	// Ham ngat Uart
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
		uint8_t i;
		if(huart->Instance == USART1) //uart1
		{
				if(Rx_indx==0) {for (i=0;i<20;i++) Rx_Buffer[i] = 0;}
			
		switch(Rx_data[0]) {            
            /* dong co chay */
            case 'r':
                run = true;
                break;
						/* dong co dung */
						case 's':
								run = false;
								break;
						/*direction*/
						case 'd':
								dir = atoi(Rx_Buffer);
								memset(Rx_Buffer, 0, sizeof(Rx_Buffer));
								Rx_indx = 0;
                break;
						/*velocity motor 1*/
            case 'm':
                DesiredSpeed = atoi(Rx_Buffer);
                memset(Rx_Buffer, 0, sizeof(Rx_Buffer));
                Rx_indx = 0;
                break;  
						/*velocity motor 2*/
            case 'n':
                DesiredSpeed_M2 = atoi(Rx_Buffer);
                memset(Rx_Buffer, 0, sizeof(Rx_Buffer));
                Rx_indx = 0;
                break;  
						/*value store in rx_buffer*/
						case '0':
						case '1':
						case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
            case '-':
								if (Rx_data[0] == ' ')
								{Rx_indx++;}
								else{
                Rx_Buffer[Rx_indx++] |= Rx_data[0];}
                break; 
            default:
                break;
        }
				HAL_UART_Receive_IT(&huart1,(uint8_t*)Rx_data,1);
		}
	}



void EXTI9_5_IRQHandler(void)	{// doc encoder	motor1 chanA

  /* USER CODE BEGIN EXTI9_5_IRQn 0 */
unsigned char State0;
	State0 = (State0<<1) | HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	State0 = (State0<<1) | HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
	State0 = State0&0x03; //có tác dụng để nhận duy nhất 2 bit cuối cùng của state0 (00, 01, 10, 11) tương ứng với 0, 1, 2 và 3 
	switch (State0) { //switch này có tác dụng để so sánh trạng thái hiện tại so với trạng thái trước đó, để tăng hoặc giảm xung theo sơ đồ x4 
		case 0:
			if(PreviousState==1) CountValue++;
			else CountValue--;
		break;
		case 1:
			if(PreviousState==3) CountValue++;
			else CountValue--;
		break;
		case 2:
			if(PreviousState==0) CountValue++;
			else CountValue--;
		break;
		case 3:
			if(PreviousState==2) CountValue++;
			else CountValue--;
		break;
		}
	PreviousState = State0;
	CntVel++;
	if (CountValue>=do_phan_giai_encoder*4) {
		CountValue = 0;
		PosCnt++;
	}
	else if	(CountValue<=-do_phan_giai_encoder*4) {
		CountValue = 0;
		PosCnt--;
	}
  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  /* USER CODE BEGIN EXTI4_IRQn 1 */
}


void EXTI4_IRQHandler(void){// doc encoder motor1 chanB

  /* USER CODE BEGIN EXTI4_IRQn 0 */
	// CHANNEL A
unsigned char State1;
	State1 = (State1<<1) | HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	State1 = (State1<<1) | HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
	State1 = State1&0x03;
	switch (State1) {
		case 0:
			if(PreviousState==1) CountValue++;
			else CountValue--;
		break;
		case 1:
			if(PreviousState==3) CountValue++;
			else CountValue--;
		break;
		case 2:
			if(PreviousState==0) CountValue++;
			else CountValue--;
		break;
		case 3:
			if(PreviousState==2) CountValue++;
			else CountValue--;
		break;
		}
	PreviousState = State1;
	CntVel++;
	if (CountValue>=do_phan_giai_encoder*4) {
		CountValue = 0;
		PosCnt++;
	}
	else if	(CountValue<=-do_phan_giai_encoder*4) {
		CountValue = 0;
		PosCnt--;
	}
  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

  /* USER CODE END EXTI3_IRQn 1 */
}


void EXTI0_IRQHandler(void)	{// doc encoder	motor2 chanA

  /* USER CODE BEGIN EXTI0_IRQn 0 */
unsigned char State0;
	State0 = (State0<<1) | HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	State0 = (State0<<1) | HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
	State0 = State0&0x03; //có tác dụng để nhận duy nhất 2 bit cuối cùng của state0 (00, 01, 10, 11) tương ứng với 0, 1, 2 và 3 
	switch (State0) { //switch này có tác dụng để so sánh trạng thái hiện tại so với trạng thái trước đó, để tăng hoặc giảm xung theo sơ đồ x4 
		case 0:
			if(PreviousState_M2==1) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 1:
			if(PreviousState_M2==3) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 2:
			if(PreviousState_M2==0) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 3:
			if(PreviousState_M2==2) CountValue_M2++;
			else CountValue_M2--;
		break;
		}
	PreviousState_M2 = State0;
	CntVel_M2++;
	if (CountValue_M2>=do_phan_giai_encoder_M2*4) {
		CountValue_M2 = 0;
		PosCnt_M2++;
	}
	else if	(CountValue_M2<=-do_phan_giai_encoder_M2*4) {
		CountValue_M2 = 0;
		PosCnt_M2--;
	}
  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */
}


void EXTI1_IRQHandler(void){// doc encoder motor2 chanB

  /* USER CODE BEGIN EXTI1_IRQn 0 */
	// CHANNEL A
unsigned char State1;
	State1 = (State1<<1) | HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	State1 = (State1<<1) | HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
	State1 = State1&0x03;
	switch (State1) {
		case 0:
			if(PreviousState_M2==1) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 1:
			if(PreviousState_M2==3) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 2:
			if(PreviousState_M2==0) CountValue_M2++;
			else CountValue_M2--;
		break;
		case 3:
			if(PreviousState_M2==2) CountValue_M2++;
			else CountValue_M2--;
		break;
		}
	PreviousState_M2 = State1;
	CntVel_M2++;
	if (CountValue_M2>=do_phan_giai_encoder_M2*4) {
		CountValue_M2 = 0;
		PosCnt_M2++;
	}
	else if	(CountValue_M2<=-do_phan_giai_encoder_M2*4) {
		CountValue_M2 = 0;
		PosCnt_M2--;
	}
  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

  /* USER CODE END EXTI3_IRQn 1 */
}









void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {	// ngat timer 2 tinh van toc

	if(htim->Instance == htim2.Instance) //10ms 
	{
		/*động cơ 2*/
		Cnttmp_M2 = CntVel_M2;
		CntVel_M2 = 0;
		RealVel_M2 = (Cnttmp_M2*60) / (0.01*do_phan_giai_encoder_M2*4);	// RPM 
		CurVel_M2 = (Cnttmp_M2*2*pi) / (0.01*do_phan_giai_encoder_M2*4); //rad/s 
		
		/*động cơ 1*/
		Cnttmp = CntVel;
		CntVel = 0;
		RealVel = (Cnttmp*60) / (0.01*do_phan_giai_encoder*4);	// RPM 
		CurVel = (Cnttmp*2*pi) / (0.01*do_phan_giai_encoder*4); //rad/s 
		
		
		
		
		//if (run == true){
		pwm = PI_controller_M1(DesiredSpeed,RealVel, kp, ki, kb);
		pwm_M2 = PI_controller_M2(DesiredSpeed_M2,RealVel_M2, kp, ki, kb);
			/*before change direction, make sure to make the motor stop (Desired speed = 0) beforehand*/
			switch (dir)
      {
      	case 1:
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14, GPIO_PIN_SET); 
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13, GPIO_PIN_RESET); 
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9, GPIO_PIN_SET); 
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8, GPIO_PIN_RESET); 
				
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,pwm);
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,pwm_M2);
      		break;
      	case 2:
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14, GPIO_PIN_RESET); 
					HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13, GPIO_PIN_SET); 
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9, GPIO_PIN_RESET); 
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8, GPIO_PIN_SET);
				
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,pwm);
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,pwm_M2);
      		break;
      	default:
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,0);
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
      		break;
      }
		//}
			
	}
}


int PI_controller_M1(float Desired, float Current, float kp, float ki,float kb){
	static float err_p = 0;
	static float iterm_p = 0;
	static float err_sat = 0;
	static float dterm_f_p = 0;
	float sampletime = 0.01;
	float err, err_windup;
	float pterm, dterm_f, dterm, iterm;
	float pidterm, pid_sat;
	int16_t pidout;
	int HLIM = 100;
	int LOLIM =  0;
	err = Desired - Current;
	pterm = kp*err;
	err_windup = ki*err + kb*err_sat;
	iterm = iterm_p+ err_windup*sampletime;
	iterm_p = iterm;
	err_p = err;
	pidterm += pterm  + iterm ;
	err_sat=pid_sat-pidterm;
	
	if (pidterm > HLIM)
		pid_sat = HLIM;
	else if (pidterm < LOLIM)
		pid_sat = LOLIM;
	else
		pid_sat = pidterm;
	pidout = pid_sat;
return pidout;
	}
int PI_controller_M2(float Desired, float Current, float kp, float ki,float kb){
	static float err_p = 0;
	static float iterm_p = 0;
	static float err_sat = 0;
	static float dterm_f_p = 0;
	float sampletime = 0.01;
	float err, err_windup;
	float pterm, dterm_f, dterm, iterm;
	float pidterm, pid_sat;
	int16_t pidout;
	int HLIM = 100;
	int LOLIM =  0;
	err = Desired - Current;
	pterm = kp*err;
	err_windup = ki*err + kb*err_sat;
	iterm = iterm_p+ err_windup*sampletime;
	iterm_p = iterm;
	err_p = err;
	pidterm += pterm  + iterm ;
	err_sat=pid_sat-pidterm;
	
	if (pidterm > HLIM)
		pid_sat = HLIM;
	else if (pidterm < LOLIM)
		pid_sat = LOLIM;
	else
		pid_sat = pidterm;
	pidout = pid_sat;
return pidout;
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
  MX_TIM2_Init();
  MX_TIM3_Init();
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);	// khoi tao timer 3
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);	// khoi tao timer 3

  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_UART_Receive_IT(&huart1,(uint8_t*)Rx_data,1);	
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 24000;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 11;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
	//dir motor 1
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
	//dir motor 2
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	/*Configure GPIO pins : PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	
	
	
	
	
  /*Configure GPIO pins : PB4 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	
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
