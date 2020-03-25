// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: count.h
// ====================================================
//

#ifndef count_h
#define count_h

#include <string>
#include <iostream>
#include <cstring>
#include <locale>
#include <cstdlib>
#include "textprocess.h"
#include "textdecorator.h"

class Count : public TextDecorator {
public:
    Count(TextProcessor& tp, char let);
    ~Count();
    char let;
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
private:
    std::istream *source;
    bool failed;
    int counter;
};

#endif /* count_h */
