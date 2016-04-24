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

// Clear the tournament bracket, input the root node
void Tournament::deleteAll(Gods *node){
    if(node->left != NULL)
        deleteAll(node->left);
    if(node->right != NULL)
        deleteAll(node->right);
    //cout<<"Deleting: "<<node->name<<endl;
    delete node;

