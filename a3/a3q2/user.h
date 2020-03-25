// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 2
// File: user.h
// ====================================================
//

#ifndef user_hpp
#define user_hpp

#include <iostream>

struct User {
    const int id;
    User *nextFollow;
    //add helper methods here if needed
    User(const int); // one parameter constructor
    ~User();         // destructor
    
    //change follow(int int)
    void follow(int, int);
    void unfollow(int, int);    //
    void unfollowDeletion(int);
    void printFollowList();
    
};

#endif /* user_hpp */
