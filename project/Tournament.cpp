#include "Tournament.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


Tournament::Tournament(){
    for(int i = 0; i < godSize; i++){
        godList[i] = NULL;
    }
    float a = (rand() % 100)/100.0;
}


Tournament::~Tournament(){

}
Gods* Tournament::Fight(Gods *a, Gods *b){
    int modifier = (rand() % 100)/100;
    return a;
}
void Tournament::InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility){
    Gods *newGod = new Gods(in_name, in_attribute, in_health, in_attack, in_agility);
        for(int i = 0; i < godSize; i++){
            if(godList[i] != NULL){
                godList[i] = newGod;
            }
    }
}
