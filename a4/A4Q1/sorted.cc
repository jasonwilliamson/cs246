// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: sorted.cc
// ====================================================
//

#include "sorted.h"
#include <iostream>

using namespace std;

SortedList::SortedList():head(NULL), length(0){}

SortedList::~SortedList(){
    delete head;
}

// see sorted.h for details
int SortedList::at(int const index) const{
    if (head != NULL) {
        return head->getValueAtIndex(index);
    }else{
        // will not be called
        // assuming valid input
        return -1;
    }
}

// see sorted.h for details
int SortedList::first() const{
    if (head != NULL) {
        return head->getValue();
    }else{
        // will not be called
        // assuming valid input
        return -1;
    }
}

// see sorted.h for details
int SortedList::last() const{
    return head->getLastValue();
}

// see sorted.h for details
int SortedList::size() const{
    return length;
}

// see sorted.h for details
void SortedList::add(int const num){
    if (head != NULL) {
        head->addSorted(num);
        // link list does not exist
    }else{
        head = new Node(num);
    }
    ++length;
}

// see sorted.h for details
int SortedList::find(int const num){
    return head->find(num);
}

// see sorted.h for details
bool SortedList::remove(int const num){
    if (head != NULL) {
        // handle case where first node is removed
        if (head->getValue() == num) {
            if (head->hasNext()) {
                Node *first = head;
                head = head->getNext();
                first->setNext(NULL);
                delete first;
                --length;
                return true;
            }else{
                delete head;
                head = NULL;
                --length;
                return true;
            }
            // remove node as usual
        }else if (head->hasNext()){
            if (head->remove(num)) {
                --length;
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}



