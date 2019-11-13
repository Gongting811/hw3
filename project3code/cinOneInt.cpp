/************************************************
project3:
Ting Gong
November 2, 2019

Global Function: cinOneInt.cpp
Function: prompt to get one valid integer that 
is within a provided range
************************************************/
#include "cinOneInt.h"
#include "constants.h"
bool cinOneInt(
    string promptLine, 
    int minValue, 
    int MaxValue,
    string errorPrint,
    int &cinInt
    )
{
    bool flag;
    flag = false;
    cout << promptLine;
    cin >> cinInt;
    if (cin.fail() || cinInt < minValue || cinInt > MaxValue)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << errorPrint << endl;
        cout << "The invalid input is: " << cinInt << endl;
    }
    else 
    {
        flag = true;
    }
    return flag;
}