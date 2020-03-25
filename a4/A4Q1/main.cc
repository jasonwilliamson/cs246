#include <iostream>
#include "vector.h"
#include "sorted.h"
#include "unsorted.h"

/*
 * This main function is provided to show you the benefits
 * of using a common interface
 *
 * g++ main.cc <otherfiles here>
 * will create a List that is internally implemented
 * as an int array
 *
 * g++ -DUNSORTED main.cc <otherfiles here>
 * will create a List that is internally implemented
 * as an unsorted linked list
 *
 * g++ -DSORTED main.cc <otherfiles here>
 * will create a List that is internally implemented
 *  as a sorted linked list
 *
 * You should not use this main function as your only
 * test for the correctness of your implementations
 *
 * DO NOT SUBMIT THIS MAIN FILE WE WILL BE USING OUR OWN
 */

using namespace std;
int main(){
    List *myList;
    
//default to vector
#ifndef SORTED
#ifndef UNSORTED
//   myList = new Vector;
#endif
#endif

//#ifdef SORTED
    myList = new SortedList;
//#endif

//#ifdef UNSORTED
//    myList = new UnsortedList;
//#endif
    cout << "Size:" << myList->size() << endl;
    
    myList->add(1);
    cout << "Size:" << myList->size() << endl;
    cout << "First:" << myList->first() << endl;
    cout << "Last:" << myList->last() << endl;
    cout << endl;
    
    
    myList->remove(1);
    cout << "Size:" << myList->size() << endl;
    cout << endl;
    
    myList->add(1);
    myList->add(2);
    myList->add(5);
    cout << "Size:" << myList->size() << endl;
    cout << "First:" << myList->first() << endl;
    cout << "Last:" << myList->last() << endl;
    cout << endl;
    
    myList->add(3);
    myList->add(6);
    myList->add(4);
    myList->add(7);
    cout << "Size:" << myList->size() << endl;
    cout << "First:" << myList->first() << endl;
    cout << "Last:" << myList->last() << endl;
    cout << endl;
    
    myList->remove(1);
    cout << "First:" << myList->first() << endl;
    myList->remove(2);
    cout << "First:" << myList->first() << endl;
    myList->remove(5);
    cout << "First:" << myList->first() << endl;
    myList->remove(3);
    cout << "First:" << myList->first() << endl;
    myList->remove(6);
    cout << "First:" << myList->first() << endl;
    myList->remove(4);
    cout << "First:" << myList->first() << endl;
    myList->remove(7);
    
    
    
    
    myList->add(1);
    myList->add(2);
    myList->add(5);
    myList->add(3);
    myList->add(6);
    myList->add(4);
    myList->add(7);
    
    
    
    cout << "Find(1): " << myList->find(1) << endl;
    myList->remove(1);
    cout << "Size:" << myList->size() << endl;
    cout << "Find(1): " << myList->find(1) << endl;
    cout << endl;
    
    cout << "Find(7): " << myList->find(7) << endl;
    cout << endl;
    
    myList->remove(3);
    cout << "Size:" << myList->size() << endl;
    cout << "First:" << myList->first() << endl;
    cout << "Last:" << myList->last() << endl;
    cout << endl;
    
    myList->remove(7);
    cout << "Size:" << myList->size() << endl;
    cout << "First:" << myList->first() << endl;
    cout << "Last:" << myList->last() << endl;
    cout << endl;
    
    myList->add(3);
    cout << "Size:" << myList->size() << endl; 
    cout << "First:" << myList->first() << endl;  
    cout << "Last:" << myList->last() << endl;  
    
    delete myList;
    
    return 0;
}