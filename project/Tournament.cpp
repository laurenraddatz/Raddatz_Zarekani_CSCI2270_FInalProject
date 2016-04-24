#include "Tournament.h"

#include <string>
#include <iostream>


Tournament::Tournament(){
    for(int i = 0; i < godSize; i++){
        godList[i] = NULL;
    }
}

Tournament::~Tournament(){

}
Gods* Tournament::Fight(Gods *a, Gods *b){
    Gods fighterA = *a;
    Gods fighterB = *b;
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
void Tournament::InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility){
    Gods *newGod = new Gods(in_name, in_attribute, in_health, in_attack, in_agility);
        int initialI = rand() % 10;
        for(int i = initialI; i < godSize + initialI ; i++){
            if(godList[i] == NULL){
                godList[i] = newGod;
               // cout << godList[i]->name << " " << i << endl;
                break;
            }
            if(i >= godSize){
                i = 0;
            }
    }
}

// Clear the tournament bracket, input the root node
void Tournament::deleteAll(Gods *node){
    if(node->left != NULL)
        DeleteAll(node->left);
    if(node->right != NULL)
        DeleteAll(node->right);
    //cout<<"Deleting: "<<node->name<<endl;
    delete node;

