//Template to ask for information from user

#include <iostream>
#include "inputerror.h"
#include <typeinfo>

using namespace std;


template <typename type>
type GetInfo (string statement) {
    type gamedetail;
    while (1) {
        cout << statement;
        if (!(cin>>gamedetail)){
            InError();
        } else {
            break;
        }
    }
    return gamedetail;
}

//Special template to get full sentence strings.
template<> inline
string GetInfo<string>(string statement) {
    string gamedetail;
    cout << statement;
    getline(cin,gamedetail);
    return gamedetail;
}
