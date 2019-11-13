/************************************************
project3:
Ting Gong
November 2, 2019

Global Function: cinTwoInt
Function: prompt to get two valid integers that 
are within a provided range
************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#include "cinTwoInt.h"
bool cinTwoInt(
     string promptLine, 
     int minValue, 
     int maxValue, 
     string errorPrint,
     int &cinInt1,
     int &cinInt2
     )
{
    cout << promptLine;
    cin >> cinInt1;
    if (cin.fail() || cinInt1 < minValue || cinInt1 > maxValue)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << errorPrint << endl;
        cout << "The invalid input is the first input: " << cinInt1 << endl;
        return false;

    }
    cin >> cinInt2;
    if (cin.fail() || cinInt2 < minValue || cinInt2 > maxValue)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << errorPrint << endl;
        cout << "The invalid input is the second input: " << cinInt2 << endl;
        return false;
    }
    return true;
}
