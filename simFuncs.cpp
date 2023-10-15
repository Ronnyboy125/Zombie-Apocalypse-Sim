#include "simFuncs.h"

void convertZom(Person* newZom, map<string,std::vector<Person*>>& _city,  map<int,vector<Person*>>& _intcity){
    string namePlace = newZom->getName(); int coordplace = newZom->getX();// placeholders
    auto *it = new Zombie(4,coordplace,0,namePlace);//sets a auto variable pointer to a new zombie with the old persons stats
    //stores the vector index value for the ptr passed in by newZom
    auto index = find(_intcity[coordplace].begin(),_intcity[coordplace].end(),newZom);
    //stores the vector index  value for the ptr passed in by newZom
    if(typeid(*newZom) == typeid(Aware)){
        auto index2 = find(_city["Aware"].begin(),_city["Aware"].end(),newZom);
        _city["Aware"].erase(index2);
    }else{
        auto index3 = find(_city["Ignorant"].begin(),_city["Ignorant"].end(),newZom);
        _city["Ignorant"].erase(index3);
    }
    //removes the old object from the second map
    _intcity[(it)->getX()].erase(index);
    _intcity[(it)->getX()].push_back(it);//places the x value into the map of x values
    delete newZom;//deletes the old person
    _city["Zombie"].push_back(it);//places new zombie in map
}

void convertAware(Person* newAware, map<string,std::vector<Person*>>& _city, map<int,vector<Person*>>& _intcity){
    string namePlace = newAware->getName(); int coordPlace = newAware->getX();
    int infecRate = newAware->getInfecRate();
    auto *it = new Aware(5,coordPlace,infecRate,namePlace);
    auto index = find(_intcity[coordPlace].begin(),_intcity[coordPlace].end(),newAware);
    auto index2 = find(_city["Ignorant"].begin(),_city["Ignorant"].end(),newAware);
    _city["Ignorant"].erase(index2);
    _intcity[(it)->getX()].erase(index);
    _intcity[(it)->getX()].push_back(it);
    delete newAware;
    _city["Aware"].push_back(it);
}