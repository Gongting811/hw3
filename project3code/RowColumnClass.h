/************************************************
project3:
Ting Gong
November 2, 2019

Class: RowcolumnClass.h
Function: Implementation of class RowcolumnClass
that can define and deal with a location, row col  
************************************************/
#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

class RowColumnClass
{
private:
    int row_index;
    int col_index;
public:
    RowColumnClass();

    RowColumnClass(
         int inRow,
         int inCol
         );
    
    void setRowCol(
         int inRow,
         int inCol
         );
    
    void setRow(
         int inRow
         );
    
    void setCol(
         int inCol
         );

    int getRow();

    int getCol();

    void addRowColTo(
         RowColumnClass &inRowCol
         );

    void printRowCol();
    
};
#endif