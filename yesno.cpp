// Function for yes/no questions.

#include <iostream>
#include "inputerror.h"
#include "getinfo.h"

using namespace std;

bool YesNo(string question) {
    char answer(0);
    bool yesno;
    do {
        cout << question << " (y/n)\n";

        answer = GetInfo<char>(">> ");
        switch (answer) {

        // Continue
        case 'y':
        case 'Y':
            yesno = 1;
            break;
        // Quit
        case 'n':
        case 'N':
            yesno = 0;
            break;
        // Repeat question
        default:
            answer = 0;
            InError();
        }
    } while (answer == 0);
    return yesno;
}



