/************************************************
project3:
Ting Gong
November 2, 2019

Global function: readOneInt
Function: read an integer from a file stream 
************************************************/
#include "readOneInt.h"
bool readOneInt(
     ifstream &inFile, 
     int &readedInt,
     string errorPrint
     )
{
    inFile >> readedInt;
    if (inFile.eof())
    {
        cout << "EOF before reading a valid int input!!" << endl;
        return false;
    }
    else if (inFile.fail())
    {
        if (errorPrint != "")
        {
            cout << errorPrint << endl;
        }
        inFile.clear();
        inFile.ignore(200, '\n');
        return false;
    }

    return true;
}