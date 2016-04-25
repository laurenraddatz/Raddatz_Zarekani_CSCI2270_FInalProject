#include "Tournament.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime> //for srand
using namespace std;

Tournament::Tournament(){
    for(int i = 0; i < godSize; i++){
        godList[i] = NULL;
    }
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
        if(fighterA.agility * modifierA < fighterB.agility * modifierB){ //whether the attack misses or hits
            fighterA.health = fighterA.health - (fighterB.attack * modifierB);
        }
        if(fighterA.agility * modifierA < fighterB.agility * modifierB){ //whether the attack misses or hits
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
void Tournament::InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility){
    Gods *newGod = new Gods(in_name, in_attribute, in_health, in_attack, in_agility);
        int initialI = rand() % 7;
        for(int i = initialI; i < godSize + initialI ; i++){
            if(godList[i] == NULL){
                godList[i] = newGod;
                break;
            }
            if(i >= godSize){
                i = 0;
            }
    }
}
void Tournament::makeGod(string in_name, string in_attribute, string in_dominantStat, string in_inferiorStat){
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
    InsertGod(in_name, in_attribute, health, attack, agility);
    cout << "The Earth trembles, the air burns, and the Heavens rage. A new God has emerged." << endl;
    cout << "Their name is " << in_name << " of the attribute " << in_attribute << endl;
    cout << " of the attack " << attack << " of the health " << health << " and the agility " << agility << endl;


}
void Tournament::makeTree(){
    // root is already a Gods object
    // very iterative :(
    // create each node
    Gods *l1 = new Gods;
    Gods *r1 = new Gods;
    Gods *ll2 = new Gods;
    Gods *lr2 = new Gods;
    Gods *rl2 = new Gods;
    Gods *rr2 = new Gods;
    Gods *god1 = new Gods;
    Gods *god2 = new Gods;
    Gods *god3 = new Gods;
    Gods *god4 = new Gods;
    Gods *god5 = new Gods;
    Gods *god6 = new Gods;
    Gods *god7 = new Gods;
    Gods *god8 = new Gods;
    
    // connect the nodes
    root->parent = NULL;
    root->left = l1;
    root->right = r1;
    
    l1->parent = root;
    l1->left = ll2;
    l1->right = lr2;
    
    r1->parent = root;
    r1->left = rl2;
    r1->right = rr2;
    
    ll2->parent = l1;
    ll2->left = god1;
    ll2->right = god2;
    
    lr2->parent = l1;
    lr2->left = god3;
    lr2->right = god4;
    
    rl2->parent = r1;
    rl2->left = god5;
    rl2->right = god6;
    
    rr2->parent = r1;
    rr2->left = god7;
    rr2->right = god8;
    
    god1->parent = ll2;
    god1->left = NULL;
    god1->right = NULL;
    
    god2->parent = ll2;
    god2->left = NULL;
    god2->right = NULL;
    
    god3->parent = lr2;
    god3->left = NULL;
    god3->right = NULL;
    
    god4->parent = lr2;
    god4->left = NULL;
    god4->right = NULL;
    
    god5->parent = rl2;
    god5->left = NULL;
    god5->right = NULL;
    
    god6->parent = rl2;
    god6->left = NULL;
    god6->right = NULL;
    
    god7->parent = rr2;
    god7->left = NULL;
    god7->right = NULL;
    
    god8->parent = rr2;
    god8->left = NULL;
    god8->right = NULL;
    
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
            cout << godList2[i]->name << endl;
        }
    }
    else if(choice == 3){
        for(int i = 0; i < 2; i++){
            cout << godList3[i]->name << endl;
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

void Tournament::runTournament(){
    int countMatch = 0;
    Gods * winner;
    Gods **godListTemp;
    cout << "The Tournament Will Now Begin" << endl;
    for (int i = 0; i < godSize; i = i + 2){
        cout << godList[i]->name << " vs " << godList[i+1]->name << endl;
    }
    for(int j = 0; j < 3; j++){
        godListTemp = new Gods*[godSize];
        for (int i = 0; i < godSize; i++){
            godListTemp[i] = godList[i];
        }
        godSize = godSize / 2;
        *godList = new Gods[godSize];
        cout << "Round " << round << endl;
        countMatch = 0;
        for (int i = 0; i < godSize*2; i = i + 2){
            winner = new Gods();
            if(godListTemp[i] != player and godListTemp[i+1] != player){
                *winner = *Fight(godListTemp[i],godListTemp[i+1]);
                cout << winner << endl;
                cout << godListTemp[i]->name << " vs " << godListTemp[i+1]->name << endl;
                cout << winner->name << " is the winner" << endl;
                winner->left = godListTemp[i];
                godListTemp[i]->parent = winner;
                winner->right = godListTemp[i+1];
                godListTemp[i+1]->parent = winner;
                godList[countMatch] = winner;
            }else{
                cout << "Player Match, to be filled later" << endl;
                *winner = *Fight(godListTemp[i],godListTemp[i+1]);
                cout << godListTemp[i]->name << " vs " << godListTemp[i+1]->name << endl;
                cout << winner->name << " is the winner" << endl;
                winner->left = godListTemp[i];
                godListTemp[i]->parent = winner;
                winner->right = godListTemp[i+1];
                godListTemp[i+1]->parent = winner;
                godList[countMatch] = winner;
            }
            countMatch++;
        }
        for(int i = 0; i < godSize; i++){
            cout << godList[i]->left->name << " look here" << endl;
        }
        round++;
    }
    Gods *temp = godList[0];
    while(temp != NULL){
    cout << temp->name << endl;
    temp = temp->left;
    }
}
