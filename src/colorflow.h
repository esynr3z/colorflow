/**
  ******************************************************************************
  * @file    colorflow.h
  *
  * @brief   This file contains all the types and functions prototypes
  *          for color convertations.
  *
  * @author  esynr3z
  * @date    29.12.2015
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COLORFLOW_H
#define __COLORFLOW_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>  
#include "colors_list.h"

/** @addtogroup ColorFlow
  * @{
  */

/** @defgroup CF_Exported_Types Types
  * @{
  */

/**
  * @brief  RGB color model.
  */

typedef struct 
{
    uint8_t R;  /*!< Red. */
    uint8_t G;  /*!< Green. */
    uint8_t B;  /*!< Blue. */
} CF_RGB_TypeDef;

/**
  * @brief  HSV color model.
  */

typedef struct 
{
    uint8_t H;  /*!< Hue. */
    uint8_t S;  /*!< Saturation. */
    uint8_t V;  /*!< Value. */
} CF_HSV_TypeDef;

/**
  * @brief  Color pallete.
  *
  * @attention For smooth color flow the first color should be the same as the last.
  *
  * @attention Strongly recomended to set ColorsTotal with one of this values:
  *   2, 4, 8, 16, 32, 64, 128.
  */

typedef struct
{
    uint8_t ColorsTotal;          /*!< Total number of colors in color pallete. */
    CF_RGB_TypeDef Colors[];      /*!< Array with colors. */
} CF_ColorPallete_TypeDef;

/**
  * @}
  */

/** @defgroup CF_Exported_Functions Functions
  * @{
  */

void CF_HSV2RGB(CF_HSV_TypeDef* HSV, CF_RGB_TypeDef* RGB, const CF_ColorPallete_TypeDef* ColorPallete);

/**
  * @}
  */

#endif /*__COLORFLOW_H*/

/**
  * @}
  */

/************************** END OF FILE ***************************************/
