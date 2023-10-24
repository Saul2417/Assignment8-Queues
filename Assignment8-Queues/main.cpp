#include <iostream>
#include <iomanip>
#include <string>
#include "input.h"
#include "WarGame.h"

using namespace std;

int menuOption();
void warGameMenu();

int main()
{

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: warGameMenu(); break;
        case 2: //playTowerOfHanoi(); break;
        case 3: //n_QueensMenu(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

//Precondition: None
//Postcondition: Returns an integer
int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 8: Applications using Queues by Saul Merino" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. War" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. T" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. T" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}