#include <iostream>
#include "io.h"
#include "game_solver.h"
#include <chrono>
#include <limits>

using namespace std::chrono;
using namespace std;

int main()
{
    int opt;
    splashScreen();
    mainMenu();
    cout << "\nEnter your option: ";
    cin >> opt;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (opt != 3)
    {
        char save;
        int cards[4];
        vector<string> result;
        if (opt == 1)
        {
            readCards(cards);
        }
        else if (opt == 2)
        {
            randomCards(cards);
        }
        else {
            cout << "The option is not available.\n";
        }

        if (opt == 1 || opt == 2) {
            auto start = high_resolution_clock::now();
            gameSolver(cards, result);
            auto stop = high_resolution_clock::now();
            auto execTime = duration_cast<microseconds>(stop - start);

            if (result.size() > 0)
            {
                cout << endl
                    << result.size() << " solutions found\n";
                for (int i = 0; i < result.size(); i++)
                {
                    cout << i + 1 << ". " << result[i] << endl;
                }
            }
            else
            {
                cout << "There is no solution\n";
            }

            cout << "The execution time is " << execTime.count() << " microseconds.\n";
            cout << "Do you want to save the solution to a file? (Y/N)\n";
            cin >> save;
            bool isSaveValid = false;
            while (!isSaveValid) {
                if (save == 'y' || save == 'Y')
                {
                    writeFile(result, cards, execTime.count());
                    cout << "Solution is succesfully saved!\n";
                }
                if (save == 'y' || save == 'Y' || save == 'n' || save == 'N') {
                    isSaveValid = true;
                }
                else {
                    cout << "Your input is invalid.\n";
                    cout << "Do you want to save the solution to a file? (Y/N)\n";
                    cin >> save;
                }
            }
            
        }
        
        mainMenu();
        cout << "\nEnter your option: ";
        cin >> opt;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Thank you for using this program!\n";
}