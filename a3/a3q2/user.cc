// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 2
// File: user.cc
// ====================================================
//

#include "user.h"
#include <iostream>

/*User(const int);
~User();
void follow(int);
void unfollow(int);*/
using namespace std;

// Constructor that takes in one parameter, user's id
User::User(const int id):id(id), nextFollow(NULL){}

// dtor of User
User::~User(){
    delete nextFollow;
    //cout << "User " << this->id << "dtor" << endl;
}

// prints all users followed by current user
void User::printFollowList(){
    
    if (nextFollow != NULL) {
        if (nextFollow->nextFollow != NULL) {
            cout << nextFollow->id << ", ";
            nextFollow->printFollowList();
        }else{
            cout << nextFollow->id << endl;
        }
    }else{
        cout << "no one" << endl;
    }
}

// will add new user the user follow list, in link list format
void User::follow(int userId, int followId){
    if (userId == followId) {
        cout << "Cannot follow yourself" << endl;
    }else if (nextFollow == NULL){
        nextFollow = new User(followId);
        cout << "User " << userId << " is now following " << followId << endl;
    }else if (nextFollow->id == followId){
        cout << "User " << userId << "is already following " << followId << endl;
    }
    else{
        nextFollow->follow(userId, followId);
    }
}

// will unfollow a user and perform necessary changes to linked list
void User::unfollow(int userId, int followId){
    if (userId == followId) {
        cout << "Cannot follow yourself therefore cannot unfollow yourself" << endl;
    }
    else if (nextFollow == NULL) {
        cout << "User " << userId << " was not following " << followId << endl;
    }else if (nextFollow->id == followId){
        User *tmp = nextFollow->nextFollow;
        nextFollow->nextFollow = NULL;
        delete nextFollow;
        nextFollow = tmp;
        //User UserID1 is no longer following UserID2
        cout << "User " << userId << " is no longer following " << followId << endl;
        
    }else{
        nextFollow->unfollow(userId, followId);
    }
}

//will unfollow a user while not printing anything to stdout
void User::unfollowDeletion(int id){
    if (this->id == id || nextFollow == NULL) {
        return;
    }else if (nextFollow->id == id){
        User *tmp = nextFollow->nextFollow;
        nextFollow->nextFollow = NULL;
        delete nextFollow;
        nextFollow = tmp;
    }else{
        nextFollow->unfollowDeletion(id);
    }
}
