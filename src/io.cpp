#include <iostream>
#include <random>
#include <fstream>
#include <vector>

using namespace std;

/* Procedure to print cards */
void printCards(int cards[])
{
    string cardsText[4];

    for (int i = 0; i < 4; i++)
    {
        switch (cards[i])
        {
        case 1:
            cardsText[i] = "A";
            break;
        case 11:
            cardsText[i] = "J";
            break;
        case 12:
            cardsText[i] = "Q";
            break;
        case 13:
            cardsText[i] = "K";
            break;
        default:
            cardsText[i] = to_string(cards[i]);
            break;
        }
    }
    cout << R"(
        ===============  CARDS  ================
        ========================================
        ||                                    ||
                      )" << cardsText[0] << "  " << cardsText[1] << "  " << cardsText[2] << "  " << cardsText[3] << R"(             
        ||                                    ||
        ========================================
        ========================================
    )";
}

/* Procedure to generate 4 random cards and insert to cards array */
void randomCards(int cards[])
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 13);

    cout << "Your four cards are as follows. \n";
    for (int i = 0; i < 4; i++)
    {
        cards[i] = distr(gen);
    }
    printCards(cards);
}

/* Procedure to get cards input from user and input into cards array */
void readCards(int cards[])
{
    string input;
    bool isValid, isPrevOne, isNeedSpace;
    isValid = false;

    do
    {
        cout << "Enter 4 cards (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) \n";
        getline(cin, input);
        isPrevOne = isNeedSpace = false;
        int i = 0;
        int ctr = 0;
        while (i <= input.length())
        {
            if (i == input.length())
            {
                if (ctr != 4)
                {
                    cout << "Input is invalid. Please input again! \n";
                    break;
                }
                else
                {
                    isValid = true;
                }
            }
            else if (input[i] == '1' && !isNeedSpace)
            {
                isPrevOne = true;
            }
            else if (input[i] > '1' && input[i] <= '9' && !isNeedSpace && !isPrevOne)
            {
                isPrevOne = false;
                isNeedSpace = true;
                cards[ctr % 4] = input[i] - '0';
                ctr++;
            }
            else if ((input[i] == 'Q' || input[i] == 'q' || input[i] == 'J' || input[i] == 'j' || input[i] == 'K' || input[i] == 'k' || input[i] == 'A' || input[i] == 'a') && !isNeedSpace && !isPrevOne)
            {
                isPrevOne = false;
                isNeedSpace = true;
                switch (input[i])
                {
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
            else if (input[i] == '0' && isPrevOne && !isNeedSpace)
            {
                isPrevOne = false;
                isNeedSpace = true;
                cards[ctr % 4] = 10;
                ctr++;
            }
            else if (input[i] == ' ' && !isPrevOne)
            {
                isNeedSpace = false;
            }
            else
            {
                cout << "Input is invalid. Please input again! \n";
                break;
            }
            i++;
        }
    } while (!isValid);
    printCards(cards);
}

/* Procedure to print main menu */
void mainMenu()
{
    cout << R"(
            ================  MENU  ================
            ========================================
            ||        1. Input your cards         ||
            ||       2. Randomly pick cards       ||
            ||              3. Exit               ||
            ========================================
            ========================================
    )" << endl;
}

/* Procedure to print splash screen */
void splashScreen()
{
    cout << "      _______  _   ___    _______  _______  __   __  _______\n     |       || | |   |  |       ||   _   ||  |_|  ||       |\n     |____   || |_|   |  |    ___||  |_|  ||       ||    ___|\n      ____|  ||       |  |   | __ |       ||       ||   |___\n     | ______||___    |  |   ||  ||       ||       ||    ___|\n     | |_____     |   |  |   |_| ||   _   || ||_|| ||   |___\n     |_______|    |___|  |_______||__| |__||_|   |_||_______|";
    cout << R"( 
                 ____    ____    ____    ____
                |2   |  |A   |  |Q   |  |4   |
                |(\/)|  | /\ |  | /\ |  | &  |
                | \/ |  | \/ |  |(__)|  |&|& |
                |   2|  |   A|  | /\Q|  | | 4|   
                `----`  `----'  `----'  `----')"
         << "\n\n";
}

/* Procedure to write results into file */
void writeFile(vector<string> result, int cards[], int execTime)
{
    string input, fileName;
    bool isValid = false;

    cout << "Enter file name: ";
    cin >> input;
    fileName = "../test/" + input + ".txt";

    ofstream resultFile(fileName);

    resultFile << "Cards:";
    for (int i = 0; i < 4; i++)
    {
        resultFile << " " << cards[i];
    }
    resultFile << endl
               << result.size() << " solutions found\n";

    for (int i = 0; i < result.size(); i++)
    {
        resultFile << result[i] << endl;
    }
    resultFile << "The execution time is " << execTime << " microseconds";
    resultFile.close();
}
