/**
  ******************************************************************************
  * File Name          : bsp.cc
  * Description        : This file is used to init the Board Support Packages
  ******************************************************************************
  * @attention
  *
  * TODO: Copyright
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/*----------------------------------------------------------------------------*/
/* Configure BSP                                                             */
/*----------------------------------------------------------------------------*/

/**
  * @brief Board Support Package Initialization
  * @retval None
  *
  */
void BSP_Init(void) {
  /* Configure LEDs */
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_RED);
  BSP_LED_On(LED_GREEN);

  /* Configure Button */
  BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_GPIO);
  /* Configure LCD */
  /* Initialize the LCD */
  uint8_t  lcd_status = LCD_OK;
  lcd_status = BSP_LCD_Init();
  while (lcd_status != LCD_OK) {}
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  BSP_LCD_Clear(LCD_COLOR_WHITE);

  /* Configure Touchscreen (optional) */
  // Touchscreen_Calibration();
  BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

#ifdef FAKE_TOUCH
  /* SD Card Init */
  BSP_SD_Init();

  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
#endif /* FAKE_TOUCH*/

  /* Set Default LCD Colors and Fonts */
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  BSP_LCD_SetFont(&Font12);
}