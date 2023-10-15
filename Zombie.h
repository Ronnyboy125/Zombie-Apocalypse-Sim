#include "person.h"
#ifndef Zombie_H
#define Zombie_H

using std:: string;

class Zombie : public Person{
    protected:
    int x;// Ava - testing
    int y;// Ava - testing
    public:
        //Base Constructor
        Zombie() : Person() {}
        //Augmented Constructor
        Zombie(int spd, int xpos, int infecRate, string _name) : 
        Person(spd, xpos,infecRate, _name){}

        //takes in a populated map then uses it to check to see if there are the
        //non-Zombie Persons in the spaces on or around the Zombie to perform it's action
        //then returns a Pointer to the Person subclass object that will get effected
        Person* checkProximity(map<int,vector<Person*>> _intcity);

        //checks against a % chance 
        //if succeeds the corresponding subclass conversions will take place
        //if fails will end the action
        void action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>&_city);//bite

        //void move();//changed for speed
        void location(); /* ava testing; 
I want this to be used for understanding where a person is in what part of the city
              ┏   ┓
              | B |
          ┏   ┗   ┛   ┓
        ┏   ┓ ┏   ┓ ┏   ┓
        | D | | A | | E |
        ┗   ┛ ┗   ┛ ┗   ┛
          ┗   ┏   ┓   ┛
              | C |
              ┗   ┛    
              
              CHEAT CODE: UP DOWN LEFT RIGHT
 
          so each box to start will be 10 by 10
          if in the middle you can go to any spot
          if on the sides you can only go to three
          the map will be in the positive quadtrant 
          to prevent negative numbers
            A: 1-100 == (rand()% 100)+1
            B: 101-200
            C: 201-300
            D: 301-400
            E: 401-500 
        ex: if (x < 100){
            ABCDE available
        }
        if (x >= 201 && >= 300){
            ADE available
        }
things to note: 
A is always available
1. spawn x rand()%500
if (x < 100){
2. x = (rand()% 100)+1   1-100  
3. num = (rand()%5)+1  (1-5) 
4. if in section n, then in section n
}
1. spawn x rand()%500
2. x = 350
3. x = rand()%100;

Note:
 if x = A = num = 1,2,3,4,5 missing:
 if x = B = num = 1,2,4,5   3
 if x = C = num = 1,3,4,5   2
 if x = D = num = 1,2,3,4   5
 if x = E = num = 1,2,3,5   4
 */
};

#endif