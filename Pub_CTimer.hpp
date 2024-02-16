/**
  ******************************************************************************
  * @file    Pub/Pub_CTimer.hpp
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2023-12-29
  * @brief   Header file for the Pub_CTimer.cpp
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PUB_CTIMER_H
#define __PUB_CTIMER_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

extern uint64_t SysTime;

/**
  * @class  CTimer
  */
class CTimer
{
public:
    CTimer(uint32_t period)
    {
        Period = period;
        TimeBase = 0;
    };
    ~CTimer(){};
    
    bool TimeOut(void);
    void SetPeriod(uint32_t period);
protected:

private:
    uint32_t Period;
    uint32_t TimeBase;
    
    bool isEnable;
};

#endif /* __PUB_CTIMER_H */

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
