/************************************************
project3:
Ting Gong
November 2, 2019

Global Function: cinOneInt.cpp
Function: prompt to get one valid integer that 
is within a provided range
************************************************/
#ifndef _CINONEINT_
#define _CINONEINT_
#include <iostream>
#include <fstream>
using namespace std;
bool cinOneInt(
    string promptLine, 
    int minValue, 
    int MaxValue,
    string errorPrint,
    int &cinInt
    );
#endif