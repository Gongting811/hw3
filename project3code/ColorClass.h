/************************************************
project3:
Ting Gong
November 2, 2019

Class: ColorClass.h
Function: Enable reading, editing, and writing 
the class of color pixels
************************************************/
#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <fstream>
#include "constants.h"

class ColorClass
{
private:
    int red;
    int green;
    int blue;
    bool clip(
         int &color
         );
public:
    ColorClass(
    int inRed=FULL_COLOR,
    int inGreen=FULL_COLOR,
    int inBlue=FULL_COLOR
    );
    // set ColorClass to black
    void setToBlack();

    // set ColorClass to red
    void setToRed();

    // set ColorClass to green
    void setToGreen();

    // set ColorClass to blue
    void setToBlue();

    // set ColorClass to white
    void setToWhite();

    // set ColorClass to input values
    bool setTo(
         int inRed,
         int inGreen,
         int inBlue
         );

    // set ColorClass to the input ColorClass
    bool setTo(
         ColorClass &inColor
         );

    // add ColorClass by the input ColorClass
    bool addColor(
         ColorClass &rhs
         );

    // substract ColorClass by the input ColorClass
    bool subtractColor(
         ColorClass &rhs
         );

    // adjust ColorClass by the input ratio
    bool adjustBrightness(
         double adjFactor
         );

    // print ColorClass
    void printComponentValues();

    // read color from file stream
    int readColor(
         ifstream &inFile
         );

    // write color to file stream
    void writeColor(
         ofstream &outFile
         );

    // judge whether the color is identical to the rhsColor
    bool isEqual(
         ColorClass &rhsColor
         );
};

#endif