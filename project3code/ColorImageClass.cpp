/************************************************
project3:
Ting Gong
November 2, 2019

Class: ColorImageClass.cpp
Function: Enable the implementation of a class of 
image, consisting of the functions of read, write, 
and edit images.
************************************************/

#include <iostream>
#include <fstream>
using namespace std;
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "readOneInt.h"
#include "cinOneString.h"
#include "cinOneInt.h"
#include "cinTwoInt.h"
// ColorImageClass member functions' definitions

// initialize ColorImageClass with pure_black
ColorImageClass::ColorImageClass()
{
    height = DEFAULT_IMAGE_HEIGHT;
    width = DEFAULT_IMAGE_WIDTH;
    pixel_colors = NULL;
}
// destructor of the ColorImageClass
ColorImageClass::~ColorImageClass()
{
    if (pixel_colors != NULL)
    {
        delete [] pixel_colors;
    }
}
// initialize the ColorImageClass with inColor
void ColorImageClass::initializeTo(
     ColorClass &inColor
     )
{
    for (int i = 0; i < height * width; i++)
    {
        pixel_colors[i].setTo(inColor);
    }
}
// add ColorImageClass's ColorClass by rhsImg index-by-index
bool ColorImageClass::addImageTo(
     ColorImageClass &rhsImg
     )
{
    bool result = false;
    bool temp = false;
    ColorClass outColor;
    RowColumnClass inRowCol;
    bool isOutOfRangeFlag = false;
    if ((rhsImg.width != width) || (rhsImg.height != height))
    {
        cout << "The added image's shape does not agree with the image!!"
             << endl;
        return true;
    }
    for (int i = 0; i < width * height; i++)
    {   
        inRowCol.setRow(i / width);
        inRowCol.setCol(i % width);

        isOutOfRangeFlag = rhsImg.getColorAtLocation(inRowCol, outColor);
        if (!isOutOfRangeFlag)
        {   
            cout << "When add Image To the image, rhsImg is smaller than the " \
                 "image!" <<  endl;
            return true;
        }
        temp = pixel_colors[i].addColor(outColor);
        if (temp)
        {
            result = true;
        }
    }
    return result;
}
// set ColorImageClass's ColorClass with the index-by-index sum of imagesToAdd
bool ColorImageClass::addImages(
     int numImgsToAdd,
     ColorImageClass imagesToAdd []
     )
{
    bool result = false;
    bool temp = false;
    if (numImgsToAdd == 0)
    {
        return false;
    }
    ColorClass pure_black;
    pure_black.setToBlack();
    initializeTo(pure_black);
    for (int i = 0; i < numImgsToAdd; i++)
    {
        temp = addImageTo(imagesToAdd[i]);
        if (temp == true)
        {
            result = true;    
        }
    }
    return result;
}
// set ColorImageClass's ColorClass by inColor
bool ColorImageClass::setColorAtLocation(
     RowColumnClass &inRowCol,
     ColorClass &inColor
     )
{
    if (isOutOfRange(inRowCol))
    {
        return false;
    }
    pixel_colors[inRowCol.getRow() * width + inRowCol.getCol()].setTo(inColor);
    
    return true; 
}
// get ColorImageClass's ColorClass to outColor
bool ColorImageClass::getColorAtLocation(
     RowColumnClass &inRowCol,
     ColorClass &outColor
     )
{
    if (isOutOfRange(inRowCol))
    {
        return false;
    }
    outColor.setTo(pixel_colors[inRowCol.getRow() * width + inRowCol.getCol()]); 
    return true; 
}
// print ColorImageClass
void ColorImageClass::printImage()
{

    for (int i = 0; i < width * height; i++)
    {
        pixel_colors[i].printComponentValues();
        if ((i + 1) % width != 0)
        {
            cout << "--";
        }
        else
        {
            cout << endl;
        }
    }

}
bool ColorImageClass::isOutOfRange(
     RowColumnClass &inRowCol
     )
{
    if (inRowCol.getRow() >= height ||
       inRowCol.getRow() < DEFAULT_INDEX ||
       inRowCol.getCol() >= width ||
       inRowCol.getCol() < DEFAULT_INDEX)
    {
        return true;
    }
    return false;
}

bool ColorImageClass::readImage(
     string promptLineRead
     )
{
    ifstream inFile;
    string format;
    bool readFlag = false;
    int readIntFlag;
    string file;
    int colorMax;
    string errorPrint;
    
    
    readFlag = cinOneString(promptLineRead, file);
    if (!readFlag)
    {
        cout << "Invalid string input for image file name" << endl;
        return false;
    }
    inFile.open(file.c_str());
    if (inFile.fail())
    {
        cout << "Unable to open the input image file!!" << endl;
        return false;
    }
    else 
    {
        // reading format P3
        readFlag = readFormat(inFile, format);

        // if P3 is read successfully
        if (readFlag)
        {
            errorPrint = "ERROR: When reading width of image, non-int value " \
                         "is read!!";
            readFlag = readOneInt(inFile, width, errorPrint);
            // if width if read successfully
            if (readFlag)
            {
                errorPrint = "ERROR: When reading height of image, non-int " \
                             "value is read!!";
                readFlag = readOneInt(inFile, height, errorPrint);
                // if height is read successfully
                if (readFlag)
                {
                    errorPrint = "ERROR: When reading max color value of " \
                                 "image, non-int value is read!!";
                    readFlag = readOneInt(inFile, colorMax, errorPrint);
                    if (colorMax != FULL_COLOR)
                    {
                        cout << "Readed max color is not 255!!" << endl;
                        readFlag = false;
                    }
                    // if max color value is read successfully
                    if (readFlag)
                    {
                        pixel_colors = new ColorClass[width * height];
                        for (int i = 0; i < width * height; i++)
                        {
                            readIntFlag = pixel_colors[i].readColor(inFile);
                            if (readIntFlag != ERROR_READ_SUCCESS)
                            {
                                cout << "ERROR: When reading";
                                switch (readIntFlag)
                                {
                                    case ERROR_READ_RED:
                                        cout << " RED ";
                                        break;
                                    case ERROR_READ_GREEN:
                                        cout << " GREEN ";
                                        break;
                                    case ERROR_READ_BLUE:
                                        cout << " BLUE ";
                                        break;
                                }
                                cout << "color at (" << i / width << ", "
                                     << (i % width) / RGB_SIZE << ")" << endl;
                                // delete [] pixel_colors;
                                // it is commented because it will be
                                // automatically called.
                                readFlag = false;
                                width = DEFAULT_IMAGE_WIDTH;
                                height = DEFAULT_IMAGE_HEIGHT;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    inFile.close();
    return readFlag;
}

bool ColorImageClass::readFormat(
     ifstream &inFile, 
     string &format
     )
{
    inFile >> format;
    if (inFile.eof())
    {
        cout << "EOF before reading a valid format!!" << endl;
        return false;
    }
    else if ((inFile.fail()) | (format != "P3"))
    {
        cout << "When reading format from image file, non-sting or non-P3 " \
                "format exists in the first line!!" << endl;
        inFile.clear();
        inFile.ignore(200, '\n');
        return false;
    }
    return true;
}

bool ColorImageClass::writeImage(
     string &file
     )
{
    ofstream outFile;
    outFile.open(file.c_str());

    if (outFile.fail())
    {
        cout << "Unable to write to output file!" << endl;
        return false;
    }
    outFile << "P3" << endl;
    outFile << width << " " << height << endl;
    outFile << "255" << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel_colors[i * width + j].writeColor(outFile);
        }
        outFile << endl;
    }
    outFile.close();
    return true;
}

void ColorImageClass::insertImage()
{
    string errorPrint;
    ColorImageClass insertedImg;
    string promptLine;
    bool readFlag = false;
    int col;
    int row;
    RowColumnClass upperLeft;
    RowColumnClass pixelLocation;
    RowColumnClass insertPixelLocation;
    ColorClass currentColor;
    bool rangeFlag = false;

    promptLine = "Enter string for file name of PPM image to insert: ";
    readFlag = insertedImg.readImage(promptLine);
    if (!readFlag)
    {
        cout << "Unable to read input image file!!" << endl;
        return;
    }

    promptLine = "Enter upper left corner to insert image row and column: ";
    errorPrint = "Invalid input of upper left corner to insert image row and " \
                 "column!!";
    readFlag = cinTwoInt(promptLine, INDEX_MIN, INDEX_MAX, errorPrint, 
                         row, col);
    if (!readFlag)
    {
        return;
    }
    upperLeft.setRowCol(row, col);

    int transparecy = TRANSP_COLOR_DEFAULT;
    promptLine = "1. Red\n2. Green\n3. Blue\n4. Black\n5. White\nEnter int " \
                 "for transparecy color: ";
    errorPrint = "Invalid input for transparecy color!!";
    readFlag = cinOneInt(promptLine, TRANSP_COLOR_RED, TRANSP_COLOR_WHITE,
                         errorPrint, transparecy);
    if (!readFlag)
    {
        return;
    }
    ColorClass transparecyColor;
    switch (transparecy)
    {
        case TRANSP_COLOR_RED:
            transparecyColor.setToRed();
            break;
        case TRANSP_COLOR_GREEN:
            transparecyColor.setToGreen();
            break;
        case TRANSP_COLOR_BLUE:
            transparecyColor.setToBlue();
            break;
        case TRANSP_COLOR_BLACK:
            transparecyColor.setToBlack();
            break;
        case TRANSP_COLOR_WHITE:
            transparecyColor.setToWhite();
            break;
    } 

    for (int i = 0; i < insertedImg.getHeight(); i++)
    {
        for (int j = 0; j < insertedImg.getWidth(); j++)
        {
            row = upperLeft.getRow() + i;
            col = upperLeft.getCol() + j;
            pixelLocation.setRowCol(row, col);
            insertPixelLocation.setRowCol(i, j);
            insertedImg.getColorAtLocation(insertPixelLocation, currentColor);
            if (!currentColor.isEqual(transparecyColor))
            {
                if (!isOutOfRange(pixelLocation))
                {
                    setColorAtLocation(pixelLocation, currentColor);
                }
                else 
                {
                    rangeFlag = true;
                }
            }
        }
    }
    if (rangeFlag)
    {
        cout << "The inserted image is not within the image!!" << endl;
    }
    // insertedImg.~ColorImageClass(); 
    // it is commented because it will be automatically called.
}

int ColorImageClass::getWidth()
{
    return width;
}
int ColorImageClass::getHeight()
{
    return height;
}
void ColorImageClass::conductPattern(
     AnnotationPattern &pattern
     )
{
    int row;
    int col;
    ColorClass colorPattern;
    RowColumnClass upperLeft = pattern.getUpperLeft();
    RowColumnClass pixelLocation;
    int colorPatternInt = pattern.getColor();
    bool rangeFlag = false;
    switch (colorPatternInt)
    {
        case PATTERN_COLOR_RED:
            colorPattern.setToRed();
            break;
        case PATTERN_COLOR_GREEN:
            colorPattern.setToGreen();
            break;
        case PATTERN_COLOR_BLUE:
            colorPattern.setToBlue();
            break;
        case PATTERN_COLOR_BLACK:
            colorPattern.setToBlack();
            break;
        case PATTERN_COLOR_WHITE:
            colorPattern.setToWhite();
            break;
    }

    for (int i = 0; i < pattern.getHeight(); i++)
    {
        for (int j = 0; j < pattern.getWidth(); j++)
        {
            if (pattern.getItem(i * pattern.getWidth() + j) == PATTERN_ACTIVE)
            {
                row = upperLeft.getRow() + i;
                col = upperLeft.getCol() + j;
                pixelLocation.setRowCol(row, col);
                // Make sure rectangle's modification is within the image
                if (!isOutOfRange(pixelLocation))
                {
                    setColorAtLocation(pixelLocation, colorPattern);
                }
                else
                {
                    rangeFlag = true;
                }
            }
        }
    }
    if (rangeFlag)
    {
        cout << "Pattern is not within the image!!" << endl;
    }
}

void ColorImageClass::conductRectangle(
     Rectangle &rectangle
     )
{
    ColorClass colorRectangle;
    int row;
    int col;
    RowColumnClass pixelLocation;
    RowColumnClass upperLeft = rectangle.getUpperLeft();
    int colorRectangleInt = rectangle.getRecColor();
    bool rangeFlag = false;
    switch (colorRectangleInt)
    {
        case REC_COLOR_RED:
            colorRectangle.setToRed();
            break;
        case REC_COLOR_GREEN:
            colorRectangle.setToGreen();
            break;
        case REC_COLOR_BLUE:
            colorRectangle.setToBlue();
            break;
        case REC_COLOR_BLACK:
            colorRectangle.setToBlack();
            break;
        case REC_COLOR_WHITE:
            colorRectangle.setToWhite();
            break;
    }
    // If user intends to add a filled rectangle
    if (rectangle.getFillOption() == FILL_OPTION_TWO) 
    {
        for (int i = 0; i <= rectangle.getHeight(); i++)
        {
            for (int j = 0; j <= rectangle.getWidth(); j++)
            {
                row = upperLeft.getRow() + i;
                col = upperLeft.getCol() + j;
                pixelLocation.setRowCol(row, col);
                // Make sure rectangle's modification is within the image
                if (!isOutOfRange(pixelLocation))
                {
                    setColorAtLocation(pixelLocation, colorRectangle);
                }
                else
                {
                    rangeFlag = true;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= rectangle.getWidth(); i++)
        {
            // Draw the upper horizontal line
            row = upperLeft.getRow();
            col = upperLeft.getCol() + i;
            pixelLocation.setRowCol(row, col);
            // Make sure rectangle's modification is within the image
            if (!isOutOfRange(pixelLocation))
            {
                setColorAtLocation(pixelLocation, colorRectangle);
            }
            else
            {
                rangeFlag = true;
            }
            // Draw the lower horizontal line
            row = upperLeft.getRow() + rectangle.getHeight();
            col = upperLeft.getCol() + i;
            pixelLocation.setRowCol(row, col);
            // Make sure rectangle's modification is within the image
            if (!isOutOfRange(pixelLocation))
            {
                setColorAtLocation(pixelLocation, colorRectangle);
            }
            else
            {
                rangeFlag = true;
            }
        }
        for (int i = 0; i <= rectangle.getHeight(); i++)
        {
            // Draw the right vertical line
            row = upperLeft.getRow() + i;
            col = upperLeft.getCol() + rectangle.getWidth();
            pixelLocation.setRowCol(row, col);
            // Make sure rectangle's modification is within the image
            if (!isOutOfRange(pixelLocation))
            {
                setColorAtLocation(pixelLocation, colorRectangle);
            }
            else
            {
                rangeFlag = true;
            }
            // Draw the left vertical line
            row = upperLeft.getRow() + i;
            col = upperLeft.getCol();
            pixelLocation.setRowCol(row, col);
            // Make sure rectangle's modification is within the image
            if (!isOutOfRange(pixelLocation))
            {
                setColorAtLocation(pixelLocation, colorRectangle);
            }
            else
            {
                rangeFlag = true;
            }
        }       
    }
    if (rangeFlag)
    {
        cout << "Rectangle is not within the image!!" << endl;
    }
}
