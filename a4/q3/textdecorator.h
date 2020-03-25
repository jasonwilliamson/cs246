// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: textdecorator.h
// ====================================================
//

#ifndef textdecorator_h
#define textdecorator_h

#include <iostream>
#include <fstream>
#include <string>
#include "textprocess.h"

class TextDecorator: public TextProcessor{
public:
    TextDecorator(TextProcessor& tp);
    virtual ~TextDecorator();
protected:
    TextProcessor& textprocess;
};

#endif /* textdecorator_h */
