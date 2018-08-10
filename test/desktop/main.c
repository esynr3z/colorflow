/**
  ******************************************************************************
  * @file    main.c
  *
  * @brief   Simple test for ColorFlow lib.
  *
  * @author  esynr3z
  * @date    29.12.2015
  *
  ******************************************************************************
  */

#include <stdio.h>
#include "colorflow.h"

/* "Rainbow" color pallete */
const CF_ColorPallete_TypeDef CF_ColorPallete_Rainbow = {8, CF_COLORPALLETE_RAINBOW};

/* "Sunny" color pallete */
const CF_ColorPallete_TypeDef CF_ColorPallete_Sunny = {4, CF_COLORPALLETE_SUNNY};

int main(void)
{
    CF_HSV_TypeDef HSV;
    CF_RGB_TypeDef RGB;

    HSV.H = 32;
    HSV.S = 255;
    HSV.V = 255;

    /* Hues total = 256.
     * Colors in "Rainbow" total = 8.
     * Hues per color = 256/8 = 32.
     * So, for "Rainbow" color pallete HSV.H = 32 it`s 2nd color - CF_ORANGE.
     */
    CF_HSV2RGB(&HSV, &RGB, &CF_ColorPallete_Rainbow);

    printf("H = %d\nS = %d\nV = %d\n\n", HSV.H, HSV.S, HSV.V);
    printf("R = %d\nG = %d\nB = %d\n", RGB.R, RGB.G, RGB.B);

    return 0;
}
