// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: cell.cc
// ====================================================
//

#include "cell.h"
#include "game.h"
using namespace std;

Cell::Cell():numNeighbours(0), game(NULL){}

Cell::~Cell(){}

char Cell::getState() const{
    return this->state;
}

//public accessor for setting state
void Cell::setState(const int &change){
    this->state = change;
}

//public accessor for setting coords
void Cell::setCoords(const int row, const int column){
    this->row = row;
    this->column = column;
}

//public accessor for setting game
void Cell::setGame(Game *game){
    this->game = game;
}

//addNeighbour(*neighbour) adds neighbouring Cell pointer
// to the end of neighbours array, for notification purposes
// increments numNeighbours value, used to track array's index
void Cell::addNeighbour(Cell *neighbour){
    neighbours[numNeighbours] = neighbour;
    ++numNeighbours;
}


//nofiy(change) this function is only invoked on the 0,0 Cell of the grid
// function inturn notifies neighbours of state change aswell as game
void Cell::notify(const int &change){
    //cout << "b3: nofity: " << change << endl;
    int oldState = this->getState();
    this->setState(change);
    
    //nofify 0,0's neighbours
    //for (int i = 0; i < numNeighbours; i++) {
    //    neighbours[i]->notify(change, oldState);
    //}
    notifyNeighbours(change, oldState);
    //notify the game of state change
    this->game->notify(this->row, this->column, oldState, change);
}

void Cell::notifyNeighbours(const int & current, const int & previous)const{
    for (int i = 0; i < numNeighbours; i++) {
        neighbours[i]->notify(current, previous);
    }
}

//notify(current, previous) consumes state values and changes state of Cell
//ONLY if Cell shared same previous state
//funtion inture notifies all neighbours and game of state change as well
void Cell::notify(const int & current, const int & previous){
    // if this cell changes state -> then it must nofify its neighbours
    if (this->getState() == previous) {
        this->setState(current);
        this->game->notify(this->row, this->column, previous, current);
        notifyNeighbours(current, previous);
    }
}