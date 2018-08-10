/**
  ******************************************************************************
  * @file    colors_list.h
  *
  * @brief   This file contains all the predifined RGB colors and color
  *          palletes for easy use.
  *
  * @author  esynr3z
  * @date    30.12.2015
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COLORS_LIST_H
#define __COLORS_LIST_H
  
/** @addtogroup ColorFlow
  * @{
  */

/** @defgroup CF_Exported_Macro Macro
  * @{
  */

/** @defgroup CF_Exported_Macro_RGB_Colors RGB colors
  * @brief  Color macro for creating @ref RGB_TypeDef arrays for color palletes
  *   @ref CF_ColorPallete_TypeDef.
  * @{
  */

#define CF_RGB_WHITE      {255,255,255}
#define CF_RGB_RED        {255,  0,  0}
#define CF_RGB_ORANGE     {255,128,  0}
#define CF_RGB_YELLOW     {255,255,  0}
#define CF_RGB_GREENLIME  {191,255,  0}
#define CF_RGB_LIGHTGREEN {128,255,  0}
#define CF_RGB_GREEN      {  0,255,  0}
#define CF_RGB_CYAN       {  0,255,255}
#define CF_RGB_LIGHTBLUE  {  0,128,255}
#define CF_RGB_BLUE       {  0,  0,255}
#define CF_RGB_PURPLE     {128,  0,255}

/**
  * @}
  */

/** @defgroup CF_Exported_Macro_Color_Palletes Color palletes
  * @brief  Color palletes created from predifined @ref CF_Exported_Macro_RGB_Colors
  *   that can be used for easy creating structs @ref CF_ColorPallete_TypeDef.
  * @{
  */

#define CF_COLORPALLETE_RAINBOW     {CF_RGB_RED,\
                                     CF_RGB_ORANGE,\
                                     CF_RGB_YELLOW,\
                                     CF_RGB_GREEN,\
                                     CF_RGB_CYAN,\
                                     CF_RGB_BLUE,\
                                     CF_RGB_PURPLE,\
                                     CF_RGB_RED}

#define CF_COLORPALLETE_SUNNY       {CF_RGB_YELLOW,\
                                     CF_RGB_ORANGE,\
                                     CF_RGB_RED,\
                                     CF_RGB_YELLOW}

#define CF_COLORPALLETE_COLDY       {CF_RGB_CYAN,\
                                     CF_RGB_LIGHTBLUE,\
                                     CF_RGB_BLUE,\
                                     CF_RGB_CYAN}

#define CF_COLORPALLETE_GREENY      {CF_RGB_LIGHTGREEN,\
                                     CF_RGB_GREENLIME,\
                                     CF_RGB_YELLOW,\
                                     CF_RGB_LIGHTGREEN}

/**
  * @}
  */

/**
  * @}
  */

#endif /*__COLORS_LIST_H*/

/**
  * @}
  */

/************************** END OF FILE ***************************************/
