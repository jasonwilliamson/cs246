// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: unsorted.h
// ====================================================
//


#ifndef unsorted_h
#define unsorted_h

#include "list.h"
#include "node.h"

class UnsortedList: public List{
public:
    UnsortedList();
    ~UnsortedList();
    
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
    Node *head;
    int length;

};

#endif