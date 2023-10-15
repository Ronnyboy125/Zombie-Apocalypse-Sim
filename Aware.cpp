#include <iostream>
#include "Aware.h"
#include "Ignorant.h" 
#include "simFuncs.h"
#include <ctime>

void Aware:: action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>& _city){
    int SpreadChance = rand()%100;
    if(checkProximity(_intcity)==nullptr){
        return;
    }else{
        if(SpreadChance < 35){
            convertAware(checkProximity(_intcity),_city,_intcity);
            return;
        }else{
            return;
        }
    }
}

Person* Aware:: checkProximity(map<int,vector<Person*>> _intcity) {
    int pos = getX();
    auto choice = _intcity[pos].begin();
    //checks to see if the position is not empty then finds an ignorant person
    if(_intcity[pos].empty()==false){
        for(int i=0; i <_intcity[pos].size(); i++){
            if(typeid(*choice[i])==typeid(Ignorant)){
                return choice[i];
            }
        }
    }
    //finds an ignorant person at pos+1
    choice = _intcity[pos+1].begin();
    if(_intcity[pos+1].empty()==false){
        for(int i =0; i<_intcity[pos+1].size(); i++){
            if(typeid(*choice[i])==typeid(Ignorant)){
                return choice[i];
            }
        }
    }
    //finds an ignorant person at pos-2
    choice = _intcity[pos-2].begin();
    if(_intcity[pos-2].empty()==false){
        for(int i =0; i<_intcity[pos-2].size();i++){
            if(typeid(*choice[i])==typeid(Ignorant)){
                return choice[i];
            }
        }
    }
    //returns if none are found 
    return nullptr;
}



//void Aware:: move(){}
