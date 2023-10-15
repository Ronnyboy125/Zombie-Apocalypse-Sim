#ifndef Person_H
#define Person_H
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <ctime> // time()
#include <stdlib.h> // srand, rand
#include <string>
using std:: string;
using std:: endl;
using std:: cout;
using std:: map;
using std:: vector;
class Person{
    private:
        int speed =0;
        int num = (rand()%501);
        int infectionRate =0;
        string name;
        map<int,string> sections;
        map<string,vector<int>> newNum;
        map <string, vector<string>> test;
        vector<string> vec = {"Central Butte", "UpDog", "South Hill", "Gardens", "Eastmont"}; 
        int WORLDMULTI = 100;
    public:
        //base constructor
        Person() : speed(0), num((rand()%500)+1), infectionRate (0), name("NONE") {}

        //Augmented constructor
        // spd == speed
        // xpos, ypos == coordinates
        // knowl = knowledge? the random percent chance a person sees a zombie and becomes aware
        // infecRate = infection rate
        // order to intereactions. 
        /*
        1. people move
        2. ignorant - check to see zombie 
        3. bool - knowledge 
        4. aware - spread awareness (interact with ignorant)
        5. zombies move

        1. opption to say how long user wants simulation to run
        2. pop city - create city - a map - open file to fill everyone in (names file)
        3. fill all 2,000 as ignorant except two: 1 aware, 1 zombie
        4. main simulation function - take in city map and days, while loop, as long as cerant days are not equal to last keep looping.

        Ava's part:
        everyone switches coordniates, and have city limits with different sections

        action: bite - if statment - going to say if there is a person
        spread awareness

        record: print stats
        */
        Person(int spd, int xpos, int infecRate, string _name) :
        speed(spd), num(xpos), infectionRate(infecRate), name(_name) {}
        
        //getters
        int getSpeed() {return speed;}
        int getX() {return num;}
        int getInfecRate() {return infectionRate;}
        string getName() {return name;}

        //virtual polymorphic action function used for "bite", "spread awareness", "become aware"
        virtual void action(map<int,vector<Person*>>& _intcity,map<string,vector<Person*>>&_city)=0;
        
        //virtual  polymorphic fucntion used to check the surrounding objects of an object
        virtual Person* checkProximity (map<int,vector<Person*>> _intcity)=0;
        // void moveTry(){
        //     num=(rand()%500)+1;
        // }
       
        // updat objects position in map
        //intcity[currentnum].pop_back(this)
        //intcity[updated num]= this 
        void move(map <int,vector<Person*>>& _intcity){
        int WS = 1; // world size
        int k = 1; // this is a place holder
        // this is for the world size
        while( WS <= 5*WORLDMULTI){ 
        sections.insert({WS,vec[k-1]});// this sets the number to the name of the section
        if (WS == WORLDMULTI * (k)){ // so if the number is equal to every 100 it will multply 
        // to fit the next section of numbers
            k++;
            }   
            WS++;

        }   
        for (auto it = sections.begin(); it != sections.end(); ++it){
       //  cout << it->first << " => " << it->second << '\n';    
        } 
        pointOptions();    
        string answer;       
        auto itr = sections.find(num);
        //cout << itr->second << endl;
        //auto itss = test.find(itr->second); // this equals first name
        
        for (auto it = test.find(itr->second); it == test.find(itr->second); ++it){ // this iterates for only the name given by the first map
         //cout << it->first << " => " ;//<< it->second << '\n';  
         if(it->first != vec[0]){ // this makes sure that we are only looking at Alpha
            // how this is set up is it will iterate and stop randomly making their next destination random
                   for(auto it1 = it->second.begin(); it1 <= it->second.begin()+(rand()%4)+1; it1++){ // this is for BCDE
                   // because there are 4 possible locations that they can go to
        //cout << *it1 << ", "; // this points to the string name
        answer = *it1; // this will equal the last iteration meaning the next destination    
        } 
         } else if (it->first == vec[0]){ // this is for alpha
            for(auto it1 = it->second.begin(); it1 <= it->second.begin()+(rand()%5)+1; it1++){ // this is for A because there 
            // are five possible locations
        //cout << *it1 << ", "; // this points to the string name
             answer = *it1;  // this will equal the last iteration meaning the next destination    
            }
         }     
           //cout << "answer: " << answer << endl;  
        //cout << endl;
        } 
        // this is mathews code
        auto place = this;
        auto index = find(_intcity[place->getX()].begin(),_intcity[place->getX()].end(),place);
        _intcity[place->getX()].erase(index);
        makeNewSpot(answer);
        _intcity[place->getX()].push_back(place);
        }
        // names to random
        //map <int,int> random;
        // if b then 
        //virtual polymorphic move function
        void makeNewSpot(string answer){
            int j = 1;
            int k = 1;
        for(int i = 0; i < 5; i++){
           for( j = k; j < (WORLDMULTI * (i+1)) + 1; j++){ // this "(100 * (i+1)) + 1" puts me in the right range. ex. 1-100, 101-200
           newNum[vec[i]].push_back(j);
           k = j; 
        }  
        k++;
        }

        for (auto it = newNum.find(answer); it == newNum.find(answer); ++it){
         //cout << it->first << " => " ;//<< it->second << '\n';

        for(auto it1 = it->second.begin(); it1 <=  it->second.begin()+(rand()%WORLDMULTI)+1; it1++){// <=  it->second.begin()+(rand()%100)+1 // this makes it stop
        // at a random spot
        //cout << *it1 << ", "; // this points to the string name
        num = *it1;
        } 
        //cout << "new coordinate: " << num << endl;
       
    //cout << endl;
    }
        }
// this is the spagetti code part of the seperating sections
// this makes it so that you can only travel to specific spots
// this is also specific for fast moving characters if I have time
// to make a more specific on for slower moving characters.
        void pointOptions(){

        for(int j = 0; j<5; j++){ 
            test[vec[0]].push_back(vec[j]);        
        }
        for(int i = 0; i < 5; i++){
            if(i <= 1){
            test[vec[1]].push_back(vec[i]);     
            }else if (i >=3){
            test[vec[1]].push_back(vec[i]);   
            }
        }
        for(int i = 0; i < 5; i++){
            if(i <= 0){
            test[vec[2]].push_back(vec[i]);     
            }else if (i >=2){
            test[vec[2]].push_back(vec[i]);   
            }
        }
        for(int i = 0; i < 5; i++){
            if(i <= 3){
            test[vec[3]].push_back(vec[i]);     
            }else if (i >= 4){
            // test[vec[3]].push_back(vec[i]);   
            }
        }
        for(int i = 0; i < 5; i++){
            if(i <= 2){
            test[vec[4]].push_back(vec[i]);     
            }else if (i >=4){
            test[vec[4]].push_back(vec[i]);   
            }
        }
        
        }       
       
};

#endif