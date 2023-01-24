#include <iostream>
#include <vector>
#include <set>

using namespace std;

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
            swap(num[l], num[i]);
            permuteCards(num, l + 1, r, cards);
            // backtrack
            swap(num[l], num[i]);
        }
    }
}

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

void setToVector (set <vector<int>> cards, vector <vector<int>>& res) {
    for (auto i = cards.begin(); i != cards.end(); i++) {
        vector <int> card;
        for (int j = 0; j < 4; j++) {
            card.push_back((*i)[j]);
        }
        res.push_back(card);
    }
}

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

bool isValidPostfix(char pattern[]) {
    int ctr = 0;
    for (int i = 0; i < 7; i++) {
        if (pattern[i] == 'a') {
            ctr = ctr - 2;
        }
        if (ctr < 0) {
            return false;
        }
        ctr++;
    }
    return ctr == 1;
}


int main() {
    set <vector<int>> cardComb;
    int num[4] = {6,6,6,6};
    vector <vector<char>> opComb;
    char opCombination[100][3];
    vector <vector<int>> cardCombVec;
    vector <string> result;

    permuteCards(num, 0, 3, cardComb);
    for (auto i = cardComb.begin(); i != cardComb.end(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << (*i)[j];
        }
        cout << endl;
    }

    setToVector(cardComb, cardCombVec);
    for (int i = 0; i < cardCombVec.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << cardCombVec[i][j];
        }
        cout << endl;
    }

    permuteOps(opComb);
    for (int i = 0; i < opComb.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << opComb[i][j];
        }
        cout << endl;
    }

    getResults(result, cardCombVec, opComb);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }


    return 0;
}