#include <iostream>

using namespace std;

void readCards(int cards[]) {
    string input;
    bool isValid, isPrevOne, isNeedSpace;
    isValid = false;

    do {    
        cout << "Enter 4 cards (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) \n";
        getline(cin, input);
        isPrevOne = isNeedSpace = false;
        int i = 0;
        int ctr = 0;
        while (i <= input.length()) {
            if (i == input.length()) {
                if (ctr != 4) {
                    cout << "Masukan tidak valid \n";
                    break;
                } else {
                    isValid = true;
                }
            }
            else if(input[i] == '1' && !isNeedSpace) {
                isPrevOne = true;
            }
            else if(input[i] > '1' && input[i] <= '9' && !isNeedSpace && !isPrevOne) {
                isPrevOne = false;
                isNeedSpace = true;
                cards[ctr % 4] = input[i] - '0';
                ctr++;
            }
            else if ((input[i] == 'Q' || input[i] == 'q' || input[i] == 'J' || input[i] == 'j' || input[i] == 'K' || input[i] == 'k' || input[i] == 'A' || input[i] == 'a') && !isNeedSpace && !isPrevOne) {
                isPrevOne = false;
                isNeedSpace = true;
                switch (input[i]) {
                    case 'A':
                    case 'a':
                        cards[ctr % 4] = 1;
                        break;
                    case 'J':
                    case 'j':
                        cards[ctr % 4] = 11;
                        break;
                    case 'Q':
                    case 'q':
                        cards[ctr % 4] = 12;
                        break;
                    case 'K':
                    case 'k':
                        cards[ctr % 4] = 13;
                        break;
                    default:
                        break;
                }
                ctr++;
            }
            else if (input[i] == '0' && isPrevOne && !isNeedSpace) {
                isPrevOne = false;
                isNeedSpace = true;
                cards[ctr % 4] = 10;
                ctr++;
            }
            else if (input[i] == ' ' && !isPrevOne) {
                isNeedSpace = false;
            }
            else {
                cout << "Masukan tidak valid \n";
                break;
            }
            i++;
        }
    } while (!isValid);


}

int main() {
    int cards[4];
    readCards(cards);
    for (int i = 0; i < 4; i++) {
        cout << cards[i] << endl;
    }
}