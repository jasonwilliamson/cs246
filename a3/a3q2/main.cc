// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 03, Problem 2
// File: main.cc
// ====================================================
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "adjacency.h"
#include "user.h"

using namespace std;

// readfile(filename, *adjList) takes in a filename and a pointer to Adjacency
// function reads contents of file and perform tasks as it would from cin
// function returns true if quit is called from commands in file
bool readFile(string filename, AdjacencyList *adjList){
    const string CMD_PLUS = "+";
    const string CMD_MINUS = "-";
    const string CMD_FOLLOW = "follow";
    const string CMD_UNFOLLOW = "unfollow";
    const string CMD_PRINT = "print";
    const string CMD_PRINTALL = "printall";
    const string CMD_LIST = "list";
    const string CMD_INCLUDE = "include";
    const string CMD_QUIT = "quit";
    
    
    string currentCommand;
    string cmdtype;
    string s;
    int n;
    int n1;
    int n2;
    //cout << "inside readFile:" << endl;
    ifstream file(filename.c_str());
    
    while (file >> s) {
        //cout << "reading from file" << endl;
        if (CMD_PLUS == s) {
            file >> n;
            //cout << "+" << n << endl;
            adjList->addUser(n);
        }else if (CMD_MINUS == s){
            //cout << "-" << endl;
            file >> n;
            adjList->removeUser(n);
        }else if (CMD_FOLLOW == s){
            //cout << "follow" << endl;
            file >> n1;
            file >> n2;
            adjList->follow(n1, n2);
        }else if (CMD_UNFOLLOW == s){
            //cout << "unfollow" << endl;
            file >> n1;
            file >> n2;
            adjList->unfollow(n1, n2);
        }else if (CMD_PRINT == s){
            //cout << "print" << endl;
            file >> n;
            adjList->print(n);
        }else if (CMD_PRINTALL == s){
            //cout << "printall" << endl;
            adjList->printAll();
        }else if (CMD_LIST == s){
            //cout << "list" << endl;
            file >> n1;
            file >> n2;
            adjList->list(n1, n2);
        }else if (CMD_INCLUDE == s){
            string newFile;
            file >> newFile;
            readFile(newFile, adjList);
        }else if (CMD_QUIT == s){
            file.close();
            file.clear();
            return true;
        }else{
            //cout << "cmd not found!" << endl;
            break;
        }
    }
    file.clear();
    file.close();
    return false;
}


int main() {
    
    AdjacencyList *adjList = new AdjacencyList;
    adjList->initialize();
    //command types
    const string CMD_PLUS = "+";
    const string CMD_MINUS = "-";
    const string CMD_FOLLOW = "follow";
    const string CMD_UNFOLLOW = "unfollow";
    const string CMD_PRINT = "print";
    const string CMD_PRINTALL = "printall";
    const string CMD_LIST = "list";
    const string CMD_INCLUDE = "include";
    const string CMD_QUIT = "quit";
    
    
    string currentCommand;
    string cmdtype;
    string s;
    int n;
    int n1;
    int n2;
    while (cin >> s) {
        
        if (CMD_PLUS == s) {
            cin >> n;
            //cout << "+" << n << endl;
            adjList->addUser(n);
        }else if (CMD_MINUS == s){
            //cout << "-" << endl;
            cin >> n;
            adjList->removeUser(n);
        }else if (CMD_FOLLOW == s){
            //cout << "follow" << endl;
            cin >> n1;
            cin >> n2;
            adjList->follow(n1, n2);
        }else if (CMD_UNFOLLOW == s){
            //cout << "unfollow" << endl;
            cin >> n1;
            cin >> n2;
            adjList->unfollow(n1, n2);
        }else if (CMD_PRINT == s){
            //cout << "print" << endl;
            cin >> n;
            adjList->print(n);
        }else if (CMD_PRINTALL == s){
            //cout << "printall" << endl;
            adjList->printAll();
        }else if (CMD_LIST == s){
            //cout << "list" << endl;
            cin >> n1;
            cin >> n2;
            adjList->list(n1, n2);
        }else if (CMD_INCLUDE == s){
            //cout << "include" << endl;
            string file;
            //cout << "Accepting file" << endl;
            cin >> file;
            //cout << "file is: " << file << endl;
            bool quit = readFile(file, adjList);
            if(quit){
                break;
            }
        }else if (CMD_QUIT == s){
            //cout << "quit" << endl;
            break;
        }else{
            //cout << "cmd not found!" << endl;
            break;
        }
    }
    
    adjList->deinitialize();
    delete adjList;
    cin.clear();
}
