// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 1
// File: node.h
// ====================================================
//

#ifndef node_h
#define node_h


struct Node{
public:
    // ctor requires an int value to be provided to create a Node
    explicit Node(const int value);
    ~Node();
    
    // overloaded assignment operator
    Node& operator= (const Node &);
    
    // getter function, returns private Node pointer next's value
    Node * getNext() const;
    
    // setter function, sets Node pointer next's value
    void setNext(Node *);
    
    // adds a value to the linkedlist in sorted(ascending) order
    // consumes the value to be added
    void addSorted(int const value);
    
    // adds a value to the end of the linked list
    // consumes the value to be added
    void addToBack(int const value);
    
    // getter function, returns value
    int getValue() const;
    
    // getter function, returns last value in linked list
    int getLastValue() const;
    
    // function returns value at given index,
    // consumes index value to be returns and provides a default index
    // of zero to start search from
    int getValueAtIndex(int const index, int currentIndex = 0);
    
    // function returns index of value in the linked list
    // consumes num, the value to search for and provides a defualt index
    // of zero to start search from
    // function returns -1 if no matching value is found
    int find(int num, int currentIndex = 0);
    
    // removes consumed num from the linked list
    bool remove(int num);
    
    // function returns true if private Node * next is not NULL otherwise
    // function returns false
    bool hasNext() const;
private:
    int value;
    Node * next;
};

#endif /* node_h */
