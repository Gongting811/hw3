/************************************************
project3:
Ting Gong
November 2, 2019

Class: ColorImageClass.h
Function: Enable the implementation of a class of 
image, consisting of the functions of read, write, 
and edit images.
************************************************/
#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "ColorClass.h"
#include "RowColumnClass.h"
#include <fstream>
#include <string>
#include "AnnotationPattern.h"
#include "Rectangle.h"
#include "cinTwoInt.h"

class ColorImageClass
{
private:
    ColorClass *pixel_colors;
    //The height of the input image.
    int height;
    //The width of the input image.
    int width;
    
public:
    // constructor
    ColorImageClass();

    // initialize the whole image with the inColor 
    void initializeTo(
         ColorClass &inColor
         );

    // add another rhsImg to the image
    bool addImageTo(
         ColorImageClass &rhsImg
         );

    // add a group of images ot the image
    bool addImages(
         int numImgsToAdd,
         ColorImageClass imagesToAdd []
         );

    // change color of the image at inRowCol location with inColor 
    bool setColorAtLocation(
         RowColumnClass &inRowCol,
         ColorClass &inColor
         );

    // get the color from the image at inRowCol location
    bool getColorAtLocation(
         RowColumnClass &inRowCol,
         ColorClass &outColor
         );

    // echo the image on screen
    void printImage();

    // judge if the inRowCol is within the image
    bool isOutOfRange(
         RowColumnClass &inRowCol
         );

    // prompt to read a image until it is valid
    bool readImage(
         string promptLineRead
         );

    bool readFormat(
         ifstream &inFile, 
         string &format
         );

    bool writeImage(
         string &file
         );

    void insertImage();
    int getWidth();
    int getHeight();
    void conductPattern(
         AnnotationPattern &pattern
         );
    void conductRectangle(
         Rectangle &rectangle
         );
    ~ColorImageClass();
    
};
#endif