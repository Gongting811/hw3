/************************************************
project3:
Ting Gong
November 2, 2019

Global function: readOneInt
Function: read an integer from a file stream 
************************************************/
#ifndef _READONEINT_
#define _READONEINT_
#include <iostream>
#include <fstream>
using namespace std;
bool readOneInt(
     ifstream &inFile, 
     int &readedInt,
     string errorPring
     );

#endif