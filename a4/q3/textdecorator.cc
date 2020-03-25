// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: textdecorator.h
// ====================================================
//

#include <iostream>
#include <fstream>
#include <string>
#include "textdecorator.h"

TextDecorator::TextDecorator(TextProcessor& tp):textprocess(tp){}

TextDecorator::~TextDecorator(){
    delete &textprocess;
}


