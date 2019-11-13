/************************************************
project3:
Ting Gong
November 2, 2019

Class: Annotationpattern.cpp
Function: Implementation of class AnnotationPattern
that can read and create a pattern 
************************************************/
#include <iostream>
#include <fstream>
using namespace std;
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "cinOneInt.h"
#include "readOneInt.h"
#include "AnnotationPattern.h"

AnnotationPattern::AnnotationPattern()
{
    rowCol.setRowCol(DEFAULT_INDEX, DEFAULT_INDEX);
    colorPattern = PATTERN_COLOR_DEFAULT;
    pattern = NULL;
    width = DEFAULT_IMAGE_WIDTH;
    height = DEFAULT_IMAGE_HEIGHT;
}
AnnotationPattern::~AnnotationPattern()
{
    if (pattern != NULL)
    {
        delete [] pattern;
    }
}

bool AnnotationPattern::readPattern(
     string file
     )
{
    int row;
    int col;
    bool readFlag = false;

    // read image pattern file
    readFlag = readFile(file);
    if (!readFlag)
    {
        width = DEFAULT_IMAGE_WIDTH;
        height = DEFAULT_IMAGE_HEIGHT;
        pattern = NULL;
        cout << "Unable to read pattern file!!" << endl;
        return false;
    }
    // read left corner
    string promptLine = "Enter upper left corner of pattern row and column: ";
    string errorPrint = "Invalid input of upper left corner of pattern row " \
                        "and column!!";
    readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                         row, col);
    if (!readFlag)
    {
        return false;
    }
    rowCol.setRowCol(row, col);

    // read pattern color
    promptLine = "1. Red\n2. Green\n3. Blue\n4. Black\n5. White\nEnter int " \
                 "for pattern color: ";
    errorPrint = "Invalid input of pattern color!!";
    readFlag = cinOneInt(promptLine, PATTERN_COLOR_RED, PATTERN_COLOR_WHITE,
                             errorPrint, colorPattern);
    if (!readFlag)
    {
        colorPattern = PATTERN_COLOR_DEFAULT;
        return false;
    }
    return true;
}

bool AnnotationPattern::readFile(
     string fileName
     )
{
    bool readFlag = false;
    ifstream inFile;
    inFile.open(fileName.c_str());

    if (inFile.fail())
    {
        cout << "Unable to open input pattern file!" << endl;
        inFile.close();
        return false;
    }
    int tempWidth;
    int tempHeight;
    readFlag = readOneInt(inFile, tempWidth, "");
    if (inFile.fail()) 
    {
        cout << "Error when reading width values." << endl;
        inFile.close();
        return false;
    }
    readFlag = readOneInt(inFile, tempHeight, "");
    if (inFile.fail()) 
    {
        cout << "Error when reading height values." << endl;
        inFile.close();
        return false;
    }

    if (tempWidth <= INDEX_MIN)
    {
        cout << "Invalid width of pattern!!" << endl;
        inFile.close();
        return false;
    }

    if (tempHeight <= INDEX_MIN) 
    {
        cout << "Invalid height of pattern!!" << endl;
        inFile.close();
        return false;
    }   
    width = tempWidth;
    height = tempHeight;
    pattern = new int[width * height];
    for (int i = 0; i < width * height; i++)
    {
        readFlag = readOneInt(inFile, pattern[i], "");
        if (!readFlag)
        {
            cout << "Error when reading (" << i / width << ", " << i % width 
                 << ") pattern" << endl;
            inFile.close();
            delete [] pattern;
            return false;
        }
    }
    
    inFile.close();
    return true;
}

int AnnotationPattern::getWidth()
{
    return width;
}

int AnnotationPattern::getHeight()
{
    return height;
}

RowColumnClass AnnotationPattern::getUpperLeft()
{
    return rowCol;
}

int AnnotationPattern::getColor()
{
    return colorPattern;
}

int AnnotationPattern::getItem(
    int index
    )
{
    return pattern[index];    
}
