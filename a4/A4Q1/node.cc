// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: node.cc
// ====================================================
//

#include "node.h"
#include <iostream>
using namespace std;

// see node.h for details
Node::Node(int const value):value(value), next(NULL){}

Node::~Node(){
    delete next;
}

// see node.h for details
int Node::getValue()const{
    return this->value;
}

// see node.h for details
int Node::getLastValue()const{
    if (this->next != NULL) {
        return this->next->getLastValue();
    }else{
        return this->value;
    }
}

// see node.h for details
bool Node::hasNext()const{
    if (this->next != NULL) {
        return true;
    }else{
        return false;
    }
}

// see node.h for details
Node * Node::getNext()const{
    return this->next;
}

// see node.h for details
void Node::setNext(Node *n){
    this->next = n;
}

// see node.h for details
int Node::getValueAtIndex(const int index, int currentIndex){
    if (index == currentIndex) {
        return this->value;
    }else{
        //assuming valid index here
        return this->next->getValueAtIndex(index, ++currentIndex);
    }
}

// see node.h for details
int Node::find(const int num, int currentIndex){
    if (this->value == num) {
        return currentIndex;
    }else if (this->next != NULL){
        return this->next->find(num, ++currentIndex);
    }else{
        return -1;
    }
}

// see node.h for details
void Node::addToBack(int const value){
    if (this->next != NULL) {
        this->next->addToBack(value);
    }else{
        this->next = new Node(value);
    }
}

// see node.h for details
void Node::addSorted(int const value){
    // insert value before current node
    if (this->value >= value) {
        Node *tmp = new Node(this->value);
        this->value = value;
        tmp->next = this->next;
        this->next = tmp;
    // insert value at the end of llist
    }else if (this->next == NULL){
        this->next = new Node(value);
    // recurse until condition is met
    }else{
        this->next->addSorted(value);
    }
}

// see node.h for details..
// checks next node for a match and removes it if matched with consumed num
// otherwise recursively checks next in the linked list until match is found or
// incounters end of list. If no match is found funciton returns false otherwise
// return true
bool Node::remove(int num){
    // node not found
    if (this->next == NULL) {
        //cout << "node not found" << endl;
        return false;
    }else if (this->next->value == num) {
        Node *tmp = this->next;
        //cout << "node found!: " << tmp << " value: " << tmp->value << endl;
        // must be last node
        this->next = NULL;
        //cout << "this->next = NULL " << " tmp is now: " << tmp << endl;
        if (tmp->next == NULL) {
            //cout << "deleting tmp: tmp->next == NULL" << endl;
            delete tmp;
            return true;
        }else{
            // not the last node
            //cout << "tmp is not last, tmp->next:" << tmp->next <<endl;
            this->next = tmp->next;
            tmp->next = NULL;
            delete tmp;
            //cout << "this->next is now:" << this->next << endl;
            return true;
        }
    }else{
        return this->next->remove(num);
    }
}

// see node.h for details
Node& Node::operator=(const Node &n){
    if (this != &n) {
        value = n.value;
        next = n.next;
    }
    return *this;
}


