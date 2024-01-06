/**
  ******************************************************************************
  * @file    Pub/Pub_CPID_Delta.cpp 
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2023-12-29
  * @brief   PID_Delta class body
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Pub_CPID_Delta.hpp"

/**
  * @brief  Init
  * @param  None
  * @retval None
  */
void CPID_Delta::Init(float kp, float ki, float kd, float min, float max)
{
    Kp = kp;
    Ki = ki;
    Kd = kd;
}

/**
  * @brief  Calculate
  * @param  None
  * @retval None
  */
float CPID_Delta::Calculate(float SV, float PV)
{
    float Udelta;
    
    /** ZN mode **/
    if(ZN_Modle)
    {
        if(SV > PV)
        {
            Uk = Umax;
        }
        else
        {
            Uk = Umin;
        }
        return Uk;
    }
        
    /** Work mode **/
    Err[2] = Err[1];
    Err[1] = Err[0];
    Err[0] = SV - PV;
    
    Udelta = (Kp + Ki + Kd)*Err[0] - (Kp + 2*Kd)*Err[1] + Kd*Err[2];
    
    Uk += Udelta;
    
    if(Uk > Umax)
    {
        Uk = Umax;
    }
    else if(Uk < Umin)
    {
        Uk = Umin;
    }
    return Uk;
}

/**
  * @brief  Reset
  * @param  None
  * @retval None
  */
void CPID_Delta::Reset(void)
{
    Err[0] = 0.0f;
    Err[1] = 0.0f;
    Err[2] = 0.0f;
    Uk     = 0.0f;
}


/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
