#include "person.h"

#ifndef Aware_H
#define Aware_H

using std:: string;

class Aware : public Person{
    public:
        Aware() : Person(){}
        Aware(int spd, int xpos, int infecRate,string _name) : 
        Person(spd, xpos, infecRate, _name){}

        //takes in a populated map then uses it to check to see if there are the
        //Ignorant Persons in the spaces on or around the Aware to perform it's action
        //then returns a Pointer to the Person subclass object that will get effected
        Person* checkProximity(map<int,vector<Person*>> _intcity);
        
        void action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>&_city); //spread awareness
        //void move(); //changed for speed
};

#endif