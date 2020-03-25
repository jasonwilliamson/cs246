// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: game.cc
// ====================================================
//

#include <iostream>
#include "game.h"
#define COLOURS 5
#define WHITE 0
#define BLACK 1
#define RED 2
#define GREEN 3
#define BLUE 4
using namespace std;


Game::Game():theGrid(NULL), gridSize(0),win(false), notification(NULL){
    for (int i = 0; i < COLOURS; i++) {
        colours[i] = 0;
    }
}


Game::~Game(){
    if (theGrid != NULL) {
        clearGame();
    }
    notification = NULL;
}


//init(n, gameNotification) consumes n and int representing the grid size
// and gameNotification a pointer to GameNotification used to update the view
void Game::init(int n, GameNotification *gameNotification){
    
    if (theGrid != NULL) {
        clearGame();
    }
    this->notification = gameNotification;
    this->gridSize = n;
    theGrid = new Cell*[n];
    for (int i = 0; i < n; i++) {
        theGrid[i] = new Cell[n];
        for (int j = 0; j < n; j++) {
            theGrid[i][j].setCoords(i, j);
            theGrid[i][j].setState(0);
            theGrid[i][j].setGame(this);
            colours[WHITE] += 1;
        }
    }
    //setup Cell's neighbours
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int row = i;
            int col = j;
            if ((col + 1)< n) {
                //cout << "row: " << i << " col: " << j << endl;
                //cout << "add row:" << i << " col: " << j+ 1 << endl;
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
            }
            if ((col - 1) >= 0) {
                //cout << "row: " << i << " col: " << j << endl;
                //cout << "add row:" << i << " col: " << j- 1 << endl;
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
            }
            if ((row + 1) < n) {
                //cout << "row: " << i << " col: " << j << endl;
                //cout << "add row:" << i + 1 << " col: " << j << endl;
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
            }
            if ((row - 1) >= 0) {
                //cout << "row: " << i << " col: " << j << endl;
                //cout << "add row:" << i - 1 << " col: " << j << endl;
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
            }
        }
    }
}


//int(row, column, state) sets individual Cell's in the grid to the consumed state
// function checks for valid input before making changes to grid
// function invoked by the controller
// function notifies view of all changes to Cell's state
void Game::init(int row, int column, int state){
    if (((row >= 0) && (row < gridSize)) &&
        ((column >= 0) && (column < gridSize)) &&
        ((state >= WHITE) && (state <= BLUE))){
        int oldState = theGrid[row][column].getState();
        theGrid[row][column].setCoords(row, column);
        theGrid[row][column].setState(state);
        colours[oldState] -= 1;
        colours[state] += 1;
        //notify view
        notification->notify(row, column, state);
    }
}


//change(state) consumes const int reference, it has been invoked by controller
// function notifies the 0,0 Cell of it's state change
void Game::change(const int &state){
    //theGrid[0][0].setState(state);
    //cout << "b2 change: " << state << endl;
    theGrid[0][0].notify(state);
}


// notify(row, column, oldstate, newState) consumes row, column values of Cell that issues notification
// along with the Cell's oldState and newState...function call issued from Cell..
// function to check for win condition and notify the view of changes
void Game::notify(int row, int column, unsigned int oldState, unsigned int newState){
    //track number of single colours
    colours[oldState] -= 1;
    colours[newState] += 1;
    int total = colours[newState];
    int winCount = gridSize*gridSize;
    //check for win condition here
    //cout << "total: " << winCount << endl;
    //cout << "colours total: " << total << endl;
    if ( total == (winCount)) {
        //cout << "inside:total: " << winCount << endl;
        //cout << "inside:colours total: " << total << endl;
        win = true;
    }
    //notify view of changes
    //cout << "b3.5 Game::notify " << endl;
    notification->notify(row, column, newState);
}

//clears the grid
void Game::clearGame(){
    for (int i = 0; i < gridSize; i++) {
        delete [] theGrid[i];
    }
    delete [] theGrid;
    theGrid = NULL;
    
    for (int i = 0; i < COLOURS; i++) {
        colours[i] = 0;
    }
}


// The following method is used to determine if the game has been won.
bool Game::isWon()const{
    return win;
}