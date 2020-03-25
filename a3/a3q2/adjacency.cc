// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 2
// File: adjacency.cc
// ====================================================
//

#include "adjacency.h"
#include "user.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// holds index of users in Users array
int userIndex = 0;

// initializes all users in Users array to NULL
void AdjacencyList::initialize(){
    for (int i = 0; i < MAXUSERS; i++) {
        users[i] = NULL;
    }
}

void AdjacencyList::deinitialize(){
    for (int i = 0; i < userIndex; i++) {
        delete users[i]->nextFollow;
    }
}

// add a user to Users array
void AdjacencyList::addUser(int id){
    for (int i = 0; i < userIndex; i++) {
        if (users[i] != NULL) {
            if (users[i]->id == id) {
                cout << "User " << id << " already has an account" << endl;
                return;
            }
        }
        
    }
    
    if (userIndex < MAXUSERS) {
        users[userIndex] = new User(id);
        userIndex++;
         cout << "User " << id << " has joined the social network" << endl; //*******
    }
}

// removes user from Users array
void AdjacencyList::removeUser(int id){
    
    for (int i = 0; i < userIndex; i++) {
        if (users[i]->id == id) {
            for (int j = 0; j < userIndex; j++) {
                users[j]->unfollowDeletion(id);
            }
            
            users[i] = NULL;
            shiftUsers(i);
            //User UserID has deleted their account
            cout << "User " << id << " has deleted their account" << endl;
            return;
        }
    }
    cout << "User " << id << " does not have an account" << endl;
}

// follow(id1, id2) takes in two parameters, id1 is the user that is following
// id2 is the user that is to be followed
void AdjacencyList::follow(int id1, int id2){
    
    User *follower = findUser(id1);
    if (follower == NULL) {
        cout << "User " << id1 << " does not have an account" << endl;
        return;
    }
    
    User *followee = findUser(id2);
    if (followee == NULL) {
        cout << "User " << id2 << " does not have an account" << endl;
        return;
    }
    
    follower->follow(id1, id2);
}

// unfollow(id1, id2) takes in two paremeters, id1 is the suer that is unfollowing
// id2 is the user that is to be unfollowed
void AdjacencyList::unfollow(int id1, int id2){
    
    User *follower = findUser(id1);
    if (follower == NULL) {
        cout << "User " << id1 << " does not have an account" << endl;
        return;
    }
    
    User *followee = findUser(id2);
    if (followee == NULL) {
        cout << "User " << id2 << " does not have an account" << endl;
        return;
    }
    
    follower->unfollow(id1, id2);
}

void AdjacencyList::list(int id, int level)const{
    //cout << "list " << id << " " << level << endl;
}

// prints details of each user in the Users array
void AdjacencyList::printAll()const{
    //cout << "printAll " << endl;
    for (int i = 0; i < userIndex; i++) {
        print(users[i]->id);
    }
}

// print(id) takes in id, the id of the User to print information of
void AdjacencyList::print(int id)const{
    
    for (int i = 0; i < userIndex; i++) {
        if (users[i]->id == id) {
            cout << "User " << id << " is following ";
            users[i]->printFollowList();
            return;
        }
    }
    cout << "User " << id << " does not have an account" << endl;
}

// finderUser(id) takes in id, searches Users array for user matching
// that id and returns the User otherwise if user not found function
// returns NULL
User * AdjacencyList::findUser(int id){
    for (int j = 0; j < userIndex; j++) {
        if (users[j] != NULL) {
            if (users[j]->id == id) {
                return users[j];
            }
        }
    }
    return NULL;
}

// shiftUsers() performs the task of shifting down all users
// in the Users array when one User leaves
void AdjacencyList::shiftUsers(int index){
    for (int i=index;i<MAXUSERS-1;i++) {
        users[i] = users[i+1];
    }
    users[MAXUSERS-1] = NULL;
}

