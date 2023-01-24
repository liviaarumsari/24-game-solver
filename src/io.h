#ifndef IO_H
#define IO_H

#include <iostream>
#include <random>
#include <fstream>

using namespace std;

/* Procedure to generate 4 random cards and insert to cards array */
void randomCards(int cards[]);

/* Procedure to get cards input from user and input into cards array */
void readCards(int cards[]);

/* Procedure to print main menu */
void mainMenu();

/* Procedure to print splash screen */
void splashScreen();

/* Procedure to write results into file */
void writeFile();

#endif