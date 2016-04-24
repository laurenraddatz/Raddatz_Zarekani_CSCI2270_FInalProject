#include "Tournament.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    Tournament newTournament;
    string data;
    string userInput, userInput2;
    string name, attribute, health, attack, agility, dominant, inferior;
    ifstream inFile("gods.txt");
    while(getline(inFile, data)){
        stringstream SS(data);
        string temp;
        getline(SS, name, ',');
        getline(SS, attribute, ',');
        getline(SS, health, ',');
        getline(SS, attack, ',');
        getline(SS, agility, ',');
        newTournament.InsertGod(name, attribute, stoi(health), stoi(attack) , stoi(agility));
    }
    cout << "Welcome to the Divine Tournament" << endl;
    cout << "Immortal blood will be shed today" << endl;
     while(userInput != "2"){
        cout << "======Main Menu======" << endl;
        cout << "1. Choose Your Champion" << endl;
        cout << "2. Quit" << endl;
        getline(cin, userInput);

        if(userInput == "1"){
            cout << "1. Choose a God" << endl;
            cout << "2. Create a God" << endl;
            getline(cin, userInput2);
            if(userInput2 == "2"){
                cout << "Choose Your God's Name" << endl;
                getline(cin, name);
                cout << "Choose Your God's Attribute" << endl;
                getline(cin, attribute);
                cout << "Choose Your God's dominant stat(attack, health, or agility)" << endl;
                getline(cin, dominant);
                cout << "Choose Your God's inferior stat(attack, health, or agility)" << endl;
                getline(cin, inferior);
                newTournament.makeGod(name, attribute, dominant, inferior);
            }
        }
     }
    return 0;
}
