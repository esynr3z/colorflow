/**
  ******************************************************************************
  * @file    colorflow.c
  *
  * @brief   This file contains all the functions for color convertations.
  *
  * @author  esynr3z
  * @date    29.12.2015
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "colorflow.h"

/** @defgroup ColorFlow
  * @brief Lib for creation yours own color palletes and performing color model
  *   convertations with them.
  *
  *   You can create color pallete you like and use it with RGB strip to create
  *   beautifull smooth color flow from one hue to other.
  *
  *   Example of use can be found in "test" folder in repo.
  * @{
  */

/** @defgroup CF_Private_Functions Private functions
  * @{
  */

/**
  * @brief  Convert HSV values to RGB in the current color pallete.
  * @param  HSV  Struct to get input values.
  * @param  RGB  Struct to put calculated values.
  * @param  ColorPallete  Color pallete struct.
  * @retval none
  */

void CF_HSV2RGB(CF_HSV_TypeDef* HSV, CF_RGB_TypeDef* RGB, const CF_ColorPallete_TypeDef* ColorPallete)
{
    uint8_t tempR;
    uint8_t tempG;
    uint8_t tempB;
    int16_t diff;

    uint8_t sector_basecolor;
    uint8_t next_sector_basecolor;
    uint8_t hues_per_sector;  
    uint8_t hue_in_sector;  

    hues_per_sector = 256 / ColorPallete->ColorsTotal;
    hue_in_sector = HSV->H % hues_per_sector; 

    sector_basecolor = HSV->H / hues_per_sector;
    if(sector_basecolor == (ColorPallete->ColorsTotal-1))
        next_sector_basecolor = 0;
    else next_sector_basecolor = sector_basecolor + 1;
    
    /* Get Red from Hue */
    diff = ((int16_t)(ColorPallete->Colors[next_sector_basecolor].R-ColorPallete->Colors[sector_basecolor].R)*hue_in_sector)/hues_per_sector;
    if((ColorPallete->Colors[sector_basecolor].R + diff) < 0)
        tempR = 0;
    else if((ColorPallete->Colors[sector_basecolor].R + diff) > 255)
        tempR = 255;
    else tempR = (uint8_t)(ColorPallete->Colors[sector_basecolor].R + diff);

    /* Get Green from Hue */
    diff = ((int16_t)(ColorPallete->Colors[next_sector_basecolor].G-ColorPallete->Colors[sector_basecolor].G)*hue_in_sector)/hues_per_sector;
    if((ColorPallete->Colors[sector_basecolor].G + diff) < 0)
        tempG = 0;
    if((ColorPallete->Colors[sector_basecolor].G + diff) > 255)
        tempG = 255;
    else tempG = (uint8_t)(ColorPallete->Colors[sector_basecolor].G + diff);

    /* Get Blue from Hue */
    diff = ((int16_t)(ColorPallete->Colors[next_sector_basecolor].B-ColorPallete->Colors[sector_basecolor].B)*hue_in_sector)/hues_per_sector;
    if((ColorPallete->Colors[sector_basecolor].B + diff) < 0)
        tempB = 0;
    if((ColorPallete->Colors[sector_basecolor].B + diff) > 255)
        tempB = 255;
    else tempB = (uint8_t)(ColorPallete->Colors[sector_basecolor].B + diff);

    /* Saturation regulation */
    tempR = (255-((uint16_t)(255-tempR)*(HSV->S))/255);
    tempG = (255-((uint16_t)(255-tempG)*(HSV->S))/255);
    tempB = (255-((uint16_t)(255-tempB)*(HSV->S))/255);

    /* Value (brightness) regulation to get final result */
    RGB->R = ((uint16_t)tempR*(HSV->V))/255;
    RGB->G = ((uint16_t)tempG*(HSV->V))/255;
    RGB->B = ((uint16_t)tempB*(HSV->V))/255;
}

/**
  * @}
  */

/**
  * @}
  */
