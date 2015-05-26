#ifndef GAMEINFO_H_INCLUDED
#define GAMEINFO_H_INCLUDED

#include <iostream>

using namespace std;

class Game {

public:
    Game();
    ~Game();

    void set_name(string in_name);
    string name();
    void set_developer(string in_developer);
    string developer();
    void set_year(int in_year);
    int year();
    void set_genre(string in_genre);
    string genre();
    void set_description(string in_description);
    string description();
    void set_rank(int in_rank);
    int grank();

    void Rankup(int val);
    void Rankdown(int val);
    void Display();

private:
    string name_;
    string developer_;
    int year_;
    string genre_;
    string description_;
    int rank_;
};

#endif // GAMEINFO_H_INCLUDED
