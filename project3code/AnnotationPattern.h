/************************************************
project3:
Ting Gong
November 2, 2019

Class: Annotationpattern.h
Function: Implementation of class AnnotationPattern
that can read and create a pattern 
************************************************/
#ifndef _ANNOTATIONPATTERN
#define _ANNOTATIONPATTERN 
class AnnotationPattern
{
private:
    RowColumnClass rowCol;
    int colorPattern;
    int *pattern;
    int width;
    int height;
public:
    AnnotationPattern();
    bool readPattern(
         string file
         );
    bool readFile(
         string fileName
         );
    int getWidth();
    int getHeight();
    RowColumnClass getUpperLeft();
    int getColor();
    int getItem(
        int index
        );
    ~AnnotationPattern();
    
};
#endif