#ifndef RCK100_USER_MOTION_H
#define RCK100_USER_MOTION_H
#define Adjustment_index true
#define Avoidance_index true
#include <avr/pgmspace.h>
static char Motor_Number = 6;
const PROGMEM uint16_t NonePose[] = {6, 512, 512, 512, 512, 512, 512};
const PROGMEM transition_t None[] = {{0,1} ,{NonePose,400}};

//const PROGMEM uint16_t DefaultPose1[] = {6, 512, 374, 507, 402, 790, 512};
const PROGMEM uint16_t DefaultPose1[] = {Motor_Number, 500, 500, 255, 228, 790, 497}; 
const PROGMEM transition_t DefaultInitial[] = {{0,1}, {DefaultPose1, 1000}};

//===== User Define Pose ======
const PROGMEM uint16_t U_still[] = {6, 500, 500, 255, 228, 790, 497};
const PROGMEM uint16_t U_stop[] = {6, 501, 499, 255, 498, 790, 497};
const PROGMEM uint16_t U_catch_first[] = {6, 639, 382, 255, 519, 699, 655};
const PROGMEM uint16_t U_catch_two[] = {6, 756, 264, 255, 519, 699, 655};
const PROGMEM uint16_t U_catch_three[] = {6, 756, 264, 255, 519, 800, 525};
const PROGMEM uint16_t U_catch_four[] = {6, 347, 686, 255, 607, 800, 546};
const PROGMEM uint16_t U_catch_ok[] = {6, 347, 686, 255, 607, 749, 546};
const PROGMEM uint16_t U_cc_41[] = {6, 756, 264, 255, 256, 699, 655};
const PROGMEM uint16_t U_cc_42[] = {6, 756, 264, 255, 256, 800, 300};

//===== User Define Sequence ======
const PROGMEM transition_t U_catch_1[] = {{0,22} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_catch_three,500} ,{U_catch_three,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_four,500} ,{U_catch_four,500} ,{U_catch_ok,500} ,{U_catch_ok,500} ,{U_stop,500} ,{U_stop,500} ,{U_still,500} ,{U_still,500}};
const PROGMEM transition_t U_catch_2[] = {{0,24} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_cc_41,500} ,{U_cc_41,500} ,{U_cc_42,500} ,{U_cc_42,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_four,500} ,{U_catch_four,500} ,{U_catch_ok,500} ,{U_catch_ok,500} ,{U_stop,500} ,{U_stop,500} ,{U_still,500} ,{U_still,500}};
const PROGMEM transition_t U_catch_3[] = {{0,22} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_catch_three,500} ,{U_catch_three,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500}};
const PROGMEM transition_t U_catch_4[] = {{0,22} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500} ,{U_catch_first,500} ,{U_catch_first,500} ,{U_catch_two,500} ,{U_catch_two,500} ,{U_catch_three,500} ,{U_catch_three,500} ,{U_still,500} ,{U_still,500} ,{U_stop,500} ,{U_stop,500}};
////==== User Sequence Setup ====////
#define ActionNo_1   U_catch_1
#define ActionNo_2   U_catch_2
#define ActionNo_3   U_catch_3
#define ActionNo_4   U_catch_4
#define ActionNo_5   None
#define ActionNo_6   None
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
#define RB_3   0
#define RB_4   0
#define RCU_LJU   0
#define RCU_LJD   0
#define RCU_LJL   0
#define RCU_LJR   0
#define RCU_L1   0
#define RCU_L2   0
#define RCU_L3   0
#define RCU_R1   0
#define RCU_R2   0
#define RCU_R3   0
#define RCU_RJU   0
#define RCU_RJD   0
#define RCU_RJL   0
#define RCU_RJR   0

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

