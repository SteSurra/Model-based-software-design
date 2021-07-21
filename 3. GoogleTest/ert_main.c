/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "feedback_control.h"          /* Model's header file */
#include "rtwtypes.h"
//ADD
#include <iostream>
#include <gtest/gtest.h>
//ADD

static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr =
  &feedback_control_M_;                /* Real-time model */
static BlockIO_feedback_control feedback_control_B;/* Observable signals */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/Echo' */
static real_T feedback_control_U_Echo;

/* '<Root>/Blinking' */
static boolean_T feedback_control_Y_Blinking;

/* '<Root>/Error' */
static boolean_T feedback_control_Y_Error;

/* '<Root>/Trigger' */
static boolean_T feedback_control_Y_Trigger;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */

//QUI

void setup(){
    
    /*Pack model data into RTM*/
    feedback_control_MPtr->dwork = &feedback_control_DWork;
    feedback_control_MPtr->blockIO = &feedback_control_B;
    
    /*Initialize model*/
    feedback_control_initialize(feedback_control_MPtr, &feedback_control_U_Echo, &feedback_control_Y_Blinking, &feedback_control_Y_Error, &feedback_control_Y_Trigger);
    
}


TEST(UnitTest, test_ert_main){
    
    setup();
    
    long int i=0;
    int num, error, blinking, trigger;
    FILE *fpEcho, *fpError, *fpBlinking, *fpTrigger;
    
    fpEcho=fopen("input_echo.txt","r");
    fpError=fopen("output_error.txt","r");
    fpBlinking=fopen("output_blinking.txt","r");
    fpTrigger=fopen("output_trigger.txt","r");
    
    while(fscanf(fpEcho,"%d\n", &num)!=EOF)
    {
        fscanf(fpError,"%d\n", &error);
        fscanf(fpBlinking,"%d\n", &blinking);
        fscanf(fpTrigger,"%d\n", &trigger);
        
        feedback_control_U_Echo = (double)num;
        
      feedback_control_step(feedback_control_MPtr, feedback_control_U_Echo, &feedback_control_Y_Blinking, &feedback_control_Y_Error,&feedback_control_Y_Trigger);
        
        
        EXPECT_EQ(feedback_control_Y_Error, error);
        EXPECT_EQ(feedback_control_Y_Blinking, blinking);
        EXPECT_EQ(feedback_control_Y_Trigger, trigger);
        
    }

    
    fclose(fpEcho);
    fclose(fpError);
    fclose(fpBlinking);
    fclose(fpTrigger);

        
}

TEST(UnitTest, test_terminate){
    
    /* pack model data into RTM */
    
    feedback_control_MPtr->dwork = &feedback_control_DWork;
    feedback_control_MPtr->blockIO = &feedback_control_B;
    
    feedback_control_terminate(feedback_control_MPtr);
    
    
}

//ADD
/*Per inizializzare il framework di googletest ed eseguire tutti i test*/
int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//ADD

