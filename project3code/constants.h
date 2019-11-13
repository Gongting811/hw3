/************************************************
project3:
Ting Gong
November 2, 2019

Global constants
************************************************/
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

const int RGB_SIZE = 3;

const int DEFAULT_INT = 0;

const int ERROR_READ_SUCCESS = 0;
const int ERROR_READ_RED = 1;
const int ERROR_READ_GREEN = 2;
const int ERROR_READ_BLUE = 3;

const int FULL_COLOR = 255;
const int ZERO_COLOR = 0;
const int DEFAULT_INDEX = 0;

const int DEFAULT_IMAGE_HEIGHT = 0;
const int DEFAULT_IMAGE_WIDTH = 0;

const int MENU_DEFAULT = 0;
const int MENU_DRAW_RECTANGLE = 1;
const int MENU_ANNOTATE_IMAGE = 2;
const int MENU_INSERT_IMAGE = 3;
const int MENU_SAVE_IMAGE = 4;
const int MENU_EXIT_PROGRAM = 5; 

const int SPECIFYING_RECTANGLE_DEFAULT = 0;
const int SPECIFYING_RECTANGLE_ONE = 1;
const int SPECIFYING_RECTANGLE_TWO = 2;
const int SPECIFYING_RECTANGLE_THREE = 3;

const int DEFAULT_RECTANGLE_WIDTH = 0;
const int DEFAULT_RECTANGLE_HEIGHT = 0;
const int DEFAULT_RECTANGLE_UPPERLEFT_ROW = 0;
const int DEFAULT_RECTANGLE_UPPERLEFT_COL = 0;

const bool DEFAULT_EXITING = false;
const int INDEX_MIN = 0;
const int INDEX_MAX = 2147483647;

const int REC_COLOR_RED = 1;
const int REC_COLOR_GREEN = 2;
const int REC_COLOR_BLUE = 3;
const int REC_COLOR_BLACK = 4;
const int REC_COLOR_WHITE = 5;
const int REC_COLOR_DEFAULT = 0;

const int PATTERN_COLOR_RED = 1;
const int PATTERN_COLOR_GREEN = 2;
const int PATTERN_COLOR_BLUE = 3;
const int PATTERN_COLOR_BLACK = 4;
const int PATTERN_COLOR_WHITE = 5;
const int PATTERN_COLOR_DEFAULT = 0;

const int TRANSP_COLOR_RED = 1;
const int TRANSP_COLOR_GREEN = 2;
const int TRANSP_COLOR_BLUE = 3;
const int TRANSP_COLOR_BLACK = 4;
const int TRANSP_COLOR_WHITE = 5;
const int TRANSP_COLOR_DEFAULT = 0;

const int FILL_OPTION_ONE = 1;
const int FILL_OPTION_TWO = 2;
const int FILL_OPTION_DEFAULT = 0;

const int PATTERN_ACTIVE = 1;
const int PATTERN_PASSIVE = 0;

#endif