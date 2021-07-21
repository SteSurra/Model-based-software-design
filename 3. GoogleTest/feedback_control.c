/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Jun 23 06:52:33 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "feedback_control.h"

/* Named constants for Chart: '<S1>/Blink' */
#define feedback_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_control_IN_Blinker1   ((uint8_T)1U)
#define feedback_control_IN_Blinker2   ((uint8_T)2U)
#define feedback_control_IN_LED_OFF    ((uint8_T)1U)
#define feedback_control_IN_LED_ON     ((uint8_T)2U)
#define feedback_control_IN_NO_BLINK   ((uint8_T)3U)
#define feedback_control_IN_blinker3   ((uint8_T)4U)

/* Named constants for Chart: '<S2>/MonitoringLogic' */
#define feedback_con_IN_CHECK_FOR_ERROR ((uint8_T)1U)
#define feedback_control_IN_ERROR_STATE ((uint8_T)2U)
#define feedback_control_IN_RESET      ((uint8_T)3U)

/* Named constants for Chart: '<S3>/FromEchoToDistance' */
#define feedback_contro_IN_WAIT_TO_FALL ((uint8_T)2U)
#define feedback_control_IN_INIT       ((uint8_T)1U)

/* Named constants for Chart: '<S4>/TriggerPulseGenerator' */
#define feedback_control_IN_HIGH       ((uint8_T)1U)
#define feedback_control_IN_LOW        ((uint8_T)2U)

/* Model step function */
void feedback_control_step(RT_MODEL_feedback_control *const feedback_control_M,
  real_T feedback_control_U_Echo, boolean_T *feedback_control_Y_Blinking,
  boolean_T *feedback_control_Y_Error, boolean_T *feedback_control_Y_Trigger)
{
  BlockIO_feedback_control *feedback_control_B = feedback_control_M->blockIO;
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;
  g_dsp_private_SlidingWindowAver *obj;
  real_T csumrev[3];
  real_T csum;
  real_T cumRevIndex;
  real_T z;

  /* Chart: '<S3>/FromEchoToDistance' incorporates:
   *  Inport: '<Root>/Echo'
   */
  if (feedback_control_DWork->temporalCounter_i1_l < 131071U) {
    feedback_control_DWork->temporalCounter_i1_l++;
  }

  /* Gateway: FromEchoToDistance/FromEchoToDistance */
  /* During: FromEchoToDistance/FromEchoToDistance */
  if (feedback_control_DWork->is_active_c5_feedback_control == 0U) {
    /* Entry: FromEchoToDistance/FromEchoToDistance */
    feedback_control_DWork->is_active_c5_feedback_control = 1U;

    /* Entry Internal: FromEchoToDistance/FromEchoToDistance */
    /* Entry Internal 'COMPUTE_ECHO_DURATION': '<S7>:2' */
    /* Transition: '<S7>:5' */
    feedback_control_DWork->is_COMPUTE_ECHO_DURATION = feedback_control_IN_INIT;
    feedback_control_DWork->temporalCounter_i1_l = 0U;

    /* Entry 'INIT': '<S7>:4' */
    feedback_control_DWork->Counter = 0.0;
  } else {
    /* During 'COMPUTE_ECHO_DURATION': '<S7>:2' */
    if (feedback_control_DWork->is_COMPUTE_ECHO_DURATION ==
        feedback_control_IN_INIT) {
      /* During 'INIT': '<S7>:4' */
      if (feedback_control_U_Echo == 1.0) {
        /* Transition: '<S7>:8' */
        feedback_control_DWork->is_COMPUTE_ECHO_DURATION =
          feedback_contro_IN_WAIT_TO_FALL;

        /* Entry 'WAIT_TO_FALL': '<S7>:7' */
        feedback_control_DWork->Counter++;
      } else {
        if ((feedback_control_DWork->temporalCounter_i1_l >= 100000U) &&
            (feedback_control_U_Echo == 0.0)) {
          /* Transition: '<S7>:19' */
          feedback_control_B->Distance = 0.0;
          feedback_control_DWork->is_COMPUTE_ECHO_DURATION =
            feedback_control_IN_INIT;
          feedback_control_DWork->temporalCounter_i1_l = 0U;

          /* Entry 'INIT': '<S7>:4' */
          feedback_control_DWork->Counter = 0.0;
        }
      }
    } else {
      /* During 'WAIT_TO_FALL': '<S7>:7' */
      if (feedback_control_U_Echo == 1.0) {
        /* Transition: '<S7>:11' */
        feedback_control_DWork->is_COMPUTE_ECHO_DURATION =
          feedback_contro_IN_WAIT_TO_FALL;

        /* Entry 'WAIT_TO_FALL': '<S7>:7' */
        feedback_control_DWork->Counter++;
      } else {
        /* Transition: '<S7>:16' */
        feedback_control_B->Distance = feedback_control_DWork->Counter / 58.0;
        feedback_control_DWork->is_COMPUTE_ECHO_DURATION =
          feedback_control_IN_INIT;
        feedback_control_DWork->temporalCounter_i1_l = 0U;

        /* Entry 'INIT': '<S7>:4' */
        feedback_control_DWork->Counter = 0.0;
      }
    }
  }

  /* End of Chart: '<S3>/FromEchoToDistance' */

  /* MATLABSystem: '<S3>/Moving Average' */
  if (feedback_control_DWork->obj.TunablePropsChanged) {
    feedback_control_DWork->obj.TunablePropsChanged = false;
  }

  obj = feedback_control_DWork->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  csumrev[2] = obj->pCumSumRev[2];
  csum += feedback_control_B->Distance;
  z = csumrev[((int32_T)cumRevIndex) - 1] + csum;
  csumrev[((int32_T)cumRevIndex) - 1] = feedback_control_B->Distance;
  if (cumRevIndex != 3.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    csumrev[1] += csumrev[2];
    csumrev[0] += csumrev[1];
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumSumRev[2] = csumrev[2];
  obj->pCumRevIndex = cumRevIndex;
  cumRevIndex = z / 4.0;

  /* End of MATLABSystem: '<S3>/Moving Average' */

  /* Chart: '<S1>/Blink' */
  if (feedback_control_DWork->temporalCounter_i1_o < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i1_o++;
  }

  /* Gateway: DutyCycleGenerator/Blink */
  /* During: DutyCycleGenerator/Blink */
  if (feedback_control_DWork->is_active_c3_feedback_control == 0U) {
    /* Entry: DutyCycleGenerator/Blink */
    feedback_control_DWork->is_active_c3_feedback_control = 1U;

    /* Entry Internal: DutyCycleGenerator/Blink */
    /* Transition: '<S5>:20' */
    feedback_control_DWork->is_c3_feedback_control =
      feedback_control_IN_NO_BLINK;

    /* Entry 'NO_BLINK': '<S5>:11' */
  } else {
    switch (feedback_control_DWork->is_c3_feedback_control) {
     case feedback_control_IN_Blinker1:
      /* During 'Blinker1': '<S5>:10' */
      if ((cumRevIndex < 10.0) || (cumRevIndex > 100.0)) {
        /* Transition: '<S5>:24' */
        /* Transition: '<S5>:49' */
        /* Exit Internal 'Blinker1': '<S5>:10' */
        feedback_control_DWork->is_Blinker1 = feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_NO_BLINK;

        /* Entry 'NO_BLINK': '<S5>:11' */
      } else if (feedback_control_DWork->is_Blinker1 ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = false;

        /* During 'LED_OFF': '<S5>:4' */
        if (feedback_control_DWork->temporalCounter_i1_o >= ((uint32_T)ceil
             (((0.1 - (cumRevIndex / 1000.0)) / 1.0E-6) - 1.0E-14))) {
          /* Transition: '<S5>:7' */
          feedback_control_DWork->is_Blinker1 = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_ON': '<S5>:6' */
          *feedback_control_Y_Blinking = true;
        }
      } else {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = true;

        /* During 'LED_ON': '<S5>:6' */
        if (cumRevIndex == 100.0) {
          /* Transition: '<S5>:52' */
          feedback_control_DWork->is_Blinker1 = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_ON': '<S5>:6' */
          *feedback_control_Y_Blinking = true;
        } else {
          if (feedback_control_DWork->temporalCounter_i1_o >= ((uint32_T)ceil
               (((cumRevIndex / 1000.0) / 1.0E-6) - 1.0E-14))) {
            /* Transition: '<S5>:8' */
            feedback_control_DWork->is_Blinker1 = feedback_control_IN_LED_OFF;
            feedback_control_DWork->temporalCounter_i1_o = 0U;

            /* Outport: '<Root>/Blinking' */
            /* Entry 'LED_OFF': '<S5>:4' */
            *feedback_control_Y_Blinking = false;
          }
        }
      }
      break;

     case feedback_control_IN_Blinker2:
      /* During 'Blinker2': '<S5>:32' */
      if (((cumRevIndex >= 10.0) && (cumRevIndex <= 100.0)) || (cumRevIndex ==
           0.0)) {
        /* Transition: '<S5>:34' */
        /* Exit Internal 'Blinker2': '<S5>:32' */
        feedback_control_DWork->is_Blinker2 = feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_NO_BLINK;

        /* Entry 'NO_BLINK': '<S5>:11' */
      } else if (feedback_control_DWork->is_Blinker2 ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = false;

        /* During 'LED_OFF': '<S5>:31' */
        if (feedback_control_DWork->temporalCounter_i1_o >= 250000U) {
          /* Transition: '<S5>:28' */
          feedback_control_DWork->is_Blinker2 = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_ON': '<S5>:29' */
          *feedback_control_Y_Blinking = true;
        }
      } else {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = true;

        /* During 'LED_ON': '<S5>:29' */
        if (feedback_control_DWork->temporalCounter_i1_o >= 250000U) {
          /* Transition: '<S5>:27' */
          feedback_control_DWork->is_Blinker2 = feedback_control_IN_LED_OFF;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_OFF': '<S5>:31' */
          *feedback_control_Y_Blinking = false;
        }
      }
      break;

     case feedback_control_IN_NO_BLINK:
      /* During 'NO_BLINK': '<S5>:11' */
      if ((cumRevIndex >= 10.0) && (cumRevIndex <= 100.0)) {
        /* Transition: '<S5>:18' */
        /* Transition: '<S5>:19' */
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_Blinker1;

        /* Entry Internal 'Blinker1': '<S5>:10' */
        /* Transition: '<S5>:51' */
        feedback_control_DWork->is_Blinker1 = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i1_o = 0U;

        /* Outport: '<Root>/Blinking' */
        /* Entry 'LED_ON': '<S5>:6' */
        *feedback_control_Y_Blinking = true;
      } else if (((cumRevIndex < 10.0) || (cumRevIndex > 100.0)) && (cumRevIndex
                  != 0.0)) {
        /* Transition: '<S5>:33' */
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_Blinker2;

        /* Entry Internal 'Blinker2': '<S5>:32' */
        /* Transition: '<S5>:30' */
        feedback_control_DWork->is_Blinker2 = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i1_o = 0U;

        /* Outport: '<Root>/Blinking' */
        /* Entry 'LED_ON': '<S5>:29' */
        *feedback_control_Y_Blinking = true;
      } else {
        /* Transition: '<S5>:42' */
        /* Transition: '<S5>:43' */
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_blinker3;

        /* Entry Internal 'blinker3': '<S5>:40' */
        /* Transition: '<S5>:36' */
        feedback_control_DWork->is_blinker3 = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i1_o = 0U;

        /* Outport: '<Root>/Blinking' */
        /* Entry 'LED_ON': '<S5>:35' */
        *feedback_control_Y_Blinking = true;
      }
      break;

     default:
      /* During 'blinker3': '<S5>:40' */
      if (cumRevIndex != 0.0) {
        /* Transition: '<S5>:47' */
        /* Transition: '<S5>:48' */
        /* Exit Internal 'blinker3': '<S5>:40' */
        feedback_control_DWork->is_blinker3 = feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_NO_BLINK;

        /* Entry 'NO_BLINK': '<S5>:11' */
      } else if (feedback_control_DWork->is_blinker3 ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = false;

        /* During 'LED_OFF': '<S5>:37' */
        if (feedback_control_DWork->temporalCounter_i1_o >= 500000U) {
          /* Transition: '<S5>:39' */
          feedback_control_DWork->is_blinker3 = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_ON': '<S5>:35' */
          *feedback_control_Y_Blinking = true;
        }
      } else {
        /* Outport: '<Root>/Blinking' */
        *feedback_control_Y_Blinking = true;

        /* During 'LED_ON': '<S5>:35' */
        if (feedback_control_DWork->temporalCounter_i1_o >= 500000U) {
          /* Transition: '<S5>:38' */
          feedback_control_DWork->is_blinker3 = feedback_control_IN_LED_OFF;
          feedback_control_DWork->temporalCounter_i1_o = 0U;

          /* Outport: '<Root>/Blinking' */
          /* Entry 'LED_OFF': '<S5>:37' */
          *feedback_control_Y_Blinking = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Blink' */

  /* Chart: '<S2>/MonitoringLogic' */
  if (feedback_control_DWork->temporalCounter_i1_p < 524287U) {
    feedback_control_DWork->temporalCounter_i1_p++;
  }

  /* Gateway: ErrorMonitoring/MonitoringLogic */
  /* During: ErrorMonitoring/MonitoringLogic */
  if (feedback_control_DWork->is_active_c1_feedback_control == 0U) {
    /* Entry: ErrorMonitoring/MonitoringLogic */
    feedback_control_DWork->is_active_c1_feedback_control = 1U;

    /* Entry Internal: ErrorMonitoring/MonitoringLogic */
    /* Transition: '<S6>:4' */
    feedback_control_DWork->is_c1_feedback_control = feedback_control_IN_RESET;

    /* Outport: '<Root>/Error' */
    /* Entry 'RESET': '<S6>:3' */
    *feedback_control_Y_Error = false;
  } else {
    switch (feedback_control_DWork->is_c1_feedback_control) {
     case feedback_con_IN_CHECK_FOR_ERROR:
      /* Outport: '<Root>/Error' */
      *feedback_control_Y_Error = false;

      /* During 'CHECK_FOR_ERROR': '<S6>:7' */
      if ((cumRevIndex >= 2.0) && (cumRevIndex <= 400.0)) {
        /* Transition: '<S6>:12' */
        /* Transition: '<S6>:14' */
        /* Transition: '<S6>:15' */
        feedback_control_DWork->is_c1_feedback_control =
          feedback_control_IN_RESET;

        /* Outport: '<Root>/Error' */
        /* Entry 'RESET': '<S6>:3' */
        *feedback_control_Y_Error = false;
      } else {
        if ((feedback_control_DWork->temporalCounter_i1_p >= 400000U) &&
            ((cumRevIndex < 2.0) || ((cumRevIndex > 400.0) && (cumRevIndex !=
               0.0)))) {
          /* Transition: '<S6>:19' */
          feedback_control_DWork->is_c1_feedback_control =
            feedback_control_IN_ERROR_STATE;

          /* Outport: '<Root>/Error' */
          /* Entry 'ERROR_STATE': '<S6>:18' */
          *feedback_control_Y_Error = true;
        }
      }
      break;

     case feedback_control_IN_ERROR_STATE:
      /* Outport: '<Root>/Error' */
      *feedback_control_Y_Error = true;

      /* During 'ERROR_STATE': '<S6>:18' */
      if (((cumRevIndex >= 2.0) && (cumRevIndex <= 400.0)) || (cumRevIndex ==
           0.0)) {
        /* Transition: '<S6>:24' */
        /* Transition: '<S6>:25' */
        /* Transition: '<S6>:14' */
        /* Transition: '<S6>:15' */
        feedback_control_DWork->is_c1_feedback_control =
          feedback_control_IN_RESET;

        /* Outport: '<Root>/Error' */
        /* Entry 'RESET': '<S6>:3' */
        *feedback_control_Y_Error = false;
      }
      break;

     default:
      /* Outport: '<Root>/Error' */
      *feedback_control_Y_Error = false;

      /* During 'RESET': '<S6>:3' */
      if (((cumRevIndex < 2.0) || (cumRevIndex > 400.0)) && (cumRevIndex != 0.0))
      {
        /* Transition: '<S6>:8' */
        feedback_control_DWork->is_c1_feedback_control =
          feedback_con_IN_CHECK_FOR_ERROR;
        feedback_control_DWork->temporalCounter_i1_p = 0U;

        /* Outport: '<Root>/Error' */
        /* Entry 'CHECK_FOR_ERROR': '<S6>:7' */
        *feedback_control_Y_Error = false;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/MonitoringLogic' */

  /* Chart: '<S4>/TriggerPulseGenerator' */
  if (feedback_control_DWork->temporalCounter_i1 < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i1++;
  }

  /* Gateway: TriggerPulseGenerator/TriggerPulseGenerator */
  /* During: TriggerPulseGenerator/TriggerPulseGenerator */
  if (feedback_control_DWork->is_active_c2_feedback_control == 0U) {
    /* Entry: TriggerPulseGenerator/TriggerPulseGenerator */
    feedback_control_DWork->is_active_c2_feedback_control = 1U;

    /* Entry Internal: TriggerPulseGenerator/TriggerPulseGenerator */
    /* Transition: '<S8>:2' */
    feedback_control_DWork->is_c2_feedback_control = feedback_control_IN_HIGH;
    feedback_control_DWork->temporalCounter_i1 = 0U;

    /* Outport: '<Root>/Trigger' */
    /* Entry 'HIGH': '<S8>:1' */
    *feedback_control_Y_Trigger = true;
  } else if (feedback_control_DWork->is_c2_feedback_control ==
             feedback_control_IN_HIGH) {
    /* Outport: '<Root>/Trigger' */
    *feedback_control_Y_Trigger = true;

    /* During 'HIGH': '<S8>:1' */
    if (feedback_control_DWork->temporalCounter_i1 >= 20U) {
      /* Transition: '<S8>:5' */
      feedback_control_DWork->is_c2_feedback_control = feedback_control_IN_LOW;
      feedback_control_DWork->temporalCounter_i1 = 0U;

      /* Outport: '<Root>/Trigger' */
      /* Entry 'LOW': '<S8>:4' */
      *feedback_control_Y_Trigger = false;
    }
  } else {
    /* Outport: '<Root>/Trigger' */
    *feedback_control_Y_Trigger = false;

    /* During 'LOW': '<S8>:4' */
    if (feedback_control_DWork->temporalCounter_i1 >= 99998U) {
      /* Transition: '<S8>:6' */
      feedback_control_DWork->is_c2_feedback_control = feedback_control_IN_HIGH;
      feedback_control_DWork->temporalCounter_i1 = 0U;

      /* Outport: '<Root>/Trigger' */
      /* Entry 'HIGH': '<S8>:1' */
      *feedback_control_Y_Trigger = true;
    }
  }

  /* End of Chart: '<S4>/TriggerPulseGenerator' */
}

/* Model initialize function */
void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, real_T *feedback_control_U_Echo, boolean_T
  *feedback_control_Y_Blinking, boolean_T *feedback_control_Y_Error, boolean_T
  *feedback_control_Y_Trigger)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;
  BlockIO_feedback_control *feedback_control_B = feedback_control_M->blockIO;

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) feedback_control_B), 0,
                sizeof(BlockIO_feedback_control));

  /* states (dwork) */
  (void) memset((void *)feedback_control_DWork, 0,
                sizeof(D_Work_feedback_control));

  /* external inputs */
  *feedback_control_U_Echo = 0.0;

  /* external outputs */
  (*feedback_control_Y_Blinking) = false;
  (*feedback_control_Y_Error) = false;
  (*feedback_control_Y_Trigger) = false;

  {
    dsp_simulink_MovingAverage_feed *obj;
    g_dsp_private_SlidingWindowAver *obj_0;

    /* SystemInitialize for Chart: '<S3>/FromEchoToDistance' */
    feedback_control_DWork->is_COMPUTE_ECHO_DURATION =
      feedback_con_IN_NO_ACTIVE_CHILD;
    feedback_control_DWork->temporalCounter_i1_l = 0U;
    feedback_control_DWork->is_active_c5_feedback_control = 0U;

    /* SystemInitialize for Chart: '<S1>/Blink' */
    feedback_control_DWork->is_Blinker1 = feedback_con_IN_NO_ACTIVE_CHILD;
    feedback_control_DWork->is_Blinker2 = feedback_con_IN_NO_ACTIVE_CHILD;
    feedback_control_DWork->is_blinker3 = feedback_con_IN_NO_ACTIVE_CHILD;
    feedback_control_DWork->temporalCounter_i1_o = 0U;
    feedback_control_DWork->is_active_c3_feedback_control = 0U;
    feedback_control_DWork->is_c3_feedback_control =
      feedback_con_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/MonitoringLogic' */
    feedback_control_DWork->temporalCounter_i1_p = 0U;
    feedback_control_DWork->is_active_c1_feedback_control = 0U;
    feedback_control_DWork->is_c1_feedback_control =
      feedback_con_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S4>/TriggerPulseGenerator' */
    feedback_control_DWork->temporalCounter_i1 = 0U;
    feedback_control_DWork->is_active_c2_feedback_control = 0U;
    feedback_control_DWork->is_c2_feedback_control =
      feedback_con_IN_NO_ACTIVE_CHILD;

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    feedback_control_DWork->obj.matlabCodegenIsDeleted = true;
    feedback_control_DWork->obj.isInitialized = 0;
    feedback_control_DWork->obj.NumChannels = -1;
    feedback_control_DWork->obj.matlabCodegenIsDeleted = false;
    obj = &feedback_control_DWork->obj;
    feedback_control_DWork->obj.isSetupComplete = false;
    feedback_control_DWork->obj.isInitialized = 1;
    feedback_control_DWork->obj.NumChannels = 1;
    obj->_pobj0.isInitialized = 0;
    feedback_control_DWork->obj.pStatistic = &obj->_pobj0;
    feedback_control_DWork->obj.isSetupComplete = true;
    feedback_control_DWork->obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
    obj_0 = feedback_control_DWork->obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      obj_0->pCumSumRev[0] = 0.0;
      obj_0->pCumSumRev[1] = 0.0;
      obj_0->pCumSumRev[2] = 0.0;
      obj_0->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
  }
}

/* Model terminate function */
void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;
  g_dsp_private_SlidingWindowAver *obj;

  /* Terminate for MATLABSystem: '<S3>/Moving Average' */
  if (!feedback_control_DWork->obj.matlabCodegenIsDeleted) {
    feedback_control_DWork->obj.matlabCodegenIsDeleted = true;
    if ((feedback_control_DWork->obj.isInitialized == 1) &&
        (feedback_control_DWork->obj.isSetupComplete)) {
      obj = feedback_control_DWork->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      feedback_control_DWork->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Moving Average' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
