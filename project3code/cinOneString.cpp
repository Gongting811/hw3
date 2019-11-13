/************************************************
project3:
Ting Gong
November 2, 2019

Global Function: cinOneString
Function: prompt to get one valid string 
************************************************/
#include "cinOneString.h"
bool cinOneString(
    string promptLine,
    string &cinString
    )
{
    bool flag;
    flag = false;
    cout << promptLine;
    cin >> cinString;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Invalid input: " << cinString << endl;
    }
    else 
    {
        flag = true;
    }
    return flag;
}