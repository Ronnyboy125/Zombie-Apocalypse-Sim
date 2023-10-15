#include <iostream>
#include "Ignorant.h"
#include "Zombie.h"
#include "simFuncs.h"
#include <ctime>

void Ignorant:: action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>& _city){
    int knowledgeChance = rand()%100;
    if(checkProximity(_intcity)==nullptr){
        return;
    }else{
        if(knowledgeChance <70){
            convertAware(checkProximity(_intcity),_city,_intcity);
            return;
        }else{
            return;
        }
    }
}

Person* Ignorant:: checkProximity(map<int,vector<Person*>> _intcity) {
    int pos = getX();
    auto choice = _intcity[pos].begin();
    //checks to see if the position is not empty then finds a zombie person
    if(_intcity[pos].empty()==false){
        for(int i=0; i <_intcity[pos].size(); i++){
            if(typeid(*choice[i])==typeid(Zombie)){
                return this;
            }
        }
    }
    //finds a zombie person at pos+1
    choice = _intcity[pos+1].begin();
    if(_intcity[pos+1].empty()==false){
        for(int i =0; i<_intcity[pos+1].size(); i++){
            if(typeid(*choice[i])==typeid(Zombie)){
                return this;
            }
        }
    }
    //finds a zombie person at pos-2
    choice = _intcity[pos-2].begin();
    if(_intcity[pos-2].empty()==false){
        for(int i =0; i<_intcity[pos-2].size();i++){
            if(typeid(*choice[i])==typeid(Zombie)){
                return this;
            }
        }
    }
    //returns if none are found
    return nullptr;
}

//void Ignorant :: move(){}
