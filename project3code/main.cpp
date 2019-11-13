/************************************************
project3:
Ting Gong
November 2, 2019

main.cpp
This program allows user to read, edit and
save an image in ppm file format.
************************************************/


#include <iostream>
#include <fstream>
using namespace std;
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "cinOneString.h"
#include "cinOneInt.h"

int main()
{

    string promptLine;
    string promptLineMenu;
    string errorPrintMenu;
    int menuPrompt = MENU_DEFAULT;
    bool readImageFlag;
    bool readRectangleFlag;
    bool readPatternFlag;
    Rectangle rectangleObj;
    ColorImageClass imageObj;
    AnnotationPattern patternObj;
    string outFile;
    
    promptLine = "Enter string for PPM image file name to load: ";
    readImageFlag = imageObj.readImage(promptLine);
    // if the program fails to read image, exit the program
    if (!readImageFlag)
    {
        menuPrompt = MENU_EXIT_PROGRAM;    
    }

    promptLineMenu = "1. Annotate image with rectangle\n2. Annotate image " \
                     "with pattern from file\n3. Insert another image\n4. " \
                     "Write out current image\n5. Exit the program\nEnter " \
                     "int for main menu choice: ";
    errorPrintMenu = "Invalid input for main menu choice!!";
    
    while (menuPrompt != MENU_EXIT_PROGRAM)
    {
        readImageFlag = false;
        // prompt until user gives a valid menu choice
        while (!readImageFlag)
        {
            readImageFlag = cinOneInt(promptLineMenu, MENU_DRAW_RECTANGLE,
                                      MENU_EXIT_PROGRAM, errorPrintMenu, 
                                      menuPrompt);
        }
        switch (menuPrompt)
        {
            case MENU_DRAW_RECTANGLE:
            {
                readRectangleFlag = rectangleObj.createRectangle();
                // only conduct rectangle when input's valid
                if (readRectangleFlag)
                {
                    imageObj.conductRectangle(rectangleObj);
                }
                break;
            }
            case MENU_INSERT_IMAGE:
            {
                imageObj.insertImage();
                break;
            }
            case MENU_ANNOTATE_IMAGE:
            {
                promptLine = "Enter string for file name containing pattern: ";
                string fileName;
                readPatternFlag = cinOneString(promptLine, fileName);
                if (readPatternFlag)
                {
                    readPatternFlag = patternObj.readPattern(fileName);
                    if (readPatternFlag)
                    {
                        imageObj.conductPattern(patternObj);
                    }
                }
                break;
            }
            case MENU_SAVE_IMAGE:
            {
                promptLine = "Enter string for PPM file name to output: ";
                readImageFlag = cinOneString(promptLine, outFile);
                if (readImageFlag)
                {
                    imageObj.writeImage(outFile);
                }
                break;
            }
        }

    }
    // imageObj.~ColorImageClass();
    cout << "Thank you for using this program" << endl;
    return (0);
}
