// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: vector.h
// ====================================================
//

#ifndef vector_h
#define vector_h

#include "list.h"

class Vector: public List{
public:
    Vector();
    ~Vector();
    
    // function returns the value at the provided index
    int at(int const index) const;
    
    // function returns first value in the list
    int first() const;
    
    // function returns the last value in the list
    int last() const;
    
    // function returns the size of the list
    int size() const;
    
    // function adds value to the end of the list
    void add(int const num);
    
    // function returns index of consumed value in list, if no match is
    // found funciton returns -1
    int find(int const num);
    
    // function removes consumed value from list
    bool remove(int const num);
private:
    int *arr;
    unsigned int length;        //# of characters currently in the chars array
    unsigned int capacity;      //maximum # of characters that chars can store
    void shiftArray(int fromIndex);
};

#endif /* vector_h */
