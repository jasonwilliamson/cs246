// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: vector.cc 
// ====================================================
//

#include "vector.h"

Vector::Vector(): length(0),  capacity(1){
    arr = new int[capacity];
}

Vector::~Vector(){
    delete [] arr;
}

// see vector.h for details
int Vector::at(int const index)const{
    return arr[index];
}

// see vector.h for details
int Vector::first() const{
    return arr[0];
}

// see vector.h for details
int Vector::last() const{
    return arr[length -1];
}

// see vector.h for details
int Vector::size() const{
    return length;
}

// see vector.h for details
void Vector::add(int const num){
    if (capacity <= length) {
        capacity *= 2;
        int *tmp = new int[capacity];
        for (unsigned int i = 0; i < length; i++) {
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
    }
    arr[length] = num;
    length++;
}

// see vector.h for details
int Vector::find(int const num){
    for (unsigned int i = 0; i < length; i++) {
        if (num == arr[i]) {
            return i;
        }
    }
    return -1;
}

// see vector.h for details
bool Vector::remove(int const num){
    for (unsigned int i = 0; i < length; i++) {
        if (num == arr[i]) {
            arr[i] = -1;
            shiftArray(i);
            return true;
        }
    }
    return false;
}

// see vector.h for details
void Vector::shiftArray(int fromIndex){
    for (unsigned int i = fromIndex; i < length -1; i++) {
        arr[i] = arr[i + 1];
    }
    //arr[length] = -1;
    length--;
}


