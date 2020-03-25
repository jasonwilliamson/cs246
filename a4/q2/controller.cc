// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: controller.cc
// ====================================================
//

#include "controller.h"
#include "game.h"
#include "textdisplay.h"
// Uncomment for part (b)
//#include "graphicdisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

Controller::Controller(){
    game = new Game();
    td = NULL;
    gameStarted = false;
    // TODO - add any code needed for part (b)
}

/*
 * Update the View(s) to indicate the new game state
 */
// most probably called from game ,, then calls view's notify to update
void Controller::notify(int row, int column, unsigned int state){
    char c = '0' + state;
    //cout << "b4: controller notify " << c << endl;
    td->notify(row, column, c);
}

/*
 * Called when command init is received
 */
void Controller::init(istream & input, Game & g){
    int row, col, state;
    while (true) {
        if (!(input >> row)) {
            if (input.eof()) break;
            else {
                input.clear();
                input.ignore();
                continue;
            }
        }
        if (!(input >> col)) {
            if (input.eof()) break;
            else {
                input.clear();
                input.ignore();
                continue;
            }
        }
        
        if ((-1 == row)&&(-1 == col)) {
            break;
        }else{
            if (!(input >> state)) {
                if (input.eof()) break;
                else {
                    input.clear();
                    input.ignore();
                    continue;
                }
            }
            game->init(row, col, state);
        }
    }
}


bool Controller::checkWin(int movesLeft) const {
    if(game->isWon() && movesLeft != 0){
        cout << "Won" << endl;
        return true;
    }
    return false;
}

void Controller::play(){
    //srand(time(NULL));
    int moves = 0;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "new") {
            //cannot begin new game once game has started
            if (!gameStarted) {
                int gridDimension;
                cin >> gridDimension;
                game->init(gridDimension, this);
                delete td;
                td = new TextDisplay(gridDimension);
                // Uncomment for part (b)
                // gd = new GraphicDisplay(n);
            
                moves = 0;
            }
        }
        // the ? command is only needed for part (b)
        // when graphics command line is enabled
        /*   else if (cmd == "?"){
         cout << "White: 0" << endl;
         cout << "Black: 1" << endl;
         cout << "Red:   2" << endl;
         cout << "Green: 3" << endl;
         cout << "Blue:  4" << endl;
         
         }
         */
        else if (cmd == "init") { //go into initialization mode
            init(cin, *game);
            td->print(cout); //display the board
            if (checkWin(moves)){
                break;
            }
        }
        else if (cmd == "include"){ //initialization from a file
            string file;
            cin >> file;
            ifstream input(file.c_str());
            init(input, *game);
            td->print(cout);
            if (checkWin(moves)){
                break;
            }
        }
        else if (cmd == "switch") { //always switch the (0,0) location
            if (checkWin(moves)){
                break;
            }
            if(moves > 0){
                int next; //get the state we have switched to
                if (cin >> next && (next >= 0 && next <= 4)){
                    //custom call to method responsible for switching (0,0)
                    //cout << "b1: switch: " << next << endl;
                    game->change(next);
                    //print the updated Textdisplay
                    td->print(cout);
                    --moves;
                    if (moves == 1) {
                        cout << moves << " move left" << endl;
                    }
                    else {
                        cout << moves << " moves left" << endl;
                    }
                    if(game->isWon()){
                        cout << "Won" << endl;
                        gameStarted = false;
                        break;
                    }
                    if(moves == 0){
                        cout << "Lost" << endl;
                        gameStarted = false;
                        break;
                    }
                }
                else cerr << "Invalid move" << endl;
            }
        }
        else if (cmd == "game"){
            if (!gameStarted) {
                gameStarted = true;
                cin >> moves;
                if (moves < 0) {
                    moves = 0;
                }
                else if (moves == 1) {
                    cout << moves << " move left" << endl;
                }
                else {
                    cout << moves << " moves left" << endl;
                }
                if (checkWin(moves)){
                    break;
                }
            }
        }
    }
}

Controller::~Controller(){
    delete td;
    delete game;
}
