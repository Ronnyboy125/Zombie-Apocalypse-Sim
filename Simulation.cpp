#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <ctime> // time()
#include <stdlib.h> // srand, rand
#include "Aware.h"
#include "Zombie.h"
#include "Ignorant.h"

using std::cout;
using std::map;
using std::vector;
using std::string;
using std::endl;
using std::cin;

//function used to populate the city maps
//_city is keyed to a string type "Aware", "Ignorant", or "Zombie"
//_intcity is keyed to a int that corresponds to object "x-coordinate" values 
void popCity(map<string,vector<Person*>>& _city, map<int,vector<Person*>>& _intcity, int awInfctRt, int igInfctRt);
void avasTestFunc();
void simulation(map<string,vector<Person*>>& _city, int days, map<int,vector<Person*>>& _intcity);
//clears the allocated memory held by the constructed objects
void clearMemory(map<string,vector<Person*>>& deleteCity);
//outputs the current count of Zombies, Ignorant, and Aware people
void reportStats(map<string,vector<Person*>> cityStats);

int main(){
    srand(time(0)); // for random number generator
    int days;
    cout<<"Choose the number of days you would like to run the simulation for."<<endl;
    cin>>days;
    
    map<string,std::vector<Person*>> city;
    map<int,std::vector<Person*>> city2;
    simulation(city, days, city2);
    
}// end of main function

void popCity(map<string,vector<Person*>>& _city, map<int,vector<Person*>>& _intcity  ,int awInfctRt, int igInfctRt){
    std:: vector<Person*> citizens; 
    int i = 0;
    //loops to fill the vector with desired num of Ignorant People
    std::fstream names;
    vector<string> citizenNames;
    names.open("names.txt");
    if(names.fail()){
        cout<<"Txt file failed to open"<<endl;
    }
    string Cnames;
    while(names.is_open()){
        if(citizenNames.size()==2000){
            names.close();
            break;
        }
        getline(names, Cnames);
        citizenNames.push_back(Cnames);
    }
    int j=0;
    while (i != 1000){
        citizens.push_back(new Ignorant(5,(rand()%500)+1,igInfctRt,citizenNames[j]));
        i++; j++;
    }
    //adds the 1 Aware and 1 Zombie Person Objects
    citizens.push_back(new Aware(5,121,awInfctRt,"James Charles"));//speed, pos, infection rate, name
    citizens.push_back(new Zombie(4,120,0, "Elizabeth Benson"));

    //creates pointer to the start of the vector
    auto it = citizens.begin();
    //loops to fill the Maps used to track the city and objects
    for(int i =0; i< citizens.size();i++){
        //checking to see if the current object is Ignorant
        if(typeid(*citizens[i])==typeid(Ignorant)){
            //fills both maps in the correct place with the current Object
            _city["Ignorant"].push_back(*it);
            _intcity[(*it)->getX()].push_back(*it);//
        //checking to see if the current object is Aware
        }else if(typeid(*citizens[i])==typeid(Aware)){
            //fills both maps in the correct place with the current object
            _city["Aware"].push_back(*it);
            _intcity[(*it)->getX()].push_back(*it);
        }else{
            //fills the maps with the last possible chioce which is a Zombie 
            _city["Zombie"].push_back(*it);
            _intcity[(*it)->getX()].push_back(*it);
        }
        ++it;
    }
    
}

// void avasTestFunc(){
// Person *zomb;
// zomb = new Zombie();
// zomb->move();

// }


void simulation(map<string,vector<Person*>>& _city, int days, map<int,vector<Person*>>& _intcity){
    int awInfctRt; int igInfctRt;
    cout<<"Please choose the infection rates for everyone in between 1 and 100."<<endl;
    cout<<"Aware People : "; cin>>awInfctRt; cout<<endl;
    if(awInfctRt > 100 || awInfctRt < 1){
        cout<<"Not a valid number, please try again"<<endl;
        cin>>awInfctRt; cout<<endl;
    }
    cout<<"Ignorant People : "; cin>>igInfctRt; cout<<endl;
    if(igInfctRt > 100 || igInfctRt < 1){
        cout<<"Not a valid number, please try again"<<endl;
        cin>>igInfctRt; cout<<endl;
    }
    //cout << "before pop city";
    popCity(_city,_intcity,awInfctRt,igInfctRt);
    int currentDay = 0;
    string type;
    int size=0;
    //runs for desired days turned into hours
    while(currentDay != days*24){
        //failsafe condition to stop unecessary looping
        if(_city["Aware"].size() == 0 && _city["Ignorant"].size() == 0){
            cout<<"Everyone has become infected before the alloted time..."<<endl;
            reportStats(_city);
            break;
        }
        //loops through the size of _city
        for(int i = 0;i<3; i++){
            if(i==0){
                //sets key value
                type = "Ignorant";
            }else if(i==1){
                //sets key value
                type = "Aware";                
            }else{
                //sets key value
                type = "Zombie";
            }
            //creates a size limit variable 
            size = _city[type].size();
            //creates an iterator to inside the map at the desired key
            auto turn = _city[type].begin();
            //loops for the number of elements in the map key at at the start of the hour
            for(int j = 0; j <size ; j++){
                (*turn)->action(_intcity,_city);
                (*turn)->move(_intcity);
               //(*turn)->moveTry();
                //this will randomly lose the iterator value for unknown reasons
                ++turn;
            }
        }  
        //outputs the stats to a .tsv file 
        reportStats(_city);
        //increments the hour
        ++currentDay;
        
    }
    //clears the allocated memory at the very end
    clearMemory(_city);
}

void clearMemory(map<string,vector<Person*>>& deleteCity){
    auto destruct = deleteCity.begin();
    //looping through the map to clear all allocated memory from the sim
    for(int i = 0; i<deleteCity.size(); i++){
        for(auto j=destruct->second.begin(); j != destruct->second.end();++j){
            delete *j;
        }
        ++destruct;
    }
}

void reportStats(map<string,vector<Person*>> cityStats){
    std:: fstream statsout;
        if(statsout.fail()){
        cout<<"Txt file failed to open"<<endl;
    }
    statsout.open("Statistics.tsv", std::ios::out | std::ios::app);
    statsout<<cityStats["Ignorant"].size() <<"\t";
    statsout<<cityStats["Aware"].size()<<"\t";
    statsout<<cityStats["Zombie"].size()<<"\n";
    statsout.close();
}