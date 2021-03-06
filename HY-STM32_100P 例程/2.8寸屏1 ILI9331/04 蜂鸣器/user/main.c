/******************** (C) COPYRIGHT 2010 HY嵌入式开发工作室 ********************

* Description        : 演示的是蜂鸣器发声
*/
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;


void RCC_Configuration(void);
void GPIOYB(unsigned int t);

void Delay(__IO uint32_t nCount);

int main(void)
{
  //uint16_t a;
  /* System Clocks Configuration **********************************************/
  
  RCC_Configuration();   
  
  //
  /* Configure all unused GPIO port pins in Analog Input mode (floating input
     trigger OFF), this will reduce the power consumption and increase the device
     immunity against EMI/EMC *************************************************/
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 |RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
                         RCC_APB2Periph_GPIOE, ENABLE);

 
  

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;				     //D1  D2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);					 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_13;		 //D3, D4
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  while (1)
  {
  
	GPIOYB(100);
    Delay(0xFFFFF);

  }
}

void GPIOYB(unsigned int t)
{
    unsigned int c;
	for(c=0;c<t;c++)
	{
    GPIO_SetBits(GPIOE, GPIO_Pin_0);//                    
    Delay(0x1AFF);

    GPIO_ResetBits(GPIOE, GPIO_Pin_0);	 
    Delay(0x1AFF);
	}
}


void RCC_Configuration(void)
{   
  /* Setup the microcontroller system. Initialize the Embedded Flash Interface,  
     initialize the PLL and update the SystemFrequency variable. */
  SystemInit();
}


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */



void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif



/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
