/************************************************
project3:
Ting Gong
November 2, 2019

Class: ColorClass.cpp
Function: Enable reading, editing, and writing 
the class of color pixels
************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#include "ColorClass.h"
#include "constants.h"
#include "readOneInt.h"

ColorClass::ColorClass(
     int inRed,
     int inGreen,
     int inBlue
     )
{
    red = inRed;
    clip(red);
    green = inGreen;
    clip(green);
    blue = inBlue;
    clip(blue);
};

// set ColorClass to black
void ColorClass::setToBlack()
{
    red = ZERO_COLOR;
    green = ZERO_COLOR;
    blue = ZERO_COLOR;
}

// set ColorClass to red
void ColorClass::setToRed()
{
    red = FULL_COLOR;
    green = ZERO_COLOR;
    blue = ZERO_COLOR;
}

// set ColorClass to green
void ColorClass::setToGreen()
{
    red = ZERO_COLOR;
    green = FULL_COLOR;
    blue = ZERO_COLOR;
}

// set ColorClass to blue
void ColorClass::setToBlue()
{
    red = ZERO_COLOR;
    green = ZERO_COLOR;
    blue = FULL_COLOR;
}

// set ColorClass to white
void ColorClass::setToWhite()
{
    red = FULL_COLOR;
    green = FULL_COLOR;
    blue = FULL_COLOR;
}

// set ColorClass to input values
bool ColorClass::setTo(
     int inRed,
     int inGreen,
     int inBlue
     )
{
    bool result = false;
    red = inRed;
    bool flag = false;
    flag = clip(red);
    if (flag)
    {
        result = true;
    }

    green = inGreen;
    flag = clip(green);
    if (flag)
    {
        result = true;
    }

    blue = inBlue;
    flag = clip(blue);
    if (flag)
    {
        result = true;
    }
    return result;
}

// set ColorClass to the input ColorClass
bool ColorClass::setTo(
     ColorClass &inColor
     )
{
    red = inColor.red;
    green = inColor.green;
    blue = inColor.blue;
    return false;
}

// add ColorClass by the input ColorClass
bool ColorClass::addColor(
     ColorClass &rhs
     )
{
    int red_ = red + rhs.red;
    int green_ = green + rhs.green;
    int blue_ = blue + rhs.blue;
    return setTo(red_, green_, blue_);
}

// substract ColorClass by the input ColorClass
bool ColorClass::subtractColor(
     ColorClass &rhs
     )
{
    int red_ = red - rhs.red;
    int green_ = green - rhs.green;
    int blue_ = blue - rhs.blue;
    return setTo(red_, green_, blue_);
}

// adjust ColorClass by the input ratio
bool ColorClass::adjustBrightness(
     double adjFactor
     )
{
    int red_ = int(red * adjFactor);
    int green_ = int(green * adjFactor);
    int blue_ = int(blue * adjFactor);
    return setTo(red_, green_, blue_);
}

// print ColorClass
void ColorClass::printComponentValues()
{
    cout << "R: " << red << " G: " << green << " B: " << blue;
}

bool ColorClass::clip(
     int &color
     )
{
  //color value less than the ZERO_COLOR will be clipped to the ZERO_COLOR
    bool clipFlag = false;
    if (color < ZERO_COLOR)
    {
        color = ZERO_COLOR;
        clipFlag = true;
    }
    //color value less than the FULL_COLOR will be clipped to the FULL_COLOR
    if (color > FULL_COLOR)
    {
        color = FULL_COLOR;
        clipFlag = true;
    }
    return clipFlag;
}

int ColorClass::readColor(
     ifstream &inFile
     )
{
    bool readFlag;
    string errorPring = "";
    readFlag = readOneInt(inFile, red, errorPring);
    if (!readFlag)
    {
        return ERROR_READ_RED;
    }
    clip(red);

    readFlag = readOneInt(inFile, green, errorPring);
    if (!readFlag)
    {
        return ERROR_READ_GREEN;
    }
    clip(green);

    readFlag = readOneInt(inFile, blue, errorPring);
    if (!readFlag)
    {
        return ERROR_READ_BLUE;
    }
    clip(blue);

    return ERROR_READ_SUCCESS;

}

void ColorClass::writeColor(
     ofstream &outFile
     )
{
    outFile << red << " " << green << " " << blue << " ";
}

bool ColorClass::isEqual(
     ColorClass &rhsColor
     )
{
    return (rhsColor.red == red) && (rhsColor.green == green) &&
        (rhsColor.blue == blue);
}
