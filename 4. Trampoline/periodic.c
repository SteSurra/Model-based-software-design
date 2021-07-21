#include <stdio.h>
#include "tpl_os.h"

#include "feedback_control.h"
#include "rtwtypes.h"



static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr =
  &feedback_control_M_;                /* Real-time model */
static BlockIO_feedback_control feedback_control_B; /* Observable signals */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/Echo' */
static real_T feedback_control_U_Echo;

/* '<Root>/Blinking' */
static boolean_T feedback_control_Y_Blinking;

/* '<Root>/Error' */
static boolean_T feedback_control_Y_Error;

/* '<Root>/Trigger' */
static boolean_T feedback_control_Y_Trigger;

FILE *fpEcho;

void setup(){
    
    /*Pack model data into RTM*/
    feedback_control_MPtr->dwork = &feedback_control_DWork;
    feedback_control_MPtr->blockIO = &feedback_control_B; //?
    
    /*Initialize model*/
    feedback_control_initialize(feedback_control_MPtr, &feedback_control_U_Echo, &feedback_control_Y_Blinking, &feedback_control_Y_Error, &feedback_control_Y_Trigger);
    
    fpEcho=fopen("input_echo.txt","r");
 
    return;
}


int main(void)
{
    setup();
    
    StartOS(OSDEFAULTAPPMODE);
    
    return 0;
}

DeclareAlarm(alarm_10msec);

real_T BSWreadEcho(){
    
    int num;
    
    fscanf(fpEcho,"%d\n", &num);
    feedback_control_U_Echo = (double)num;
        
return feedback_control_U_Echo;
}

void BSWwriteError(boolean_T x){
    
    static int i=0;
    
    i++;
    
    if(x){
        printf("BSWwriteError[%d]: 1 ",i);
    }
    else{
        printf("BSWwriteError[%d]: 0 ",i);
    }
        
}

void BSWwriteBlinking(boolean_T x){
    
    static int i=0;
    
    i++;
    
    if(x){
        printf("BSWwriteBlinking[%d]: 1\r\n",i);
    }
    else{
        printf("BSWwriteBlinking[%d]: 0\r\n",i);
    }
        
}

void BSWwriteTrigger(boolean_T x){
    
    static int i=0;
    
    i++;
    
    if(x){
        printf("BSWwritetrigger[%d]: 1\r\n",i);
    }
    else{
        printf("BSWwriteTrigger[%d]: 0\r\n",i);
    }
        
}


TASK(my_periodic_task)
{
    static int i=0;
    i++;
    
    printf("---\r\n");
    
    feedback_control_U_Echo = BSWreadEcho();
    if(feedback_control_U_Echo){
        printf("BSWwriteEcho[%d]: 1 ",i);
    }
    else{
        printf("BSWwriteEcho[%d]: 0 ",i);
    }
    
    
    
    feedback_control_step(feedback_control_MPtr, feedback_control_U_Echo, &feedback_control_Y_Blinking, &feedback_control_Y_Error,&feedback_control_Y_Trigger);

    
    BSWwriteError(feedback_control_Y_Error);
    BSWwriteBlinking(feedback_control_Y_Blinking);
    BSWwriteTrigger(feedback_control_Y_Trigger);
    printf("\n\n");
    
  TerminateTask();
}

TASK(stop)
{
  fclose(fpEcho);
  CancelAlarm(alarm_10msec);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}
