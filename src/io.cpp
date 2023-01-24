#include <iostream>
#include <random>
#include <fstream>

using namespace std;

/* Procedure to generate 4 random cards and insert to cards array */
void randomCards(int cards[]) {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(1, 13); 

    cout << "These are 4 cards chosen randomly! \n";
    for(int i=0; i<4; i++) {
        cards[i] = distr(gen);
        if (i != 0) {
            cout << " ";
        }
        if (cards[i] > 10 || cards[i] == 1) {
            switch (cards[i])
            {
            case 11:
                cout << "J";
                break;
            case 12:
                cout << "Q";
                break;
            case 13:
                cout << "K";
                break;
            case 1:
                cout << "A";
                break;
            default:
                break;
            }
        }
        else {
            cout << to_string(cards[i]);
        }
    }
    cout << endl;
}

/* Procedure to get cards input from user and input into cards array */
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

/* Procedure to print main menu */
void mainMenu() {
    cout << "============== MENU ==============\n";
    cout << "1. Input your cards\n";
    cout << "2. Randomly pick cards\n";
    cout << "3. Exit\n";

}

/* Procedure to print splash screen */
void splashScreen() {

}

/* Procedure to write results into file */
void writeFile() {
    string input, fileName;
    bool isValid = false;

    cout << "Enter file name: ";
    cin >> input;
    fileName = "../test/" + input + ".txt";

    ofstream resultFile(fileName);
    
    resultFile << "Files can be tricky, but it is fun enough!";
    resultFile.close();
}

int main() {
    int cards[4];
    int randCards[4];
    // readCards(cards);
    // for (int i = 0; i < 4; i++) {
    //     cout << cards[i] << endl;
    // }
    // randomCards(randCards);
    // for (int i = 0; i < 4; i++) {
    //     cout << randCards[i] << endl;
    // }
    writeFile();
}