#include "Tournament.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h> // for atoi
using namespace std;

int main()
{
    Tournament newTournament;
    bool found = false;
    string userInput, userInput2;
    string name, attribute, health, attack, agility, dominant, inferior;
    cout << "Welcome to the Divine Tournament" << endl;
    cout << "Immortal blood will be shed today" << endl;
     while(userInput != "3"){
        cout << "======Main Menu======" << endl;
        cout << "1. Choose Your Champion" << endl;
        cout << "2. Join the Audience" << endl;
        cout << "3. Quit" << endl;
        getline(cin, userInput);

        if(userInput == "1"){
            cout << "1. Choose a God" << endl;
            cout << "2. Create a God" << endl;
            getline(cin, userInput2);
            if(userInput2 == "2"){ //make god
                cout << "Choose Your God's Name" << endl;
                getline(cin, name);
                attribute = "";
                while (attribute != "normal" and attribute != "lightning" and attribute != "fire" and attribute != "water" and attribute != "earth" ){ //make sure player choses available attribute
                    cout << "Choose Your God's Attribute (normal, lightning, fire, water, or earth)" << endl;
                    getline(cin, attribute);
                }
                dominant = "";
                while (dominant != "attack" and dominant != "health" and dominant != "agility"){ //make sure player choses available stat
                    cout << "Choose Your God's dominant stat (attack, health, or agility)" << endl;
                    getline(cin, dominant);
                }
                inferior = "";
                while (inferior != "attack" and inferior != "health" and inferior != "agility"){ //make sure player choses available stat
                    cout << "Choose Your God's inferior stat (attack, health, or agility). Your inferior stat must be different than your dominant stat." << endl;
                    getline(cin, inferior);
                    while(inferior==dominant){
                        cout << "Your dominant and inferior stats are the same. Please choose a different inferior stat (attack, health, or agility)" << endl;
                        getline(cin, dominant);
                    }
                }
                newTournament.makeGod(name, attribute, dominant, inferior);
            }else if(userInput2 == "1"){ //choose god
                newTournament.printGods(1);
                while(found == false){
                    cout << "Choose your Champion" << endl;
                    getline(cin, name);
                    found = newTournament.findGod(name);
                }
                found = false; //reset found
                cout << "You have chosen " << name << endl;
                newTournament.runTournament();

            }
        }else if(userInput == "2"){
            newTournament.runTournament();
        }
     }
    return 0;
}
