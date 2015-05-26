//Database of games

#include <iostream>
#include "gameinfo.h"
#include "getinfo.h"
#include "inputerror.h"
#include <fstream>
#include <string>
#include <sstream>


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
    void AddGame();
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

Database::Database() {
    next_game_ = 0;
}

Database::~Database(){};

void Database::AddGame(){
    if (next_game_==100) {
        cout << "\nDatabase full.\n\n";
        return;
    }

    games_[next_game_].set_name(GetInfo<string>("Name: "));
    games_[next_game_].set_developer(GetInfo<string>("Developer: "));
    games_[next_game_].set_year(GetInfo<int>("Year: "));
    cin.ignore(1000,'\n');
    games_[next_game_].set_genre(GetInfo<string>("Genre: "));
    games_[next_game_].set_description(GetInfo<string>("Description: "));
    next_game_++;
}

void Database::DisplayArray() {
    cout << "\nGame Database (" << DatabaseSize() << " game" << (DatabaseSize() == 1 ? "" : "s") << "):\n\n\t***\n";
    for(int i=0;i<next_game_;i++) {
        games_[i].Display();
        cout << "\t***\n";
    }
}

void Database::DisplayRank() {
    cout << "\nGame Database by Rank (" << DatabaseSize() << " game" << (DatabaseSize() == 1 ? "" : "s") << "):\n\n\t***\n";
    for(int i=1;i<=10;i++) {
        for (int j=0;j<next_game_;j++) {
            if (games_[j].grank() == i){
                games_[j].Display();
                cout << "\t***\n";
            }
        }
    }
}


Game* Database::SearchGame() {
    //Search menu answer and loop control
    char answer(0);
    //Search word/number
    string searchword;
    int searchnumber;
    //Search log and counter
    Game* searchlog[100];
    int next_logitem = 0;

    //Get search log
    do {
        cout << "Search by?\n"
             << "1) Name\n"
             << "2) Developer\n"
             << "3) Year\n"
             << "4) Genre\n\n";
        answer = GetInfo<char>(">> ");
        cin.ignore(1000,'\n');
        switch (answer) {
        case '1':
            searchword = GetInfo<string>("Search for: ");
            //create log of search matches
            for (int i=0;i<next_game_;i++) {
                if (games_[i].name() == searchword) {
                    searchlog[next_logitem] = &games_[i];
                    next_logitem++;
                }
            }
            answer = 1;
            break;

        case '2':
            searchword = GetInfo<string>("Search for: ");
            //create log of search matches
            for (int i=0;i<next_game_;i++) {
                if (games_[i].developer() == searchword) {
                    searchlog[next_logitem] = &games_[i];
                    next_logitem++;
                }
            }
            answer = 1;
            break;

        case '3':
            searchnumber = GetInfo<int>("Search for: ");
            //create log of search matches
            for (int i=0;i<next_game_;i++) {
                if (games_[i].year() == searchnumber) {
                    searchlog[next_logitem] = &games_[i];
                    next_logitem++;
                }
            }
            answer = 1;
            break;
        case '4':
            searchword = GetInfo<string>("Search for: ");
            //create log of search matches
            for (int i=0;i<next_game_;i++) {
                if (games_[i].description() == searchword) {
                    searchlog[next_logitem] = &games_[i];
                    next_logitem++;
                }
            }
            answer = 1;
            break;
        default:
            answer = 0;
            InError();
            break;
        }
        //Print out search results
        cout << "\nMatching games:\n\n";
        if (next_logitem == 0) {
            answer = 0;
            cout << "\t**None**\n\n";
        } else {
            for (int i=0;i<next_logitem;i++) {
                cout << "(" << i+1 << ")";
                (*searchlog[i]).Display();
            }
        }

    } while (answer == 0);

    //Choose game from search list
    int chosen_number;
    Game * chosen_game;
    while (1) {
        chosen_number = GetInfo<int>("Enter number of desired game on search list.\n>> ") - 1;
        if (chosen_number < 0 || chosen_number >= next_logitem) {
            cout << "Game not in list.\n";
        } else {
            chosen_game = searchlog[chosen_number];
            break;
        }
    }

    //Return address of chosen game
    return chosen_game;
}


void Database::EditGame(Game& editgame) {

    char answer(0);
    while (1) {
        //Print out game details
        cout << "Game details:\n\n";
        editgame.Display();

        //Edit options
        cout << "Edit what?\n"
             << "1) Name\n"
             << "2) Developer\n"
             << "3) Year\n"
             << "4) Genre\n"
             << "5) Rank\n"
             << "6) Back\n\n";
        answer = GetInfo<char>(">> ");
        cin.ignore(1000,'\n');
        switch (answer) {
        case '1':
            editgame.set_name(GetInfo<string>("New Name: "));
            break;
        case '2':
            editgame.set_developer(GetInfo<string>("New Developer: "));
            break;
        case '3':
            editgame.set_year(GetInfo<int>("New Year: "));
            break;
        case '4':
            editgame.set_genre(GetInfo<string>("New Genre: "));
            break;
        case '5':
            //Promote/Demote Ranking
            int increment;
            do {
                answer = GetInfo<char>("Promote or Demote? (p/d)\n>> ");
                switch (answer) {
                case 'p':
                case 'P':
                    cout << "Current Ranking is: " << editgame.grank() << endl;
                    increment = GetInfo<int>("Promote by how much?\n>> ");
                    editgame.Rankup(increment);
                    cout << "Ranking is now: " << editgame.grank() << endl;
                    break;
                case 'd':
                case 'D':
                    cout << "Current Ranking is: " << editgame.grank() << endl;
                    increment = GetInfo<int>("Demote by how much?\n>> ");
                    editgame.Rankdown(increment);
                    cout << "Ranking is now: " << editgame.grank() << endl;
                    break;
                default:
                    answer = 0;
                    InError();
                }
            } while (answer == 0);
        case '6':
            return;
        default:
            InError();
            break;
        }
    }
}

int Database::DatabaseSize() {return next_game_;}

void Database::PrintDatabase() {

    //Get name of output file
    string filename = GetInfo<string>("\nName of file to save to: ");
    filename.insert(filename.length(),".txt");
    ofstream DatabaseFile(filename.c_str(), ios::out);

    //print to file
    DatabaseFile << "\nGame Database (" << DatabaseSize() << " game" << (DatabaseSize() == 1 ? "" : "s") << "):\n\n\t***\n";
    for(int i=0;i<next_game_;i++) {
         DatabaseFile << "\nName: " << games_[i].name() << endl
                      << "Developer: " << games_[i].developer() << endl
                      << "Year: " << games_[i].year() << endl
                      << "Genre: " << games_[i].genre() << endl
                      << "Description: " << games_[i].description() << endl
                      << "Rank: " << games_[i].grank() << endl << endl;
         DatabaseFile << "\t***\n";
    }
    DatabaseFile.close();
    cout << "\nDatabase saved to " << filename << ".\n";
}

void Database::ReadFile() {

    //Exit if database already full
    if (next_game_ == 100) {
        cout << "\nDatabase full.\n\n";
        return;
    }

    //Get name of input file and add .txt if needed
    string filename = GetInfo<string>("\nName of file to read from: ");
    if (filename.find(".txt") == string::npos) {
        filename.insert(filename.length(),".txt");
    }
    ifstream ReadFile(filename.c_str(), ios::in);
    string line;
    stringstream stringnumber;
    int intnumber;

    //Ignore beginning of file
    for (int i=0;i<5;i++){
        ReadFile.ignore(1000,'\n');
    }

    while (1) {
        //Read in details
        getline(ReadFile,line);
        games_[next_game_].set_name(line.substr(6,'\n'));

        getline(ReadFile,line);
        games_[next_game_].set_developer(line.substr(11,'\n'));

        getline(ReadFile,line);
        stringnumber << line.substr(6,'\n');
        stringnumber >> intnumber;
        stringnumber.str("");
        stringnumber.clear();
        games_[next_game_].set_year(intnumber);

        getline(ReadFile,line);
        games_[next_game_].set_genre(line.substr(7,'\n'));

        getline(ReadFile,line);
        games_[next_game_].set_description(line.substr(13,'\n'));

        getline(ReadFile,line);
        stringnumber << line.substr(6,'\n');
        stringnumber >> intnumber;
        stringnumber.str("");
        stringnumber.clear();
        games_[next_game_].set_rank(intnumber);

        //Next slot in database, exit if full
        next_game_++;
        if (next_game_ == 100) {
            cout << "\nDatabase full.\n\n";
            return;
        }

        //Skip gaps between entries
        for (int i=0;i<3;i++){
            ReadFile.ignore(1000,'\n');
        }

        //Break if end of file
        if (ReadFile.eof()) {
            return;
        }
    }



    ReadFile.close();
}
