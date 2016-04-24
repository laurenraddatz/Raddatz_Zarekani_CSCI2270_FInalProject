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
//Gods  Tournament::*Fight(Gods *a, Gods, *b){

//}
void Tournament::InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility){
    Gods *newGod = new Gods(in_name, in_attribute, in_health, in_attack, in_agility);
        for(int i = 0; i < godSize; i++){
            if(godList[i] != NULL){
                godList[i] = newGod;
            }
    }
}
