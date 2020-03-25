// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: dropfirst.cc
// ====================================================
//

#include <string>
#include <iostream>
#include <ostream>
#include "dropfirst.h"

using namespace std;

DropFirst::DropFirst(TextProcessor& tp, int n):TextDecorator(tp), n(n), source(0), failed(false){}

DropFirst::~DropFirst(){}

void DropFirst::setSource(istream *inp){
    source = inp;
    textprocess.setSource(inp);
}

string DropFirst::getWord(){
    string s;
    s = textprocess.getWord();
    failed = textprocess.fail();
    if (s.length() <= n) {
        return this->getWord();
    }else{
        s = s.substr(n);
        return s;
    }
    
}

bool DropFirst::fail() const{
    return failed;
}
