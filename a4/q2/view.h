// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: view.h
// ====================================================
//

#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>

class View {
    
protected:
    const int gridSize;
public:
    View(int n);
    
    /*
     * The Controller calls notify to update the (row,column) location to be ch
     */
    virtual void notify(int row, int column, char ch) = 0;
    
    virtual void print(std::ostream &out) const = 0;
    
    virtual ~View();
};

#endif