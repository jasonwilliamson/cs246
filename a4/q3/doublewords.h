// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: doublewords.h
// ====================================================
//

#ifndef doublewords_h
#define doublewords_h

#include "textdecorator.h"

class DoubleWords : public TextDecorator {
public:
    DoubleWords(TextProcessor&);
    ~DoubleWords();
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
private:
    std::istream *source;
    bool failed;
    int wordcount;
    std::string prevWord;
};

#endif /* doublewords_h */
