#ifndef GAME_SOLVER_H
#define GAME_SOLVER_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* Procedure to permute 4 number of cards */
void permuteCards(int num[], int l, int r, set <vector<int>>& cards);

/* Procedure to make all the combination of the operator */
void permuteOps(vector <vector<char>>& res);

/* Procedure to transform set to vector */
void setToVector (set <vector<int>> cards, vector <vector<int>>& res);

/* Function to compute based on the operator */
double evaluate(double a, double b, char ops);

/* Procedure to get all correct expression that results in 24 */
void getResults(vector<string>& res, vector <vector<int>> cards, vector <vector<char>> ops);

/* Procedure to solve 24 game with an array of cards*/
void gameSolver(int cards[], vector <string>& result);

#endif