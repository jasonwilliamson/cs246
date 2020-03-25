// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: sorted.h
// ====================================================
//

#ifndef sorted_h
#define sorted_h

#include "list.h"
#include "node.h"

class SortedList: public List{
public:
    SortedList();
    ~SortedList();
    
    // function returns the value at the provided index
    int at(int const index)const;
    
    // function returns first value in the list
    int first()const;
    
    // function returns the last value in the list
    int last()const;
    
    // function returns the size of the list
    int size()const;
    
    // function adds value to the list in sorted(ascending order)
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

#endif /* sorted_h */
