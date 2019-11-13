/************************************************
project3:
Ting Gong
November 2, 2019

Class: Rectangle.cpp
Function: Implementation of class rectangle
that can read and create a rectangle to be added 
in an image 
************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#include "constants.h"
#include "Rectangle.h"
#include "cinOneInt.h"
#include "cinTwoInt.h"

Rectangle::Rectangle()
{
    upperLeft.setRowCol(DEFAULT_RECTANGLE_UPPERLEFT_ROW,
                        DEFAULT_RECTANGLE_UPPERLEFT_COL);
    width = DEFAULT_RECTANGLE_WIDTH;
    height = DEFAULT_RECTANGLE_HEIGHT;
    choiceRec = SPECIFYING_RECTANGLE_DEFAULT;
    recColor = REC_COLOR_DEFAULT;
    fillOption = FILL_OPTION_DEFAULT;
}
Rectangle::~Rectangle()
{
}
bool Rectangle::createRectangle()
{
    bool readFlag = false;
    readFlag = choosingSpecifying();
    if (!readFlag)
    {
        upperLeft.setRowCol(DEFAULT_RECTANGLE_UPPERLEFT_ROW,
                            DEFAULT_RECTANGLE_UPPERLEFT_COL);
        width = DEFAULT_RECTANGLE_WIDTH;
        height = DEFAULT_RECTANGLE_HEIGHT;
        choiceRec = SPECIFYING_RECTANGLE_DEFAULT;
        return false;
    }
    readFlag = chooseingColor();
    if (!readFlag)
    {
        upperLeft.setRowCol(DEFAULT_RECTANGLE_UPPERLEFT_ROW,
                            DEFAULT_RECTANGLE_UPPERLEFT_COL);
        width = DEFAULT_RECTANGLE_WIDTH;
        height = DEFAULT_RECTANGLE_HEIGHT;
        choiceRec = SPECIFYING_RECTANGLE_DEFAULT;
        recColor = REC_COLOR_DEFAULT;
        return false;
    }
    readFlag = choosingFillOption();
    if (!readFlag)
    {
        upperLeft.setRowCol(DEFAULT_RECTANGLE_UPPERLEFT_ROW,
                            DEFAULT_RECTANGLE_UPPERLEFT_COL);
        width = DEFAULT_RECTANGLE_WIDTH;
        height = DEFAULT_RECTANGLE_HEIGHT;
        choiceRec = SPECIFYING_RECTANGLE_DEFAULT;
        recColor = REC_COLOR_DEFAULT;
        fillOption = FILL_OPTION_DEFAULT;
        return false;
    }
    return true;
}
bool Rectangle::choosingSpecifying()
{   
    int upperLeftRow;
    int upperLeftCol;
    bool readFlag = false;
    string promptLine = "1. Specify upper left and lower right corners of " \
                         "rectangle\n2. Specify upper left corner and " \
                         "dimensions of rectangle\n3. Specify extent from " \
                         "center of rectangle\nEnter int for rectangle " \
                         "specification method: ";
    string errorPrint = "Invalid input for rectangle specification method!!";
    readFlag = cinOneInt(promptLine, SPECIFYING_RECTANGLE_ONE,
                          SPECIFYING_RECTANGLE_THREE, errorPrint, choiceRec);
    if (!readFlag)
    {
        return false;
    }
    if (choiceRec == SPECIFYING_RECTANGLE_DEFAULT)
    {
        cout << "Error when creating rectangle: there is no rectangle \
                specifying method specified!!" << endl;
        return false;
    }

    if (choiceRec == SPECIFYING_RECTANGLE_ONE)
    {
        int lowerRightCol;
        int lowerRightRow;

        promptLine = "Enter upper left corner row and column: ";
        errorPrint = "Invalid input for upper left corner row and column!!";
        readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             upperLeftRow, upperLeftCol);
        if (!readFlag)
        {
            return false;
        }
        upperLeft.setRowCol(upperLeftRow, upperLeftCol);

        promptLine = "Enter lower right corner row and column: ";
        errorPrint = "Invalid input for lower right corner row and column!!";
        readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             lowerRightRow, lowerRightCol);
        if (!readFlag)
        {
            return false;
        }

        height = lowerRightRow - upperLeftRow;
        width = lowerRightCol - upperLeftCol;
    }
    else if (choiceRec == SPECIFYING_RECTANGLE_TWO)
    {
        promptLine = "Enter upper left corner row and column: ";
        errorPrint = "Invalid input for upper left corner row and column!!";
        readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             upperLeftRow, upperLeftCol);
        if (!readFlag)
        {
            return false;
        }
        upperLeft.setRowCol(upperLeftRow, upperLeftCol);

        promptLine = "Enter int for number of rows: ";
        errorPrint = "Invalid input for number of rows in specification " \
                     "method 3!!";
        readFlag = cinOneInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             height);
        if (!readFlag)
        {
            return false;
        }
        promptLine = "Enter int for number of columns: ";
        errorPrint = "Invalid input for number of columns in specification " \
                     "method 3!!";
        readFlag = cinOneInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             width);
        if (!readFlag)
        {
            return false;
        }
    }
    else if (choiceRec == SPECIFYING_RECTANGLE_THREE)
    {
        promptLine = "Enter rectangle center row and column: ";
        errorPrint = "Invalid input for rectangle center in specification " \
                     "method 3!!";
        readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             upperLeftRow, upperLeftCol);
        if (!readFlag)
        {
            return false;
        }
        promptLine = "Enter int for half number of rows: ";
        errorPrint = "Invalid input for half number of rows in specification " \
                     "method 3!!";
        readFlag = cinOneInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             height);
        if (!readFlag)
        {
            return false;
        }
        promptLine = "Enter int for half number of columns: ";
        errorPrint = "Invalid input for half number of columns in " \
                     "specification method 3!!";
        readFlag = cinOneInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                             width);
        if (!readFlag)
        {
            return false;
        }

        upperLeftCol -= width; 
        upperLeftRow -= height;
        width *= 2;
        height *= 2;
        upperLeft.setRowCol(upperLeftRow, upperLeftCol);
    }
    return true;
}
bool Rectangle::chooseingColor()
{
    bool readFlag = false;
    string promptLine = "1. Red\n2. Green\n3. Blue\n4. Black\n5. White\n" \
                        "Enter int for rectangle color: ";
    string errorPrint = "Invalid input when choosing the color of rectangle!!";
    
    readFlag = cinOneInt(promptLine, REC_COLOR_RED, REC_COLOR_WHITE,
                         errorPrint, recColor);
    if (!readFlag)
    {
        return false;
    }
    return true;

}
bool Rectangle::choosingFillOption()
{
    bool readFlag = false;
    string promptLine = "1. No\n2. Yes\nEnter int for rectangle fill option: ";
    string errorPrint = "Invalid input when choosing the fill option of " \
                        "rectangle!!";
    
    readFlag = cinOneInt(promptLine, FILL_OPTION_ONE, FILL_OPTION_TWO,
                           errorPrint, fillOption);
    if (!readFlag)
    {
        return false;
    }
    return true;
}

RowColumnClass Rectangle::getUpperLeft()
{
    return upperLeft;
}

int Rectangle::getWidth()
{
    return width;
}
int Rectangle::getHeight()
{
    return height;
}
int Rectangle::getRecColor()
{
    return recColor;
}
int Rectangle::getFillOption()
{
    return fillOption;
}
