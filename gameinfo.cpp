//Class to contain and manipulate game info

#include <iostream>


using namespace std;

const int kDefaultRank = 10;


//Game details in class
class Game {

    //private details of game
private:
    string name_;
    string developer_;
    int year_;
    string genre_;
    string description_;
    int rank_;

    //Public access to game details
public:
    //Default details of game when new object is created
    Game();
    //Deletion of game object
    ~Game();

    //External access to write and read game details
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

    //Other functions: Raise/Lower game ranking and display all game details
    void Rankup(int val);
    void Rankdown(int val);
    void Display();
};



//Constructor - Default values
Game::Game() {
    name_ = "Super Mario Bros";
    developer_ = "Nintendo";
    year_ = 1985;
    genre_ = "Platform";
    description_ = "The game that saved the computer game industry.";
    rank_ = kDefaultRank;
}

Game::~Game() {}

//Mutators/Setters - Writing game details
void Game::set_name(string in_name){
    name_ = in_name;
}
void Game::set_developer(string in_developer){
    developer_ = in_developer;
}
void Game::set_year(int in_year){
    year_ = in_year;
}
void Game::set_genre(string in_genre){
    genre_ = in_genre;
}
void Game::set_description(string in_description){
    description_ = in_description;
}
void Game::set_rank(int in_rank){
    rank_ = in_rank;
}

//Getters - Reading game details
string Game::name(){return name_;}
string Game::developer(){return developer_;}
int Game::year(){return year_;}
string Game::genre(){return genre_;}
string Game::description(){return description_;}
int Game::grank(){return rank_;}

//Methods/Functions
void Game::Rankup(int val) {
    if (val < 0){
        cout << "\tNegative numbers are the devil!\n";
    } else {
        rank_ = (rank_-val) < 1 ? 1 : (rank_-val);
    }
}

void Game::Rankdown(int val) {
    if (val < 0){
        cout << "\tNegative numbers are the devil!\n";
    } else {
        rank_ = (rank_+val) > 10 ? 10 : (rank_+val);
    }
}

void Game::Display() {
    cout << "\nName: " << name_ << endl
         << "Developer: " << developer_ << endl
         << "Year: " << year_ << endl
         << "Genre: " << genre_ << endl
         << "Description: " << description_ << endl
         << "Rank: " << rank_ << endl << endl;
}

