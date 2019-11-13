/************************************************
project3:
Ting Gong
November 2, 2019

Global Function: cinTwoInt
Function: prompt to get two valid integers that 
are within a provided range
************************************************/
#ifndef _CINTWOINT_
#define _CINTWOINT_ 
bool cinTwoInt(
     string promptLine, 
     int maxValu, 
     int minValue, 
     string errorPrint,
     int &cinInt1,
     int &cinInt2
     );
#endif