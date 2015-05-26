#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <iostream>
#include "gameinfo.h"



using namespace std;

const int kMaxGames = 100;


class Database {

private:
    //Game database
    Game games_[kMaxGames];
    //Next free slot in array
    int next_game_;


public:
    //Constructor and Destructor
    Database();
    ~Database();


    //Add game
    void AddGame();//string in_name, string in_developer, int in_year, string in_genre,string in_description);
    //Search database
    Game* SearchGame();
    //Edit game details/rank
    void EditGame(Game& editgame);
    //Display database in order of entry
    void DisplayArray();
    //Display database in order of rank
    void DisplayRank();
    int DatabaseSize();
    void PrintDatabase();
    void ReadFile();
};

#endif // DATABASE_H_INCLUDED
