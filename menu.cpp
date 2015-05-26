//Menu Placeholder

#include <iostream>
#include "database.h"
#include "inputerror.h"
#include "getinfo.h"

using namespace std;

void Menu() {

    Database database;
    Game* editgame;

    char answer;
    while (1) {

        cout << "\nGame Database project:" << endl
             << "1) Add Game" << endl
             << "2) Search/Edit Games" << endl
             << "3) Display Database" << endl
             << "4) Display Database in order of Ranking" << endl
             << "5) Save to File" << endl
             << "6) Read File" << endl
             << "7) Quit" << endl << endl;
        answer = GetInfo<char>(">> ");
        switch (answer) {
        case '1':
            cout << "\nEnter game information:\n";
            cin.ignore(1000,'\n');
            database.AddGame();
            break;
        case '2':
            if (database.DatabaseSize() == 0) {
                cout << "\n\tDatabase is empty.\n\n";
                break;
            }
            editgame = database.SearchGame();
            database.EditGame(*editgame);
            break;
        case '3':
            if (database.DatabaseSize() == 0) {
                cout << "\n\tDatabase is empty.\n\n";
                break;
            }
            database.DisplayArray();
            break;
        case '4':
            if (database.DatabaseSize() == 0) {
                cout << "\n\tDatabase is empty.\n\n";
                break;
            }
            database.DisplayRank();
            break;
        case '5':
            if (database.DatabaseSize() == 0) {
                cout << "\n\tDatabase is empty.\n\n";
                break;
            }
            cin.ignore(1000,'\n');
            database.PrintDatabase();
            break;
        case '6':
            cin.ignore(1000,'\n');
            database.ReadFile();
            break;
        case '7':
            cout << "\n\tGoodbye!\n";
            return;
            break;
        default:
            InError();
        }

    }
}
