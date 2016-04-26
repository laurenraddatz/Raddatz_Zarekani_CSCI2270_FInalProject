#include "Tournament.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime> //for srand
using namespace std;

Tournament::Tournament(){
    InitializeTourny();
    srand(time(NULL)); //for random number generator

}

Tournament::~Tournament(){

}
Gods* Tournament::Fight(Gods *a, Gods *b){
    Gods fighterA = *a;
    Gods fighterB = *b;
    float modifierA, modifierB;
    while(fighterA.health >= 0 and fighterB.health >= 0){ //both Gods still standing
        modifierA = (rand() % 100)/100.00; //percentage
        modifierB = (rand() % 100)/100.00; //percentage
        if(fighterA.attribute != "normal" and fighterB.attribute != "normal"){
            // case where fighterA gets advantage
            if((fighterA.attribute == "water" and fighterB.attribute == "fire") or (fighterA.attribute == "lightning" and fighterB.attribute == "water") or (fighterA.attribute == "earth" and fighterB.attribute == "lightning") or (fighterA.attribute == "fire" and fighterB.attribute == "earth")){
                modifierA += .2;
                modifierB -= .2;
            }
            // case where fighterB gets advantage
            else if((fighterB.attribute == "water" and fighterA.attribute == "fire") or (fighterB.attribute == "lightning" and fighterA.attribute == "water") or (fighterB.attribute == "earth" and fighterA.attribute == "lightning") or (fighterB.attribute == "fire" and fighterA.attribute == "earth")){
                modifierB += .2;
                modifierA -= .2;
            }
        }  
        if(fighterB.agility * modifierB - fighterA.agility * modifierA > 5){ //whether the attack misses or hits
            fighterA.health = fighterA.health - (fighterB.attack * modifierB);
        }
        if(fighterA.agility * modifierA - fighterB.agility * modifierB > 5){ //whether the attack misses or hits
            fighterB.health = fighterB.health - (fighterA.attack * modifierA);
        }
    }
    if(fighterA.health > fighterB.health){
        return a;
    }else{
        return b;
    }
}
void Tournament::deleteGod(int index){
    godList[index] = NULL;
}
bool Tournament::findGod(std::string in_name){
    for(int i = 0; i < godSize; i++){
        if(godList[i]->name == in_name){
            player = godList[i];
            return true;
        }
    }
    return false;
}
void Tournament::InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility, std::string in_speech){
    Gods *newGod = new Gods(in_name, in_attribute, in_health, in_attack, in_agility, in_speech);
        int initialI = rand() % 8;
        for(int i = initialI; i < godSize + initialI ; i++){
            if(i == godSize){
                i = 0;
            }
            if(godList[i] == NULL){
                godList[i] = newGod;
                break;
            }
    }
}
void Tournament::makeGod(string in_name, string in_attribute, string in_dominantStat, string in_inferiorStat, string speech){
    deleteGod(rand() % 10);
    int agility, health, attack;
    agility = 0;
    health = 0;
    attack = 0;
    if(in_dominantStat == "agility"){
        agility = rand() % 45 + 80; //in between 80 and 125
    }else if(in_dominantStat == "health"){
        health = rand() % 45 + 80;
    }else if(in_dominantStat == "attack"){
        attack = rand() % 45 + 80;
    }
    if(in_inferiorStat == "agility"){
        agility = rand() % 100 + 1; //in between 1 and 100
    }else if(in_inferiorStat == "health"){
        health = rand() % 100 + 1;
    }else if(in_inferiorStat == "attack"){
        attack = rand() % 100 + 1;
    }
    if(agility == 0){
        agility = rand() % 50 + 50; //in between 50 and 100
    }else if(health == 0){
        health = rand() % 50 + 50;
    }else if(attack == 0){
        attack = rand() % 50 + 50;
    }
    InsertGod(in_name, in_attribute, health, attack, agility, speech);
    cout << "The Earth trembles, the air burns, and the Heavens rage. A new God has emerged." << endl;
    cout << "Their name is " << in_name << " of the attribute " << in_attribute << endl;
    cout << " of the attack " << attack << " of the health " << health << " and the agility " << agility << endl;


}

// Returns the root node for use in functions
Gods* Tournament::getRoot()
{
    return root;
}

// the user chooses which tier to print (choice)
void Tournament::printGods(int choice){
    cout << "Gods in this tier:" << endl;
    if(choice == 1){
        for(int i = 0; i < 8; i++){
            cout << godList[i]->name << endl;
        }
    }
    else if(choice == 2){
        for(int i = 0; i < 4; i++){
    //        cout << godList2[i]->name << endl;
        }
    }
    else if(choice == 3){
        for(int i = 0; i < 2; i++){
   //         cout << godList3[i]->name << endl;
        }
    }
}

// Clear the tournament bracket, input the root node
void Tournament::deleteAll(Gods *node){
    if(node->left != NULL)
        deleteAll(node->left);
    if(node->right != NULL)
        deleteAll(node->right);
    //cout<<"Deleting: "<<node->name<<endl;
    delete node;
}
void Tournament::readFile(){
    string data, temp;
    string name, attribute, health, attack, agility, speech;
    ifstream inFile("gods.txt");
    while(getline(inFile, data)){
        stringstream SS(data);
        getline(SS, name, ',');
        getline(SS, attribute, ',');
        getline(SS, health, ',');
        getline(SS, attack, ',');
        getline(SS, agility, ',');
        getline(SS, speech, ',');
        InsertGod(name, attribute, atoi(health.c_str()), atoi(attack.c_str()) , atoi(agility.c_str()), atoi(speech.c_str()));
    }
}
void Tournament::findGodHistory(string name, Gods* temp){
    int countingKids = 0;
    if(temp == NULL){
        for(int i = 0; i < godSize; i++){
            if(godList[i]->name == name){
                player = godList[i];
                cout << godList[i]->name << " Attribute: " << godList[i]->attribute << " Health: " << godList[i]->health << " Attack: " << godList[i]->attack << " Agility: " << godList[i]->agility << endl;
                cout << "Winning Speech: " << godList[i]->speech << endl;
                cout << "This Deity has not fought yet. Start a new tournament to see what this immortal is made out of!" << endl;
            }
        }
        goto label;
    }
    if(temp->name == name){
        cout << temp->name << " Attribute: " << temp->attribute << " Health: " << temp->health << " Attack: " << temp->attack << " Agility: " << temp->agility << endl;
        cout << "Winning Speech: " << temp->speech << endl;
        countingKids++;
        while(temp->left != NULL){
            countingKids++;
            if(temp->left->name == name){
                temp = temp->left;
            }else if(temp->right->name == name){
                temp = temp->right;
            }
        }
        int whatRound = 1;
        while(temp->parent != NULL and countingKids > 0){
            temp = temp->parent;
            cout << "Round " << whatRound << " " << temp->left->name << " fought " << temp->right->name << endl;
            cout << temp->name << " was the victor!" << endl;
            countingKids--;
            whatRound++;
        }
        goto label;
    }
    if (temp->left != NULL){
        findGodHistory(name, temp->left);
    }
     if (temp->right != NULL){
        findGodHistory(name, temp->right);
    }
    label:;
}
void Tournament::InitializeTourny(){
    godSize = 8;
    *godList = new Gods[godSize];
    for(int i = 0; i < godSize; i++){
        godList[i] = NULL;
    }
    readFile(); //reshuffle list
}
Gods* Tournament::manualFight(Gods *a, Gods *b){
    cout << "Take Up Your Arms" << endl;
    cout << "It's Time to Earn Your Divinity" << endl;
    Gods playerChar = *a;
    Gods fighterB = *b;
    string userInput;
    int turn = 0;
    float playerModifierAgility, playerModifierAttack, playerModifierHealth, modifierB;
    while(playerChar.health >= 0 and fighterB.health >= 0){ //both Gods still standing
        userInput = "";
        cout << "Turn " << turn << ":" << endl;
        while(userInput != "attack" and userInput != "defense" and userInput != "speed" and userInput != "balanced"){
            cout << "Will you focus on attack, defense, speed, or a balanced form?" << endl;
            getline(cin, userInput);
        }
        if(userInput == "attack"){
            playerModifierAttack = (rand() % 60 + 40)/100.00; //percentage
            playerModifierAgility = (rand() % 80)/100.00;
            playerModifierHealth = 0;
        }else if(userInput == "defense"){
            playerModifierAttack = 0; //percentage
            playerModifierAgility = (rand() % 80)/100.00;
            playerModifierHealth = (rand() % 40)/100.00;
        }else if(userInput == "speed"){
            playerModifierAttack = 0; //percentage
            playerModifierAgility = (rand() % 60 + 40)/100.00;
            playerModifierHealth = 0;
        }else if(userInput == "balanced"){
            playerModifierAttack = 0; //percentage
            playerModifierAgility = (rand() % 100 + 10)/100.00;
            playerModifierHealth = 0;
        }

        modifierB = (rand() % 100)/100.00; //percentage
        cout << modifierB << " " << playerModifierAgility << endl;
        if(fighterB.agility * modifierB - playerChar.agility * playerModifierAgility > 5){ //whether the attack misses or hits
            playerChar.health = playerChar.health - ((fighterB.attack * modifierB) * (1.00 - playerModifierHealth));
            cout << "You took " << ((fighterB.attack * modifierB) * (1.00 - playerModifierHealth)) << " damage" << endl;
        }else{
            cout << "Enemy Attack Missed!" << endl;
        }
        if(playerChar.agility * playerModifierAgility - fighterB.agility * modifierB > 5){ //whether the attack misses or hits
            fighterB.health = fighterB.health - ((playerChar.attack * playerModifierAgility) * (1.00 + playerModifierAttack));
            cout << "Enemy takes " << ((playerChar.attack * playerModifierAgility) * (1.00 + playerModifierAttack)) << " damage" << endl;
        }else{
            cout << "Your Attack Missed!" << endl;
        }
        turn++;
    }
    if(playerChar.health > fighterB.health){
        return a;
    }else{
        cout << "Game Over" << endl;
        return b;
    }
}
void Tournament::runTournament(){
    int countMatch = 0;
    round = 1;
    Gods * winner;
    Gods **godListTemp;
    cout << "+++The Tournament Will Now Begin+++" << endl;
    for (int i = 0; i < godSize; i = i + 2){
        cout << godList[i]->name << " vs " << godList[i+1]->name << endl;
    }
    for(int j = 0; j < 3; j++){ //loop for each tournament tier
        godListTemp = new Gods*[godSize];
        for (int i = 0; i < godSize; i++){ //copy godList
            godListTemp[i] = godList[i];
        }
        godSize = godSize / 2; //half godSize for the next tier
        *godList = new Gods[godSize];
        cout << "+++Round " << round << endl;
        countMatch = 0; //we start the following loop at match 0
        for (int i = 0; i < godSize*2; i = i + 2){ //loops through each match of the tier
            winner = new Gods();
            if(godListTemp[i] != player and godListTemp[i+1] != player){ //have the first 2 gods in the list fight
                *winner = *Fight(godListTemp[i],godListTemp[i+1]); //create a clone of the winning God set to a new location
                cout << godListTemp[i]->name << " vs " << godListTemp[i+1]->name << endl;
                cout << winner->name << " is the winner" << endl;
                winner->left = godListTemp[i];
                godListTemp[i]->parent = winner;
                winner->right = godListTemp[i+1];
                godListTemp[i+1]->parent = winner;
                godList[countMatch] = winner;
            }else{
                cout << godListTemp[i]->name << " vs " << godListTemp[i+1]->name << endl;
                if(godListTemp[i] == player){
                    *winner = *manualFight(godListTemp[i],godListTemp[i+1]);
                }else{
                    *winner = *manualFight(godListTemp[i+1],godListTemp[i]);
                }
                if(godListTemp[i]->name == winner->name){
                    player = winner;
                }                
                cout << winner->name << " is the winner" << endl;
                winner->left = godListTemp[i];
                godListTemp[i]->parent = winner;
                winner->right = godListTemp[i+1];
                godListTemp[i+1]->parent = winner;
                godList[countMatch] = winner;
            }
            countMatch++;
        }
        round++;
    }
    root = godList[0];
    cout << root->name << " is the supreme deity" << endl;
    cout << root->name << ": " << root->speech << endl;
    InitializeTourny();
}
