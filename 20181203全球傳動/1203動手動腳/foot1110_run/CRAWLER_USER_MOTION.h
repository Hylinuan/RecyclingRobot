#ifndef CRAWLER_USER_MOTION_H
#define CRAWLER_USER_MOTION_H
#include <avr/pgmspace.h>
#define Adjustment_index false
#define Avoidance_index false

//===== User Default Sequence ======
const PROGMEM uint16_t DefaultPose[] = {18, 367, 512, 512, 512, 512, 512, 657, 512, 512, 657, 512, 512, 512, 512, 512, 367, 512, 512};
const PROGMEM transition_t DefaultInitial[] = {{0,1} ,{DefaultPose,500}};
const PROGMEM uint16_t NonePose[] = {18, 367, 512, 512, 512, 512, 512, 657, 512, 512, 657, 512, 512, 512, 512, 512, 367, 512, 512};
const PROGMEM transition_t None[] = {{0,1} ,{NonePose,500}};

//===== User Define Pose ======
const PROGMEM uint16_t D_WF_4[] = {18, 410, 408, 420, 410, 230, 420, 614, 408, 420, 716, 793, 604, 472, 616, 604, 512, 793, 604};
const PROGMEM uint16_t D_WF_5[] = {18, 410, 408, 420, 410, 408, 420, 614, 408, 420, 716, 616, 604, 472, 616, 604, 512, 616, 604};
const PROGMEM uint16_t D_WF_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WF_2[] = {18, 288, 230, 420, 512, 408, 420, 492, 230, 420, 614, 616, 604, 594, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_WF_3[] = {18, 288, 408, 420, 512, 408, 420, 492, 408, 420, 614, 616, 604, 594, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WB_2[] = {18, 455, 230, 420, 452, 408, 420, 670, 230, 420, 674, 616, 604, 477, 793, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_3[] = {18, 455, 408, 420, 452, 408, 420, 670, 408, 420, 674, 616, 604, 477, 616, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_1[] = {18, 350, 408, 420, 452, 408, 420, 584, 408, 420, 674, 616, 604, 572, 616, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_4[] = {18, 350, 408, 420, 552, 230, 420, 584, 408, 420, 574, 793, 604, 572, 616, 604, 360, 793, 604};
const PROGMEM uint16_t D_WB_5[] = {18, 350, 408, 420, 552, 408, 420, 584, 408, 420, 574, 616, 604, 572, 616, 604, 360, 616, 604};
const PROGMEM uint16_t D_WL_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WL_2[] = {18, 410, 230, 420, 512, 408, 420, 614, 230, 420, 614, 616, 604, 512, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_WL_3[] = {18, 410, 459, 574, 510, 470, 340, 613, 459, 574, 612, 565, 450, 510, 554, 684, 410, 565, 450};
const PROGMEM uint16_t D_WL_4[] = {18, 410, 408, 420, 512, 230, 420, 613, 408, 420, 614, 793, 604, 506, 616, 604, 409, 791, 604};
const PROGMEM uint16_t D_WR_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WR_2[] = {18, 410, 408, 420, 512, 230, 420, 614, 408, 420, 614, 793, 604, 512, 616, 604, 410, 793, 604};
const PROGMEM uint16_t D_WR_3[] = {18, 410, 459, 574, 510, 470, 340, 614, 459, 574, 614, 565, 450, 512, 554, 684, 410, 565, 450};
const PROGMEM uint16_t D_WR_4[] = {18, 410, 230, 420, 512, 408, 420, 614, 230, 420, 614, 616, 604, 512, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_2[] = {18, 512, 230, 420, 512, 408, 420, 716, 230, 420, 614, 616, 604, 614, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_3[] = {18, 512, 408, 420, 512, 408, 420, 716, 408, 420, 614, 616, 604, 614, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_4[] = {18, 410, 408, 420, 614, 230, 420, 614, 408, 420, 716, 793, 604, 512, 616, 604, 512, 793, 604};
const PROGMEM uint16_t D_TL_5[] = {18, 410, 408, 420, 614, 408, 420, 614, 408, 420, 716, 616, 604, 512, 616, 604, 512, 616, 604};
const PROGMEM uint16_t D_TR_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TR_2[] = {18, 410, 408, 420, 410, 230, 420, 614, 408, 420, 512, 793, 604, 512, 616, 604, 308, 793, 604};
const PROGMEM uint16_t D_TR_3[] = {18, 410, 408, 420, 410, 408, 420, 614, 408, 420, 512, 616, 604, 512, 616, 604, 308, 616, 604};
const PROGMEM uint16_t D_TR_4[] = {18, 308, 230, 420, 512, 408, 420, 512, 230, 420, 614, 616, 604, 410, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_TR_5[] = {18, 308, 408, 420, 512, 408, 420, 512, 408, 422, 614, 616, 604, 410, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_Fast_WF_2[] = {18, 362, 250, 320, 442, 290, 290, 462, 250, 320, 612, 734, 734, 612, 774, 704, 512, 734, 734};
const PROGMEM uint16_t D_Fast_WF_3[] = {18, 362, 325, 373, 442, 290, 290, 462, 290, 290, 612, 734, 734, 612, 734, 734, 512, 734, 734};
const PROGMEM uint16_t D_Fast_WF_4[] = {18, 412, 290, 290, 412, 250, 320, 512, 290, 290, 662, 774, 704, 582, 734, 734, 562, 774, 704};
const PROGMEM uint16_t D_Fast_WF_5[] = {18, 412, 290, 290, 412, 290, 290, 512, 290, 290, 662, 699, 654, 582, 734, 734, 562, 734, 734};
const PROGMEM uint16_t D_Fast_WB_2[] = {18, 432, 252, 318, 453, 278, 295, 592, 252, 319, 661, 743, 726, 512, 774, 705, 512, 742, 735};
const PROGMEM uint16_t D_Fast_WB_3[] = {18, 433, 283, 291, 458, 284, 294, 583, 282, 292, 659, 744, 725, 516, 737, 732, 505, 743, 723};
const PROGMEM uint16_t D_Fast_WB_4[] = {18, 375, 280, 297, 512, 254, 318, 525, 280, 288, 592, 769, 706, 603, 744, 729, 433, 769, 706};
const PROGMEM uint16_t D_Fast_WB_5[] = {18, 373, 279, 298, 512, 278, 302, 526, 279, 288, 593, 753, 717, 603, 745, 731, 433, 743, 721};
const PROGMEM uint16_t D_Fast_TL_1[] = {18, 362, 290, 290, 452, 290, 290, 562, 290, 290, 662, 734, 734, 572, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TL_2[] = {18, 362, 290, 290, 522, 200, 320, 562, 287, 299, 712, 824, 704, 574, 733, 733, 552, 824, 704};
const PROGMEM uint16_t D_Fast_TL_3[] = {18, 362, 290, 290, 522, 290, 290, 562, 290, 290, 712, 734, 734, 574, 734, 734, 552, 734, 734};
const PROGMEM uint16_t D_Fast_TL_4[] = {18, 412, 200, 320, 452, 290, 290, 602, 200, 320, 662, 734, 734, 642, 824, 704, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TL_5[] = {18, 412, 290, 290, 452, 290, 290, 602, 290, 290, 662, 734, 734, 639, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_1[] = {18, 362, 290, 290, 452, 290, 290, 562, 290, 290, 662, 734, 734, 572, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_2[] = {18, 312, 200, 320, 452, 290, 290, 522, 200, 320, 662, 734, 734, 502, 824, 704, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_3[] = {18, 312, 290, 290, 452, 290, 290, 522, 290, 290, 662, 734, 734, 502, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_4[] = {18, 362, 290, 290, 382, 200, 320, 562, 290, 290, 612, 824, 704, 572, 734, 734, 352, 824, 704};
const PROGMEM uint16_t D_Fast_TR_5[] = {18, 362, 290, 290, 382, 290, 290, 562, 290, 290, 612, 734, 734, 572, 734, 734, 352, 734, 734};
const PROGMEM uint16_t U_forward2[] = {18, 288, 230, 420, 512, 408, 420, 554, 230, 392, 617, 616, 604, 590, 800, 604, 410, 616, 604};//腳1.3.5:A向前 B抬高 C不動;腳2.4.6:A不動 B不動 C不動
const PROGMEM uint16_t U_forward3[] = {18, 288, 408, 420, 512, 408, 420, 600, 408, 420, 604, 616, 604, 550, 616, 604, 410, 616, 604};//腳1.3.5:A不動 B放低 C不動;腳2.4.6:A不動 B不動 C不動
const PROGMEM uint16_t U_forward4[] = {18, 410, 408, 420, 436, 230, 420, 614, 408, 420, 708, 701, 510, 550, 575, 575, 512, 793, 604};//腳1.3.5:A向後 B抬高 C不動;腳2.4.6:A向前 B抬高 C不動
const PROGMEM uint16_t U_forward1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 711, 601, 607, 512, 588, 604, 410, 579, 604};//腳1.3.5:A不動 B不動 C不動;腳2.4.6:A向前 B放低 C不動
const PROGMEM uint16_t U_backward2[] = {18, 455, 230, 420, 452, 408, 420, 670, 230, 420, 674, 580, 585, 477, 793, 604, 440, 570, 604};//腳1.3.5:A向後 B抬高 C不動;腳2.4.6:A不動 B不動 C不動
const PROGMEM uint16_t U_backward3[] = {18, 455, 437, 420, 452, 453, 465, 670, 480, 456, 674, 616, 604, 477, 597, 604, 440, 570, 604};//腳1.3.5:A不動 B放低 C不動;腳2.4.6:A不動 B不動 C不動
const PROGMEM uint16_t U_backward4[] = {18, 350, 408, 392, 552, 230, 420, 584, 408, 420, 574, 793, 604, 517, 616, 604, 360, 793, 604};//腳1.3.5:A向前 B不動 C不動;腳2.4.6:A向後 B抬高 C不動
const PROGMEM uint16_t U_backward5[] = {18, 350, 408, 420, 552, 435, 447, 584, 462, 420, 574, 616, 604, 572, 616, 604, 360, 588, 604};//腳1.3.5:A不動 B不動 C不動;腳2.4.6:A不動 B放低 C不動
const PROGMEM uint16_t U_rightward1[] = {18, 410, 408, 420, 512, 182, 420, 614, 408, 420, 614, 794, 604, 512, 515, 531, 410, 794, 604};//腳1.3.5:A不動 B不動 C不動;腳2.4.6:A不動 B抬高 C不動
const PROGMEM uint16_t U_rightward2[] = {18, 410, 479, 483, 512, 479, 483, 614, 479, 420, 614, 514, 439, 512, 532, 576, 410, 514, 439};//腳1.3:A不動 B不動 C不動;腳2.4.6:A不動 B抬高 C向外;腳5:A不動 B抬高 C向內
const PROGMEM uint16_t U_rightward3[] = {18, 410, 271, 574, 512, 479, 574, 614, 271, 574, 614, 515, 530, 512, 677, 530, 410, 515, 530};//腳1.3.5:A不動 B抬高 C不動;腳4.6:A不動 B不動 C向內;腳2:A不動 B抬高 C向外
const PROGMEM uint16_t U_rightward4[] = {18, 410, 469, 420, 512, 479, 420, 614, 469, 574, 614, 515, 530, 512, 480, 402, 410, 515, 530};//腳1.3:A不動 B抬高 C往內;腳2.5:A不動 B抬高 C向外;腳4.6:A不動 B抬高 C向內
const PROGMEM uint16_t U_leftward1[] = {18, 410, 408, 347, 512, 182, 347, 614, 408, 420, 614, 794, 604, 512, 616, 604, 410, 794, 604};//腳1.3:A不動 B不動 C往內;腳2.4.6:A不動 B抬高 C不動;腳5:A不動 B不動 C不動
const PROGMEM uint16_t U_leftward2[] = {18, 410, 435, 420, 512, 480, 420, 614, 435, 573, 614, 541, 639, 512, 579, 604, 410, 541, 639};//腳1.3:A不動 B不動 C往外;腳2:A不動 B放低 C往外;腳5:A不動 B抬高 C不動;腳4.6:A不動 B放低 C往內
const PROGMEM uint16_t U_leftward3[] = {18, 410, 299, 420, 512, 480, 420, 614, 263, 420, 614, 512, 512, 512, 685, 639, 410, 512, 512};//腳1.3:A不動 B抬高 C往外;腳2:A不動 B不動 C往內;腳5:A不動 B抬高 C不動;腳4.6:A不動 B不動 C往外
const PROGMEM uint16_t U_leftward4[] = {18, 410, 506, 546, 512, 480, 599, 614, 506, 420, 614, 512, 512, 512, 449, 584, 410, 512, 512};//腳1.3:A不動 B放低 C往外;腳2:A不動 B不動 C不動;腳5:A不動 B放低 C往內;腳4.6:A不動 B不動 C不動
const PROGMEM uint16_t U_leftturn1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};//腳1.2.3.4.5.6:A不動 B抬高 C往外(全部伏低)
const PROGMEM uint16_t U_leftturn2[] = {18, 473, 230, 420, 512, 408, 420, 641, 230, 420, 614, 616, 604, 593, 793, 604, 410, 616, 604};//腳1.3:A向後 B抬高 C不動;腳2.4.6:A不動 B不動 C不動;腳5:A往前 B抬高 C不動
const PROGMEM uint16_t U_leftturn3[] = {18, 410, 495, 510, 510, 488, 484, 613, 504, 501, 612, 565, 576, 510, 554, 557, 410, 537, 513};//腳1.3:A向前 B放低 C不動;腳2.4.6:A不動 B不動 C不動;腳5:A往後 B放低 C不動(跟leftturn1一樣的動作)
const PROGMEM uint16_t U_leftturn4[] = {18, 410, 408, 420, 566, 230, 420, 613, 408, 420, 740, 793, 604, 506, 616, 604, 472, 791, 604};//腳1.3.5:A不動 B不動 C不動;腳2:A往後 B抬高 C不動;腳4.6:A往前 B抬高 C不動
const PROGMEM uint16_t U_rightturn1[] = {18, 410, 408, 420, 512, 408, 420, 657, 408, 420, 614, 616, 604, 512, 616, 604, 367, 616, 604};//腳1.2.3.4.5.6:A不動 B抬高 C往外(全部伏低)
const PROGMEM uint16_t U_rightturn2[] = {18, 292, 281, 420, 512, 408, 420, 575, 281, 420, 614, 616, 604, 400, 742, 604, 367, 616, 604};//腳1.3:A往前 B抬高 C不動;腳2.4.6:A不動 B不動 C不動;腳5:A往後 B抬高 C不動
const PROGMEM uint16_t U_rightturn3[] = {18, 410, 495, 510, 510, 488, 484, 613, 504, 501, 612, 565, 576, 510, 554, 557, 410, 537, 513};//腳1.3:A往後 B放低 C不動;腳2.4.6:A不動 B不動 C不動;腳5:A往前 B放低 C不動(跟rightturn1一樣的動作)
const PROGMEM uint16_t U_rightturn4[] = {18, 410, 408, 420, 448, 299, 420, 657, 408, 420, 505, 740, 604, 512, 616, 604, 276, 740, 604};//腳1.3.5:A不動 B不動 C不動;腳2:A往前 B抬高 C不動;腳4.6:A往後 B抬高 C不動
const PROGMEM uint16_t U_origin[] = {18, 367, 512, 512, 512, 512, 512, 647, 539, 512, 657, 528, 529, 512, 512, 512, 367, 512, 512};
//const PROGMEM uint16_t U_down[] = {18, 410, 408, 420, 448, 299, 420, 657, 408, 420, 505, 740, 604, 512, 616, 604, 276, 740, 604};

//===== User Define Sequence ======
const PROGMEM transition_t D_Walkforward[] = {{0,12} ,{D_WF_4,100} ,{D_WF_5,50} ,{D_WF_1,10} ,{D_WF_2,100} ,{D_WF_3,50} ,{D_WF_1,10} ,{D_WF_4,100} ,{D_WF_5,50} ,{D_WF_1,10} ,{D_WF_2,100} ,{D_WF_3,50} ,{D_WF_1,10}};
const PROGMEM transition_t D_Walkbackward[] = {{0,12} ,{D_WB_2,100} ,{D_WB_3,50} ,{D_WB_1,10} ,{D_WB_4,100} ,{D_WB_5,50} ,{D_WB_1,10} ,{D_WB_2,100} ,{D_WB_3,50} ,{D_WB_1,10} ,{D_WB_4,100} ,{D_WB_5,50} ,{D_WB_1,10}};
const PROGMEM transition_t D_Walkleftward[] = {{0,9} ,{D_WL_1,15} ,{D_WL_2,100} ,{D_WL_3,40} ,{D_WL_4,100} ,{D_WL_1,40} ,{D_WL_2,100} ,{D_WL_3,40} ,{D_WL_4,100} ,{D_WL_1,15}};
const PROGMEM transition_t D_Walkrightward[] = {{0,9} ,{D_WR_1,15} ,{D_WR_2,100} ,{D_WR_3,40} ,{D_WR_4,100} ,{D_WR_1,40} ,{D_WR_2,100} ,{D_WR_3,40} ,{D_WR_4,100} ,{D_WR_1,15}};
const PROGMEM transition_t D_Turnleft[] = {{0,9} ,{D_TL_1,30} ,{D_TL_2,50} ,{D_TL_3,30} ,{D_TL_4,50} ,{D_TL_5,30} ,{D_TL_2,50} ,{D_TL_3,30} ,{D_TL_4,50} ,{D_TL_5,30}};
const PROGMEM transition_t D_Turnright[] = {{0,9} ,{D_TR_1,30} ,{D_TR_2,50} ,{D_TR_3,30} ,{D_TR_4,50} ,{D_TR_5,30} ,{D_TR_2,50} ,{D_TR_3,30} ,{D_TR_4,50} ,{D_TR_5,30}};
const PROGMEM transition_t D_FastWalkforward[] = {{0,8} ,{D_Fast_WF_2,60} ,{D_Fast_WF_3,50} ,{D_Fast_WF_4,60} ,{D_Fast_WF_5,50} ,{D_Fast_WF_2,60} ,{D_Fast_WF_3,50} ,{D_Fast_WF_4,60} ,{D_Fast_WF_5,50}};
const PROGMEM transition_t D_FastWalkbackward[] = {{0,8} ,{D_Fast_WB_2,60} ,{D_Fast_WB_3,50} ,{D_Fast_WB_4,60} ,{D_Fast_WB_5,50} ,{D_Fast_WB_2,60} ,{D_Fast_WB_3,50} ,{D_Fast_WB_4,60} ,{D_Fast_WB_5,50}};
const PROGMEM transition_t D_FastTurnleft[] = {{0,9} ,{D_Fast_TL_1,50} ,{D_Fast_TL_2,50} ,{D_Fast_TL_3,50} ,{D_Fast_TL_4,50} ,{D_Fast_TL_5,50} ,{D_Fast_TL_2,50} ,{D_Fast_TL_3,50} ,{D_Fast_TL_4,50} ,{D_Fast_TL_5,50}};
const PROGMEM transition_t D_FastTurnright[] = {{0,9} ,{D_Fast_TR_1,50} ,{D_Fast_TR_2,50} ,{D_Fast_TR_3,50} ,{D_Fast_TR_4,50} ,{D_Fast_TR_5,50} ,{D_Fast_TR_2,50} ,{D_Fast_TR_3,50} ,{D_Fast_TR_4,50} ,{D_Fast_TR_5,50}};
const PROGMEM transition_t U_forwardall[] = {{0,4} ,{U_forward2,300} ,{U_forward3,300} ,{U_forward4,300} ,{U_forward1,300}};
const PROGMEM transition_t U_backwardall[] = {{0,4} ,{U_backward2,500} ,{U_backward3,500} ,{U_backward4,500} ,{U_backward5,500}};
const PROGMEM transition_t U_rightwardall[] = {{0,4} ,{U_rightward1,400} ,{U_rightward2,400} ,{U_rightward3,400} ,{U_rightward4,400}};
const PROGMEM transition_t U_leftwardall[] = {{0,4} ,{U_leftward1,300} ,{U_leftward2,300} ,{U_leftward3,300} ,{U_leftward4,300}};
const PROGMEM transition_t U_leftturnall[] = {{0,4} ,{U_leftturn1,300} ,{U_leftturn2,300} ,{U_leftturn3,300} ,{U_leftturn4,300}};
const PROGMEM transition_t U_rightturnall[] = {{0,4} ,{U_rightturn1,300} ,{U_rightturn2,300} ,{U_rightturn3,300} ,{U_rightturn4,300}};
const PROGMEM transition_t U_originall[] = {{0,1} ,{U_origin,100}};
const PROGMEM transition_t U_downstopcatch[] = {{0,1} ,{D_Fast_WF_2,100}};


////==== User Sequence Setup ====////
#define ActionNo_1   D_Walkforward
#define ActionNo_2   D_Walkbackward
#define ActionNo_3   D_Walkleftward
#define ActionNo_4   D_Walkrightward
#define ActionNo_5   D_Turnleft
#define ActionNo_6   D_Turnright
#define ActionNo_7   D_FastWalkforward
#define ActionNo_8   D_FastWalkbackward
#define ActionNo_9   D_FastTurnleft
#define ActionNo_10   D_FastTurnright
#define ActionNo_11   U_forwardall
#define ActionNo_12   U_backwardall
#define ActionNo_13   U_rightwardall
#define ActionNo_14   U_leftwardall
#define ActionNo_15   U_leftturnall
#define ActionNo_16   U_rightturnall
#define ActionNo_17   U_originall
#define ActionNo_18   U_downstopcatch
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
#define RB_1   39
#define RB_2   41
#define RB_3   40
#define RB_4   42
#define RCU_LJU   1
#define RCU_LJD   2
#define RCU_LJL   3
#define RCU_LJR   4
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

