// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 1
// File: istring.cc
// ====================================================
//

#include "istring.h"
#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

char * copyCharArray(char *cArr, int size);

//defualt constructor
iString::iString(): length(0), capacity(1) {
    chars = new char[capacity];
    chars[0] = '\0';
}


iString::iString(const char *str)
:length((int)strlen(str)), capacity(length+1){
    chars = new char[capacity];
    strcpy(chars,str);
}

//copy constructor
iString::iString(const iString &s)
    :chars(new char[s.capacity]), length(s.length), capacity(s.capacity){
        strcpy(chars,s.chars);
}

//destructor
iString::~iString(){
    delete [] chars;
}


iString & iString::operator=(const iString &s){
    if (this != &s) {
        delete [] chars;
        chars = new char[s.capacity];
        strcpy(chars,s.chars);
        length = s.length;
        capacity = s.capacity;
    }
    return *this;
}


// concatenated prefixes of source iString
iString operator~(const iString &s){
    int tmpCapacity = (s.length * (s.length + 1))/2 + 1;
    char *tmp = new char[tmpCapacity];
    tmp[0] = '\0';
    
    char *prefix = new char[s.length + 1];
    
    for (int i=1;i<s.length;i++) {
        strncpy(prefix,s.chars,i);
        strcat(tmp,prefix);
    }
    
    iString newStr = iString(tmp);
    delete [] tmp;
    return newStr;
}

// overloaded + operator
iString operator+(const iString &s1, const iString &s2){
    int newLength = s1.length + s2.length;
    char *tmp = new char[newLength+1];
    
    strcpy(tmp,s1.chars);
    strcat(tmp,s2.chars);
    
    iString newStr = iString(tmp);
    delete [] tmp;
    return newStr;
}

// overloaded >> operator
istream& operator>>(istream &in, iString &s){
    int capacity = 5;
    int index = 0;
    char *tmp = new char[capacity];
    char input;
    do {
        in >> input;
        if (index + 1 >= capacity) {
            capacity *= 2;
            char *tmpLarge = new char[capacity];
            strcpy(tmpLarge,tmp);
            delete [] tmp;
            tmp = tmpLarge;
        }
        tmp[index] = input;
        index++;
    } while (isspace(in.peek()));
    delete [] s.chars;
    tmp[index] = '\0';
    s.chars = tmp;
    s.length = index;
    s.capacity = capacity + 1;
    return in;
}

// overloaded << operator
ostream& operator<<(ostream &out, const iString &s){
    return out << s.chars;
}

