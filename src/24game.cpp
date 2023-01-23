#include <iostream>
#include <string>

using namespace std;

void permuteCards(int num[], int l, int r, int res[][4], int *idx)
{
    // Base case
    if (l == r) {
        for (int i=0; i<4;i++) {
            res[*idx][i] = num[i];
        }
        *idx = *idx + 1;
    }
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            // Swapping done
            swap(num[l], num[i]);
            // Recursion called
            permuteCards(num, l + 1, r, res, idx);
            // backtrack
            swap(num[l], num[i]);
        }
    }
}

void permuteOps(char res[][3], int *idx) {
    char ops[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                res[*idx][0] = ops[i];
                res[*idx][1] = ops[j];
                res[*idx][2] = ops[k];
                *idx = *idx + 1;
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

void permuteCards(char num[], int l, int r, char res[][7], int *idx)
{
    // Base case
    if (l == r) {
        if (isValidPostfix(num)){
            for (int i=0; i<4;i++) {
                res[*idx][i] = num[i];
            }
        *idx = *idx + 1;
        }
    }
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            // Swapping done
            swap(num[l], num[i]);
            // Recursion called
            permuteCards(num, l + 1, r, res, idx);
            // backtrack
            swap(num[l], num[i]);
        }
    }
}



void get24Results(int cards[][4], char ops[][3], char[][7]) {

}

int main() {
    int num[4] = {2,4,6,8};
    int cardCombination[100][4];
    int idxCard = 0;
    char opCombination[100][3];
    int idxOps = 0;

    permuteCards(num, 0, 3, cardCombination, &idxCard);
    cout << idxCard << endl;
    for (int i = 0; i < idxCard; i++) {
        for (int j = 0; j < 4; j++) {
            cout << cardCombination[i][j];
        }
        cout << endl;
    }

    permuteOps(opCombination, &idxOps);
    cout << idxOps;
    for (int i = 0; i < idxOps; i++) {
        for (int j = 0; j < 3; j++) {
            cout << opCombination[i][j];
        }
        cout << endl;
    }


    return 0;
}