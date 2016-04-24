#include "Tournament.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string data;
    string name, attribute, health, attack, agility;
    ifstream inFile("gods.txt");
    while(getline(inFile, data)){
        stringstream SS(data);
        string temp;
        getline(SS, name, ',');
        getline(SS, attribute, ',');
        getline(SS, health, ',');
        getline(SS, attack, ',');
        getline(SS, agility, ',');
        cout << name << attribute << health << attack << agility << endl;
    }
    cout << "Welcome to the Divine Tournament" << endl;
    cout << "Immortal blood will be shed today" << endl;
    return 0;
}
