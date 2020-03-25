// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: allcaps.h
// ====================================================
//

#ifndef allcaps_h
#define allcaps_h

#include "textdecorator.h"

class AllCaps : public TextDecorator {
public:
    AllCaps(TextProcessor&);
    ~AllCaps();
    
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
private:
    std::istream *source;
    bool failed;
};

#endif /* allcaps_h */
