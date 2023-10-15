#include "person.h"

#ifndef Ignorant_H
#define Ignorant_H

using std:: string;

class Ignorant : public Person{
    private:
        bool knowledge = false;
    public:
        //base Constructor
        Ignorant() : Person() {}
        //Augmented Constructor
        Ignorant(int spd,int xpos, int infecRate, string _name) : 
        Person(spd,xpos, infecRate, _name){}

        //takes in a populated map then uses it to check to see if there are the
        //Zombie Persons in the spaces on or around the Ignorant to perform it's action
        //then returns a Pointer to the Person subclass object that will get effected
        Person* checkProximity(map<int,vector<Person*>> _intcity);

        void action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>&_city); //become aware
        //void move(); //changed for speed
};

#endif