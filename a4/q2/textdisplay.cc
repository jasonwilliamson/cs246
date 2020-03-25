// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: textdisplay.cc
// ====================================================
//

#include "textdisplay.h"

using namespace std;

//ctor, initializes the display grid with default value of '0' chars
TextDisplay::TextDisplay(int n):View(n){

    theDisplay = new char*[n];
    for (int i = 0; i < n; i++) {
        theDisplay[i] = new char[n];
        for (int j = 0; j < n; j++) {
            theDisplay[i][j] = '0';
        }
    }
}


TextDisplay::~TextDisplay(){
    for (int i = 0; i < gridSize; i++) {
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
    theDisplay = NULL;
}


//notify(row, column, ch) invoked by controller, function updates
// the display with new state change
void TextDisplay::notify(int row, int column, char ch){
    theDisplay[row][column] = ch;
}


//print(out) outputs the display in grid form
void TextDisplay::print(ostream &out) const{
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            out << theDisplay[i][j];
        }
        out << endl;
    }
}