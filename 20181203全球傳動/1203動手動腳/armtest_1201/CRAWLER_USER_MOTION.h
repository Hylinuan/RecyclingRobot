#ifndef CRAWLER_USER_MOTION_H
#define CRAWLER_USER_MOTION_H
#include <avr/pgmspace.h>
#define Adjustment_index false
#define Avoidance_index false

//===== User Default Sequence ======
const PROGMEM uint16_t DefaultPose[] = {18, 512, 512, 275, 250, 790, 497, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM transition_t DefaultInitial[] = {{0,1} ,{DefaultPose,500}};
const PROGMEM uint16_t NonePose[] = {18, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM transition_t None[] = {{0,1} ,{NonePose,500}};

//===== User Define Pose ======
const PROGMEM uint16_t U_still[] = {18, 500, 500, 255, 228, 790, 497, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_stop[] = {18, 501, 499, 255, 498, 790, 497, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_first[] = {18, 639, 382, 255, 519, 699, 655, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_two[] = {18, 756, 264, 255, 519, 699, 655, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_three[] = {18, 880, 130, 255, 519, 800, 525, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_three_left[] = {18, 880, 130, 255, 519, 800, 525, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_four[] = {18, 347, 686, 300, 607, 800, 546, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_four_left[] = {18, 347, 686, 200, 607, 800, 546, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_catch_ok[] = {18, 347, 686, 255, 607, 749, 546, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_cc_41[] = {18, 756, 264, 255, 256, 699, 655, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};
const PROGMEM uint16_t U_cc_42[] = {18, 756, 264, 255, 256, 800, 400, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};


//===== User Define Sequence ======
const PROGMEM transition_t U_catch_1[] = {{0,22} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_catch_three,500} ,{U_catch_three,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_four,500} ,{U_catch_four,500} ,{U_catch_ok,500} ,{U_catch_ok,500} ,{U_stop,500} ,{U_stop,500} ,{U_still,500} ,{U_still,500}};
const PROGMEM transition_t U_catch_2[] = {{0,24} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_cc_41,500} ,{U_cc_41,500} ,{U_cc_42,500} ,{U_cc_42,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_four,500} ,{U_catch_four,500} ,{U_catch_ok,500} ,{U_catch_ok,500} ,{U_stop,500} ,{U_stop,500} ,{U_still,500} ,{U_still,500}};
const PROGMEM transition_t U_stopaction[] = {{0,2} ,{U_still,500},{U_still,500}};
const PROGMEM transition_t U_cok_left[] = {{0,22} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_catch_three_left,500} ,{U_catch_three_left,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_four_left,500} ,{U_catch_four_left,500} ,{U_catch_ok,500} ,{U_catch_ok,500} ,{U_stop,500} ,{U_stop,500} ,{U_still,500} ,{U_still,500}};
const PROGMEM transition_t U_catch1203_1[] = {{0,7} ,{U_still,500}  ,{U_stop,500}  ,{U_catch_first,500}  ,{U_catch_two,500}  ,{U_catch_three_left,500} ,{U_still,500}  ,{U_stop,500}};
const PROGMEM transition_t U_catch1203_2[] = {{0,6} ,{U_stop,500}  ,{U_catch_first,500},{U_catch_two,500} ,{U_catch_first,500} ,{U_still,500},{U_stop,500}};

//const PROGMEM transition_t D_Walkleftward[] = {{0,9} ,{D_WL_1,15} ,{D_WL_2,100} ,{D_WL_3,40} ,{D_WL_4,100} ,{D_WL_1,40} ,{D_WL_2,100} ,{D_WL_3,40} ,{D_WL_4,100} ,{D_WL_1,15}};
//const PROGMEM transition_t D_Walkrightward[] = {{0,9} ,{D_WR_1,15} ,{D_WR_2,100} ,{D_WR_3,40} ,{D_WR_4,100} ,{D_WR_1,40} ,{D_WR_2,100} ,{D_WR_3,40} ,{D_WR_4,100} ,{D_WR_1,15}};
//const PROGMEM transition_t D_Turnleft[] = {{0,9} ,{D_TL_1,30} ,{D_TL_2,50} ,{D_TL_3,30} ,{D_TL_4,50} ,{D_TL_5,30} ,{D_TL_2,50} ,{D_TL_3,30} ,{D_TL_4,50} ,{D_TL_5,30}};
//const PROGMEM transition_t D_Turnright[] = {{0,9} ,{D_TR_1,30} ,{D_TR_2,50} ,{D_TR_3,30} ,{D_TR_4,50} ,{D_TR_5,30} ,{D_TR_2,50} ,{D_TR_3,30} ,{D_TR_4,50} ,{D_TR_5,30}};
//const PROGMEM transition_t D_FastWalkforward[] = {{0,8} ,{D_Fast_WF_2,60} ,{D_Fast_WF_3,50} ,{D_Fast_WF_4,60} ,{D_Fast_WF_5,50} ,{D_Fast_WF_2,60} ,{D_Fast_WF_3,50} ,{D_Fast_WF_4,60} ,{D_Fast_WF_5,50}};
//const PROGMEM transition_t D_FastWalkbackward[] = {{0,8} ,{D_Fast_WB_2,60} ,{D_Fast_WB_3,50} ,{D_Fast_WB_4,60} ,{D_Fast_WB_5,50} ,{D_Fast_WB_2,60} ,{D_Fast_WB_3,50} ,{D_Fast_WB_4,60} ,{D_Fast_WB_5,50}};
//const PROGMEM transition_t D_FastTurnleft[] = {{0,9} ,{D_Fast_TL_1,50} ,{D_Fast_TL_2,50} ,{D_Fast_TL_3,50} ,{D_Fast_TL_4,50} ,{D_Fast_TL_5,50} ,{D_Fast_TL_2,50} ,{D_Fast_TL_3,50} ,{D_Fast_TL_4,50} ,{D_Fast_TL_5,50}};
//const PROGMEM transition_t D_FastTurnright[] = {{0,9} ,{D_Fast_TR_1,50} ,{D_Fast_TR_2,50} ,{D_Fast_TR_3,50} ,{D_Fast_TR_4,50} ,{D_Fast_TR_5,50} ,{D_Fast_TR_2,50} ,{D_Fast_TR_3,50} ,{D_Fast_TR_4,50} ,{D_Fast_TR_5,50}};
//const PROGMEM transition_t U_forwardall[] = {{0,4} ,{U_forward2,300} ,{U_forward3,300} ,{U_forward4,300} ,{U_forward1,300}};
//const PROGMEM transition_t U_backwardall[] = {{0,4} ,{U_backward2,500} ,{U_backward3,500} ,{U_backward4,500} ,{U_backward5,500}};
//const PROGMEM transition_t U_rightwardall[] = {{0,4} ,{U_rightward1,400} ,{U_rightward2,400} ,{U_rightward3,400} ,{U_rightward4,400}};
//const PROGMEM transition_t U_leftwardall[] = {{0,4} ,{U_leftward1,300} ,{U_leftward2,300} ,{U_leftward3,300} ,{U_leftward4,300}};
//const PROGMEM transition_t U_leftturnall[] = {{0,4} ,{U_leftturn1,300} ,{U_leftturn2,300} ,{U_leftturn3,300} ,{U_leftturn4,300}};
//const PROGMEM transition_t U_rightturnall[] = {{0,4} ,{U_rightturn1,300} ,{U_rightturn2,300} ,{U_rightturn3,300} ,{U_rightturn4,300}};


////==== User Sequence Setup ====////
#define ActionNo_1   U_catch_1
#define ActionNo_2   U_catch_2
#define ActionNo_3   U_stopaction
#define ActionNo_4   U_cok_left
#define ActionNo_5   U_catch1203_1
#define ActionNo_6   U_catch1203_2
#define ActionNo_7   None
#define ActionNo_8   None
#define ActionNo_9   None
#define ActionNo_10   None
#define ActionNo_11   None
#define ActionNo_12   None
#define ActionNo_13   None
#define ActionNo_14   None
#define ActionNo_15   None
#define ActionNo_16   None
#define ActionNo_17   None
#define ActionNo_18   None
#define ActionNo_19   None
#define ActionNo_20   None
#define ActionNo_21   None
#define ActionNo_22   None
#define ActionNo_23   None
#define ActionNo_24   None
#define ActionNo_25   None
#define ActionNo_26   None
#define ActionNo_27   None
#define ActionNo_28   None
#define ActionNo_29   None
#define ActionNo_30   None
#define ActionNo_31   None
#define ActionNo_32   None
#define ActionNo_33   None
#define ActionNo_34   None
#define ActionNo_35   None
#define ActionNo_36   None
#define ActionNo_37   None
#define ActionNo_38   None
#define ActionNo_39   None
#define ActionNo_40   None
#define ActionNo_41   None
#define ActionNo_42   None
#define ActionNo_43   None
#define ActionNo_44   None
#define ActionNo_45   None
#define ActionNo_46   None
#define ActionNo_47   None
#define ActionNo_48   None
#define ActionNo_49   None
#define ActionNo_50   None
#define ActionNo_51   None
#define ActionNo_52   None
#define ActionNo_53   None
#define ActionNo_54   None

////==== Robot Button Control & Remote Control ====////
#define RB_1   1
#define RB_2   2
#define RB_3   3
#define RB_4   1
#define RCU_LJU   16
#define RCU_LJD   17
#define RCU_LJL   18
#define RCU_LJR   19
#define RCU_L1   11
#define RCU_L2   12
#define RCU_L3   14
#define RCU_R1   16
#define RCU_R2   15
#define RCU_R3   13
#define RCU_RJU   7
#define RCU_RJD   8
#define RCU_RJL   9
#define RCU_RJR   10

////==== Music Setup ====////
#define Music_1   "none"
#define Music_2   "none"
#define Music_3   "none"
#define Music_4   "none"
#define Music_5   "none"
#define Music_6   "none"
#define Music_7   "none"
#define Music_8   "none"
#define Music_9   "none"
#define Music_10   "none"
#define Music_11   "none"
#define Music_12   "none"
#define Music_13   "none"
#define Music_14   "none"
#define Music_15   "none"
#define Music_16   "none"
#define Music_17   "none"
#define Music_18   "none"
#define Music_19   "none"
#define Music_20   "none"
#define Music_21   "none"
#define Music_22   "none"
#define Music_23   "none"
#define Music_24   "none"
#define Music_25   "none"
#define Music_26   "none"
#define Music_27   "none"
#define Music_28   "none"
#define Music_29   "none"
#define Music_30   "none"
#define Music_31   "none"
#define Music_32   "none"
#define Music_33   "none"
#define Music_34   "none"
#define Music_35   "none"
#define Music_36   "none"
#define Music_37   "none"
#define Music_38   "none"
#define Music_39   "none"
#define Music_40   "none"
#define Music_41   "none"
#define Music_42   "none"
#define Music_43   "none"
#define Music_44   "none"
#define Music_45   "none"
#define Music_46   "none"
#define Music_47   "none"
#define Music_48   "none"
#define Music_49   "none"
#define Music_50   "none"
#define Music_51   "none"
#define Music_52   "none"
#define Music_53   "none"
#define Music_54   "none"

#endif

