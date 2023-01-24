#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* Implementation of swap function */
void swapValue(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to permute 4 number of cards */
void permuteCards(int num[], int l, int r, set <vector<int>>& cards)
{
    if (l == r) {
        vector <int> card;
        for (int i=0; i<4;i++) {
            card.push_back(num[i]);
        }
        cards.insert(card);
    }
    else {
        for (int i = l; i <= r; i++) {
            swapValue(&num[l], &num[i]);
            permuteCards(num, l + 1, r, cards);
            // backtrack
            swapValue(&num[l], &num[i]);
        }
    }
}

/* Function to make all the combination of the operator */
void permuteOps(vector <vector<char>>& res) {
    char ops[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                vector <char> comb;
                comb.push_back(ops[i]);
                comb.push_back(ops[j]);
                comb.push_back(ops[k]);
                res.push_back(comb);
        }            
        }
    }
    
}

/* Function to transform set to vector */
void setToVector (set <vector<int>> cards, vector <vector<int>>& res) {
    for (auto i = cards.begin(); i != cards.end(); i++) {
        vector <int> card;
        for (int j = 0; j < 4; j++) {
            card.push_back((*i)[j]);
        }
        res.push_back(card);
    }
}

/* Function to compute based on the operator */
double evaluate(double a, double b, char ops) {
    switch (ops)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a / b;
    }
}

/* Function to get all correct expression that results in 24 */
void getResults(vector<string>& res, vector <vector<int>> cards, vector <vector<char>> ops) {
    for (int i = 0; i < cards.size(); i++) {
        for (int j = 0; j < ops.size(); j++) {
            double card1 = (double) cards[i][0];
            double card2 = (double) cards[i][1];
            double card3 = (double) cards[i][2];
            double card4 = (double) cards[i][3];

            double num12 = evaluate(card1, card2, ops[j][0]);
            double num23 = evaluate(card2, card3, ops[j][1]);
            double num34 = evaluate(card3, card4, ops[j][2]);

            string op1 = " " + string(1, ops[j][0]) + " ";
            string op2 = " " + string(1, ops[j][1]) + " ";
            string op3 = " " + string(1, ops[j][2]) + " ";

            // test every possible precedence
            double prec1 = evaluate(evaluate(num12, card3, ops[j][1]), card4, ops[j][2]);
            if (prec1 == 24) {
                string sol1 = "(((" + to_string(cards[i][0]) + op1 + to_string(cards[i][1]) + ")" + op2 + to_string(cards[i][2]) + ")" + op3 + to_string(cards[i][3]) + ")";
                res.push_back(sol1);
            }
            double prec2 = evaluate(num12, num34, ops[j][1]);
            if (prec2 == 24) {
                string sol2 = "((" + to_string(cards[i][0]) + op1 + to_string(cards[i][1]) + ")" + op2 + "(" + to_string(cards[i][2]) + op3 + to_string(cards[i][3]) + "))";
                res.push_back(sol2);
            }
            double prec3 = evaluate(evaluate(card1, num23, ops[j][0]), card4, ops[j][2]);
            if (prec3 == 24) {
                string sol3 = "((" + to_string(cards[i][0]) + op1 + "(" + to_string(cards[i][1]) + op2 + to_string(cards[i][2]) + "))" + op3 + to_string(cards[i][3]) + ")";
                res.push_back(sol3);
            }
            double prec4 = evaluate(card1, evaluate(num23, card4, ops[j][2]), ops[j][0]);
            if (prec4 == 24) {
                string sol4 = "(" + to_string(cards[i][0]) + op1 + "((" + to_string(cards[i][1]) + op2 + to_string(cards[i][2]) + ")" + op3 + to_string(cards[i][3]) + "))";
                res.push_back(sol4);
            }
            double prec5 = evaluate(card1, evaluate(card2, num34, ops[j][1]), ops[j][0]);
            if (prec5 == 24) {
                string sol5 = "(" + to_string(cards[i][0]) + op1 + "(" + to_string(cards[i][1]) + op2 + "(" + to_string(cards[i][2]) + op3 + to_string(cards[i][3]) + ")))";
                res.push_back(sol5);
            }
        }
    }
}

void gameSolver(int cards[], vector <string>& result) {
    set <vector<int>> cardComb;
    vector <vector<char>> opComb;
    vector <vector<int>> cardCombVec;
    
    permuteCards(cards, 0, 3, cardComb);
    setToVector(cardComb, cardCombVec);
    permuteOps(opComb);
    getResults(result, cardCombVec, opComb);
}
