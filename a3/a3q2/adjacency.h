// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 2
// File: adjacency.h
// ====================================================
//

#ifndef adjacency_hpp
#define adjacency_hpp

#include "user.h"
#include <string>

struct User;
const int MAXUSERS=100;
struct AdjacencyList {
    
    User *users[MAXUSERS];//array of User pointers
    
    //for descriptions of the following refer to
    //commands in the assignment specifications
    void addUser(int);
    void removeUser(int);
    void follow(int, int);
    void unfollow(int, int);
    void list(int id, int level) const;
    void printAll() const;
    void print(int) const;
    
    //add helper methods here
    void initialize();
    void deinitialize();
    void shiftUsers(int);
    User* findUser(int);
};

#endif
