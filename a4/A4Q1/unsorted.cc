// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: unsorted.cc
// ====================================================
//
#include <cstdlib>
#include <iostream>
#include "unsorted.h"

using namespace std;

UnsortedList::UnsortedList():head(NULL), length(0){}

UnsortedList::~UnsortedList(){
    delete head;
}

// see unsorted.h for details
int UnsortedList::at(int const index) const{
    if (head != NULL) {
        return head->getValueAtIndex(index);
    }else{
        return -1;
    }
}

// see unsorted.h for details
int UnsortedList::first()const {
    if (head != NULL) {
        return head->getValue();
    }else{
        return -1;
    }
}

// see unsorted.h for details
int UnsortedList::last()const {
    if (head != NULL) {
        return head->getLastValue();
    }else{
        return -1;
    }
    
}

// see unsorted.h for details
int UnsortedList::size()const {
    return length;
}

// see unsorted.h for details
void UnsortedList::add(const int num){
    if (head != NULL) {
        head->addToBack(num);
    }else{
        head = new Node(num);
    }
    ++length;
}

// see unsorted.h for details
int UnsortedList::find(int const num){
    return head->find(num);
}

// see unsorted.h for details
bool UnsortedList::remove(int const num){
    if (head != NULL) {
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
        }else if (head->hasNext()){
            if (head->remove(num)) {
                cout << "node has been successfully removed" << endl;
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












