/**
  ******************************************************************************
  * @file    STM32F3xx_EEPROM_Emulation/src/main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    02-October-2012
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "eeprom.h"

/** @addtogroup EEPROM_Emulation
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Values of Variable1, Variable2 and Variable3 */
uint16_t VarValue1, VarValue2, VarValue3;

/* Virtual address defined by the user: 0xFFFF value is prohibited */
uint16_t VirtAddVarTab[NB_OF_VAR] = {0x5555, 0x6666, 0x7777};
uint16_t VarDataTab[NB_OF_VAR] = {0, 0, 0};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f37x.s/startup_stm32f30x.s) before to branch to 
       application main. To reconfigure the default setting of SystemInit() 
       function, refer to system_stm32f37x.c/system_stm32f30x.c files.
     */ 
     
  uint16_t varvalue = 0;
  
  /* Unlock the Flash Program Erase controller */
  FLASH_Unlock();

  /* EEPROM Init */
  EE_Init();
  
  /* Initialize variables to be used */
  VarValue1 = 0;
  VarValue2 = 0;
  VarValue3 = 0; 
  
  /* Store successively many values of the three variables in the EEPROM */
  /* Store 100 values of Variable1, Variable2 and Variable3 in EEPROM */
  for (varvalue = 0; varvalue < 100; varvalue++)
  {
    VarValue1 += 1;
    VarValue2 += 2;
    VarValue3 += 3;
             
    EE_WriteVariable(VirtAddVarTab[0], VarValue1);
    EE_WriteVariable(VirtAddVarTab[1], VarValue2);
    EE_WriteVariable(VirtAddVarTab[2], VarValue3);
  }
  /* read the last stored variables data*/
  EE_ReadVariable(VirtAddVarTab[0], &VarDataTab[0]);
  EE_ReadVariable(VirtAddVarTab[1], &VarDataTab[1]);
  EE_ReadVariable(VirtAddVarTab[2], &VarDataTab[2]);
  
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
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

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
