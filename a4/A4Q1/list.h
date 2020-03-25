// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: list.h
// ====================================================
//

#ifndef list_h
#define list_h


class List{
public:
    virtual ~List();
    virtual int at(int const index) const = 0;
    virtual int first() const = 0;
    virtual int last() const = 0;
    virtual int size() const = 0;
    virtual void add(int const num) = 0;
    virtual int find(int const num) = 0;
    virtual bool remove(int const num) = 0;
};

#endif /* list_h */
