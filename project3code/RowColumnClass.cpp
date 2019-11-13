/************************************************
project3:
Ting Gong
November 2, 2019

Class: RowcolumnClass.cpp
Function: Implementation of class RowcolumnClass
that can define and deal with a location, row col  
************************************************/
#include <iostream>
using namespace std;
#include "RowColumnClass.h"
#include "constants.h"

// initialize RowColumnClass with default indexs
RowColumnClass::RowColumnClass()
{
    row_index = DEFAULT_RECTANGLE_UPPERLEFT_ROW;
    col_index = DEFAULT_RECTANGLE_UPPERLEFT_COL;
};
// initialize RowColumnClass with input indexs
RowColumnClass::RowColumnClass(
     int inRow,
     int inCol
     )
{
    row_index = inRow;
    col_index = inCol;        
}
// set RowColumnClass with input indexs
void RowColumnClass::setRowCol(
     int inRow,
     int inCol
     )
{
    row_index = inRow;
    col_index = inCol;            
}
// set RowColumnClass with input row
void RowColumnClass::setRow(
     int inRow
     )
{
    row_index = inRow;
}
// set RowColumnClass with input column
void RowColumnClass::setCol(
     int inCol
     )
{
    col_index = inCol;        
}
// get RowColumnClass's row index
int RowColumnClass::getRow()
{
    return row_index;
}
// get RowColumnClass's column index
int RowColumnClass::getCol()
{
    return col_index;        
}
// add RowColumnClass's index with input RowColumnClass
void RowColumnClass::addRowColTo(
     RowColumnClass &inRowCol
     )
{ 
    row_index += inRowCol.getRow();
    col_index += inRowCol.getCol();
}
// print RowColumnClass
void RowColumnClass::printRowCol()
{
    cout << "[" << row_index << "," << col_index << "]";
}
