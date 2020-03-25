// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: dropfirst.h
// ====================================================
//

#ifndef dropfirst_h
#define dropfirst_h

#include "textdecorator.h"

class DropFirst : public TextDecorator {
public:
    DropFirst(TextProcessor&, int n);
    ~DropFirst();
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
private:
    std::istream *source;
    bool failed;
    int n;
};

#endif /* dropfirst_h */
