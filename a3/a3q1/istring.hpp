//
//  istring.hpp
//  a3q1
//
//  Created by Jason Williamson on 2015-10-25.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//


#ifndef ISTRING_H
#define ISTRING_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

struct iString{
    
    char * chars;	        //dynamically allocated array of chars
    unsigned int length;    //# of characters currently in the chars array
    unsigned int capacity;  //maximum # of characters that chars can store
    iString();              //constructor
    iString(const char *);  //one parameter constructor that takes c-style string
    iString(const iString&);//copy constructor
    ~iString();             //destructor
    iString& operator=(const iString&); //copy assignment operator
};

// Add other declarations such as
// input/ouput operators, operator+, operator~ here:

#endif


