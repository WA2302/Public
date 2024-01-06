/**
  ******************************************************************************
  * @file    Pub/Pub_CTimer.cpp 
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2023-12-29
  * @brief   Timer class body
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Pub_CTimer.hpp"

/**
  * @brief  SetPeriod
  * @param  uint32_t: period to set
  * @retval None
  */
void CTimer::SetPeriod(uint32_t period)
{
    Period = period;
    TimeBase = SysTime;
}

/**
  * @brief  TimeOut
  * @param  None
  * @retval True: timeout False:not
  */
bool CTimer::TimeOut(void)
{
    if(SysTime - TimeBase >= Period)
    {
        TimeBase = SysTime;
        return true;
    }
    
    return false;
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
