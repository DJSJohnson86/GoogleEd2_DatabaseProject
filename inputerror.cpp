// Function to clear input errors

#include <iostream>

using namespace std;

void InError(){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "\tInvalid Input.\n";
}
