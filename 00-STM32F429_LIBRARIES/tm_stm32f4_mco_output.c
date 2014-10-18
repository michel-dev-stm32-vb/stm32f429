/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#include "tm_stm32f4_mco_output.h"

void TM_MCOOUTPUT_InitMCO1(void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Enable clock for GPIOA */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	/* PA8 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;  

	/* Initialize GPIOA */
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void TM_MCOOUTPUT_InitMCO2(void) {
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Enable clock for GPIOC */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	/* PC9 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;  

	/* Initialize GPIOC */
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void TM_MCOOUTPUT_SetOutput1(TM_MCOOUTPUT1_Source_t Source, TM_MCOOUTPUT_Prescaler_t Prescaler) {
	uint32_t presc = 0, src = 0;
	/* Get prescaler */
	switch (Prescaler) {
		case TM_MCOOUTPUT_Prescaler_1:
			presc = RCC_MCO1Div_1;
			break;
		case TM_MCOOUTPUT_Prescaler_2:
			presc = RCC_MCO1Div_2;
			break;
		case TM_MCOOUTPUT_Prescaler_3:
			presc = RCC_MCO1Div_3;
			break;
		case TM_MCOOUTPUT_Prescaler_4:
			presc = RCC_MCO1Div_4;
			break;
		case TM_MCOOUTPUT_Prescaler_5:
			presc = RCC_MCO1Div_5;
			break;
		default:
			break;
	}
	/* Get source */
	switch (Source) {
		case TM_MCOOUTPUT1_Source_HSE:
			src = RCC_MCO1Source_HSE;
			break;
		case TM_MCOOUTPUT1_Source_HSI:
			src = RCC_MCO1Source_HSI;
			break;
		case TM_MCOOUTPUT1_Source_PLLCLK:
			src = RCC_MCO1Source_PLLCLK;
			break;
		case TM_MCOOUTPUT1_Source_LSE:		
			src = RCC_MCO1Source_LSE;
			break;
		default:
			break;
	}
	/* Set */
	RCC_MCO1Config(src, presc);
}

void TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_t Source, TM_MCOOUTPUT_Prescaler_t Prescaler) {
	uint32_t presc, src;
	/* Get prescaler */
	switch (Prescaler) {
		case TM_MCOOUTPUT_Prescaler_1:
			presc = RCC_MCO2Div_1;
			break;
		case TM_MCOOUTPUT_Prescaler_2:
			presc = RCC_MCO2Div_2;
			break;
		case TM_MCOOUTPUT_Prescaler_3:
			presc = RCC_MCO2Div_3;
			break;
		case TM_MCOOUTPUT_Prescaler_4:
			presc = RCC_MCO2Div_4;
			break;
		case TM_MCOOUTPUT_Prescaler_5:
			presc = RCC_MCO2Div_5;
			break;
		default:
			break;
	}
	/* Get clock source */
	switch (Source) {
		case TM_MCOOUTPUT2_Source_SYSCLK:
			src = RCC_MCO2Source_SYSCLK;
			break;
		case TM_MCOOUTPUT2_Source_PLLI2SCLK:
			src = RCC_MCO2Source_PLLI2SCLK;
			break;
		case TM_MCOOUTPUT2_Source_HSE:
			src = RCC_MCO2Source_HSE;
			break;
		case TM_MCOOUTPUT2_Source_PLLCLK:
			src = RCC_MCO2Source_PLLCLK;
			break;
		default:
			break;
	}
	/* Set */
	RCC_MCO2Config(src, presc);
}
