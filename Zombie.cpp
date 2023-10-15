#include<iostream>
#include "Zombie.h"
#include "simFuncs.h"
#include <ctime>
//note for bite action 
//retrieve x,y coord
//check if any non zombie is with in reasonable distance
//select a human to bite
//resolve the bite/infection attempt
using std:: endl;
using std:: cout;

//Bite
void Zombie:: action(map<int,vector<Person*>>& _intcity, map<string,vector<Person*>>&_city){
    int biteChance = rand()%100;
    if(checkProximity(_intcity)==nullptr){
        return;
    }else{
        if(biteChance < checkProximity(_intcity)->getInfecRate()){
            convertZom(checkProximity(_intcity),_city,_intcity);
            return;
        }else{
            return;
        }
    }
}


Person* Zombie:: checkProximity(map<int,vector<Person*>> _intcity) {
    int pos = getX();
    auto choice = _intcity[pos].begin();
    //checks to see if the position is not empty then finds a nonzombie person
    if(_intcity[pos].empty()==false){
        for(int i=0; i <_intcity[pos].size(); i++){
            if(typeid(*choice[i])!=typeid(Zombie)){
                return choice[i];
            }
        }
    }
    
    //finds a nonzombie person at pos+1
    choice = _intcity[pos+1].begin();
    if(_intcity[pos+1].empty()==false){
        for(int i =0; i<_intcity[pos+1].size(); i++){
            if(typeid(*choice[i])!=typeid(Zombie)){
                return choice[i];
            }
        }
    }
    //finds a nonzombie person at pos-2
    choice = _intcity[pos-2].begin();
    if(_intcity[pos-2].empty()==false){
        for(int i =0; i<_intcity[pos-2].size();i++){
            if(typeid(*choice[i])!=typeid(Zombie)){
                return choice[i];
            }
        }
    }
    //returns if nothing is found
    return nullptr;
}


// void Zombie :: move(){
// //   (int spd, int xpos, int ypos, int knowl, int infecRate)
//  x = rand()%10; 
//  y = rand()%10;
//  cout << x << " " << y << endl;
// }