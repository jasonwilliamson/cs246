// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: allcaps.cc
// ====================================================
//

#include <string>
#include <iostream>
#include <cstring>
#include <locale>
#include "allcaps.h"

using namespace std;

AllCaps::AllCaps(TextProcessor& tp):TextDecorator(tp), source(0), failed(false){};

AllCaps::~AllCaps(){}

void AllCaps::setSource(istream *inp){
    source = inp;
    textprocess.setSource(inp);
}


string AllCaps::getWord(){
    string s;
    s = textprocess.getWord();
    failed = textprocess.fail();
    
    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    for (int i = 0; i < s.length(); i++) {
        cstr[i] = toupper(cstr[i]);
    }
    s = cstr;
    delete [] cstr;
    return s;
}

bool AllCaps::fail() const{
    return failed;
}
