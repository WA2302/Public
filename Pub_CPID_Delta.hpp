/**
  ******************************************************************************
  * @file    Pub/Pub_CPID_Delta.hpp
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2023-12-29
  * @brief   Header file for the Pub_CPID_Delta.cpp
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PUB_CPID_DELTA_H
#define __PUB_CPID_DELTA_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/**
  * @class  CPID_Delta
  */
class CPID_Delta
{
public:
    CPID_Delta()
    {
        Uk = 0.0f;
        Err[0] = 0.0f;
        Err[1] = 0.0f;
        Err[2] = 0.0f;
    };
    ~CPID_Delta(){};
    
    void Init(float kp, float ki, float kd, float min, float max);
    float Calculate(float SV, float PV);
    void Reset(void);
protected:

private:
    float Err[3];
    float Kp;
    float Ki;
    float Kd;
    float Uk;
    float Umin;
    float Umax;
    
    bool ZN_Modle;
};

#endif /* __PUB_CPID_DELTA_H */

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
