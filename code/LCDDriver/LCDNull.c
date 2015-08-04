/*
*********************************************************************************************************
*                                             uC/GUI V3.98
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : LCDNull.C
Purpose     : Empty driver
              This driver does no perform any function. It can be
              used for measurement purpose.
----------------------------------------------------------------------   
Version-Date---Author-Explanation                                        
----------------------------------------------------------------------   
0.90.00 030627 JE     a) First release
---------------------------END-OF-HEADER------------------------------
*/

#include <stddef.h>
#include "LCD_Private.h"      /* private modul definitions & config */
#include "GUI_Private.h"
#include "GUIDebug.h"
#include "Lcd.h"

#if (LCD_CONTROLLER == 1375) \
    && (!defined(WIN32) | defined(LCD_SIMCONTROLLER))

static LcdDriverOps* mLcdDriverOps = NULL;
    
/*********************************************************************
*
*       Exported functions
*
**********************************************************************
*/

/*********************************************************************
*
*       LCD_L0_SetPixelIndex
*/
void LCD_L0_SetPixelIndex(int x, int y, int PixelIndex) {
  GUI_USE_PARA(x);
  GUI_USE_PARA(y);
  GUI_USE_PARA(PixelIndex);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_SetPixelIndex)
  {
    mLcdDriverOps->Lcd_SetPixelIndex(x, y, PixelIndex);
  }
}

/*********************************************************************
*
*       LCD_L0_GetPixelIndex
*/
unsigned int LCD_L0_GetPixelIndex(int x, int y) {
  GUI_USE_PARA(x);
  GUI_USE_PARA(y);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_GetPixelIndex)
  {
    return mLcdDriverOps->Lcd_GetPixelIndex(x, y);
  }
  return 0;
}

/*********************************************************************
*
*       LCD_L0_XorPixel
*/
void LCD_L0_XorPixel(int x, int y) {
  GUI_USE_PARA(x);
  GUI_USE_PARA(y);
}

/*********************************************************************
*
*       LCD_L0_DrawHLine
*/
void LCD_L0_DrawHLine(int x0, int y,  int x1) {
  GUI_USE_PARA(x0);
  GUI_USE_PARA(y);
  GUI_USE_PARA(x1);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_DrawHLine)
  {
    mLcdDriverOps->Lcd_DrawHLine(x0, y, x1, LCD_COLORINDEX);
  }
}

/*********************************************************************
*
*       LCD_L0_DrawVLine
*/
void LCD_L0_DrawVLine(int x, int y0,  int y1) {
  GUI_USE_PARA(x);
  GUI_USE_PARA(y0);
  GUI_USE_PARA(y1);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_DrawVLine)
  {
    mLcdDriverOps->Lcd_DrawVLine(x, y0, y1, LCD_COLORINDEX);
  }
  
}

/*********************************************************************
*
*       LCD_L0_FillRect
*/
void LCD_L0_FillRect(int x0, int y0, int x1, int y1) {
  GUI_USE_PARA(x0);
  GUI_USE_PARA(y0);
  GUI_USE_PARA(x1);
  GUI_USE_PARA(y1);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_FillRect)
  {
    mLcdDriverOps->Lcd_FillRect(x0,y0,x1,y1,LCD_COLORINDEX);
  }
}

/*********************************************************************
*
*       LCD_L0_DrawBitmap
*/
void LCD_L0_DrawBitmap(int x0, int y0,
                       int xsize, int ysize,
                       int BitsPerPixel, 
                       int BytesPerLine,
                       const U8 GUI_UNI_PTR * pData, int Diff,
                       const LCD_PIXELINDEX* pTrans)
{
  GUI_USE_PARA(x0);
  GUI_USE_PARA(y0);
  GUI_USE_PARA(xsize);
  GUI_USE_PARA(ysize);
  GUI_USE_PARA(BitsPerPixel);
  GUI_USE_PARA(BytesPerLine);
  GUI_USE_PARA(pData);
  GUI_USE_PARA(Diff);
  GUI_USE_PARA(pTrans);
  if(mLcdDriverOps && mLcdDriverOps->Lcd_Pic)
  {
    mLcdDriverOps->Lcd_Pic(x0, y0, xsize, ysize, BitsPerPixel, BytesPerLine, (const U8 GUI_UNI_PTR *) pData, (const LCD_PIXELINDEX*) pTrans);
  }
}

/*********************************************************************
*
*       LCD_L0_SetOrg
*/
void LCD_L0_SetOrg(int x, int y) {
  GUI_USE_PARA(x);
  GUI_USE_PARA(y);
}

/*********************************************************************
*
*       LCD_On / LCD_Off
*/
void LCD_On (void) 
{
  if(mLcdDriverOps && mLcdDriverOps->Lcd_On)
  {
    mLcdDriverOps->Lcd_On();
  }
}
void LCD_Off(void) 
{
    if(mLcdDriverOps && mLcdDriverOps->Lcd_Off)
    {
        mLcdDriverOps->Lcd_Off();
    }
}

/*********************************************************************
*
*       LCD_L0_Init
*/
int LCD_L0_Init(LcdDriverOps* Ops) {
  mLcdDriverOps = Ops;
  if(mLcdDriverOps && mLcdDriverOps->Lcd_Init)
  {
    mLcdDriverOps->Lcd_Init();
  }
  return 0;
}

/*********************************************************************
*
*       LCD_L0_SetLUTEntry
*/
void LCD_L0_SetLUTEntry(U8 Pos, LCD_COLOR Color) {
  GUI_USE_PARA(Pos);
  GUI_USE_PARA(Color);
}

/*********************************************************************
*
*       LCD_L0_GetDevFunc
*/
void * LCD_L0_GetDevFunc(int Index) {
  GUI_USE_PARA(Index);
  return NULL;
}

#else

void LCDNull_c(void);
void LCDNull_c(void) {} /* avoid empty object files */

#endif /* (LCD_CONTROLLER == -2) */
	 	 			 		    	 				 	  			   	 	 	 	 	 	  	  	      	   		 	 	 		  		  	 		 	  	  			     			       	   	 			  		    	 	     	 				  	 					 	 			   	  	  			 				 		 	 	 			     			 
