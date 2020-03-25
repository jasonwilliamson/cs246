// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 3
// File: count.cc
// ====================================================
//

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <locale>
#include <cstdlib>
#include "count.h"
#include "textprocess.h"

using namespace std;

Count::Count(TextProcessor& tp, char let):TextDecorator(tp), let(let), source(0), failed(false), counter(1){};

Count::~Count(){}

void Count::setSource(istream *inp){
    source = inp;
    textprocess.setSource(inp);
}


string Count::getWord(){
    string s;
    s = textprocess.getWord();
    failed = textprocess.fail();
    bool check = true;
    
    do {
        int found = int(s.find(let));
        if (found != -1) {
            stringstream convert;
            convert << counter;
            string num = convert.str();
            s.replace(found, 1, num);
            ++counter;
        }else{
            check = false;
        }
    } while (check);
    
    return s;
}

bool Count::fail() const{
    return failed;
}
