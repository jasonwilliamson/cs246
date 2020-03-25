// ====================================================
// Jason Williamson (20552360)
// CS 246 Fall 2015
// Assignment 04, Problem 2
// File: view.cc
// ====================================================
//

#include "view.h"

View::View(int n):gridSize(n){}

View::~View(){}  // not sure if needed , since its virtual def in header

//methods are virtual , abstract class, do we want a constructor at all?