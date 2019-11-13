/************************************************
project3:
Ting Gong
November 2, 2019

Class: Rectangle.h
Function: Implementation of class rectangle
that can read and create a rectangle to be added 
in an image 
************************************************/
#ifndef _RECTANGLE_
#define _RECTANGLE_
#include "RowColumnClass.h"
class Rectangle
{
private:
    RowColumnClass upperLeft;
    int width;
    int height;
    int choiceRec;
    int recColor;
    int fillOption;
public:
    Rectangle();
    // constructor 
    bool createRectangle();
    // call the folowing three functions to obtain specification method, color,
    // and fill option. 
    bool choosingSpecifying();
    // prompt to user for choosing a rectangle specification method
    bool chooseingColor();
    // prompt to user for choosing a fill color
    bool choosingFillOption();
    // prompt to user for choosing a fill option

    RowColumnClass getUpperLeft();
    // get the upper-left corner of rectangle
    int getWidth();
    int getHeight();
    int getRecColor();
    int getFillOption();
    ~Rectangle();
};

#endif
