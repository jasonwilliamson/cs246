// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: doublewords.cc
// ====================================================
//

#include <string>
#include <iostream>
#include <ostream>
#include "doublewords.h"

using namespace std;

DoubleWords::DoubleWords(TextProcessor& tp):TextDecorator(tp),
 source(0), failed(false), wordcount(1), prevWord(""){}

DoubleWords::~DoubleWords(){}

void DoubleWords::setSource(istream *inp){
    source = inp;
    textprocess.setSource(inp);
}

string DoubleWords::getWord(){
    string s;
    if ((wordcount % 2) == 0) {
        s = prevWord;
    }else{
        s = textprocess.getWord();
        failed = textprocess.fail();
        prevWord = s;
    }
    ++wordcount;
    return s;
}

bool DoubleWords::fail() const{
    return failed;
}