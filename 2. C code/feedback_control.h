/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.105
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jun 25 14:37:33 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

#ifndef struct_tag_n6PybfofDJX1nilXyEd0pE
#define struct_tag_n6PybfofDJX1nilXyEd0pE

struct tag_n6PybfofDJX1nilXyEd0pE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_n6PybfofDJX1nilXyEd0pE*/

#ifndef typedef_g_dsp_private_SlidingWindowAver
#define typedef_g_dsp_private_SlidingWindowAver

typedef struct tag_n6PybfofDJX1nilXyEd0pE g_dsp_private_SlidingWindowAver;

#endif                               /*typedef_g_dsp_private_SlidingWindowAver*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_feedback_control
#define typedef_cell_wrap_feedback_control

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_feedback_control;

#endif                                 /*typedef_cell_wrap_feedback_control*/

#ifndef struct_tag_i9IfhfSX0XccmEaqGxzasC
#define struct_tag_i9IfhfSX0XccmEaqGxzasC

struct tag_i9IfhfSX0XccmEaqGxzasC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_feedback_control inputVarSize;
  g_dsp_private_SlidingWindowAver *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAver _pobj0;
};

#endif                                 /*struct_tag_i9IfhfSX0XccmEaqGxzasC*/

#ifndef typedef_dsp_simulink_MovingAverage_feed
#define typedef_dsp_simulink_MovingAverage_feed

typedef struct tag_i9IfhfSX0XccmEaqGxzasC dsp_simulink_MovingAverage_feed;

#endif                               /*typedef_dsp_simulink_MovingAverage_feed*/

/* Block signals (default storage) */
typedef struct {
  real_T Distance;                     /* '<S3>/FromEchoToDistance' */
} BlockIO_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_feed obj; /* '<S3>/Moving Average' */
  real_T Counter;                      /* '<S3>/FromEchoToDistance' */
  uint32_T temporalCounter_i1;         /* '<S4>/TriggerPulseGenerator' */
  uint32_T temporalCounter_i1_l;       /* '<S3>/FromEchoToDistance' */
  uint32_T temporalCounter_i1_p;       /* '<S2>/MonitoringLogic' */
  uint32_T temporalCounter_i1_o;       /* '<S1>/Blink' */
  uint8_T is_active_c5_feedback_control;/* '<S4>/TriggerPulseGenerator' */
  uint8_T is_c5_feedback_control;      /* '<S4>/TriggerPulseGenerator' */
  uint8_T is_active_c1_feedback_control;/* '<S3>/FromEchoToDistance' */
  uint8_T is_COMPUTE_ECHO_DURATION;    /* '<S3>/FromEchoToDistance' */
  uint8_T is_active_c3_feedback_control;/* '<S2>/MonitoringLogic' */
  uint8_T is_c3_feedback_control;      /* '<S2>/MonitoringLogic' */
  uint8_T is_active_c2_feedback_control;/* '<S1>/Blink' */
  uint8_T is_c2_feedback_control;      /* '<S1>/Blink' */
  uint8_T is_Blinker2;                 /* '<S1>/Blink' */
  uint8_T is_blinker3;                 /* '<S1>/Blink' */
  uint8_T is_Blinker1;                 /* '<S1>/Blink' */
} D_Work_feedback_control;

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T * volatile errorStatus;
  BlockIO_feedback_control *blockIO;
  D_Work_feedback_control *dwork;
};

/* Model entry point functions */
extern void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, real_T *feedback_control_U_Echo, boolean_T
  *feedback_control_Y_Blinking, boolean_T *feedback_control_Y_Error, boolean_T
  *feedback_control_Y_Trigger);
extern void feedback_control_step(RT_MODEL_feedback_control *const
  feedback_control_M, real_T feedback_control_U_Echo, boolean_T
  *feedback_control_Y_Blinking, boolean_T *feedback_control_Y_Error, boolean_T
  *feedback_control_Y_Trigger);
extern void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/DutyCycleGenerator'
 * '<S2>'   : 'feedback_control/ErrorMonitoring'
 * '<S3>'   : 'feedback_control/FromEchoToDistance'
 * '<S4>'   : 'feedback_control/TriggerPulseGenerator'
 * '<S5>'   : 'feedback_control/DutyCycleGenerator/Blink'
 * '<S6>'   : 'feedback_control/ErrorMonitoring/MonitoringLogic'
 * '<S7>'   : 'feedback_control/FromEchoToDistance/FromEchoToDistance'
 * '<S8>'   : 'feedback_control/TriggerPulseGenerator/TriggerPulseGenerator'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
