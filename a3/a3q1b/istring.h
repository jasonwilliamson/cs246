// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 1
// File: istring.h
// ====================================================
//

#ifndef ISTRING_H
#define ISTRING_H
#include <iostream>
#include <cstring>
#include <locale>

struct iString{
    
    char * chars;               //dynamically allocated array of chars
    unsigned int length;        //# of characters currently in the chars array
    unsigned int capacity;      //maximum # of characters that chars can store
    iString();                  //constructor
    iString(const char *);      //one parameter constructor that takes c-style string
    iString(const iString &);               //copy constructor
    ~iString();                             //destructor
    iString& operator=(const iString &);    //copy assignment operator
};

// input/ouput operators, operator+, operator~ here:
iString operator~(const iString &s);
iString operator+(const iString &s1, const iString &s2);
std::istream& operator>>(std::istream &in, iString &s);
std::ostream& operator<<(std::ostream &out, const iString &s);
#endif
