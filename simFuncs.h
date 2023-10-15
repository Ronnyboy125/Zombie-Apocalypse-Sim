#include "person.h"
#include "Zombie.h"
#include "Aware.h"

#ifndef SIMFUNCS_H
#define SIMFUNCS_H

void convertZom(Person* newZom, map<string,std::vector<Person*>>& _city,  map<int,vector<Person*>>& _intcity);

void convertAware(Person* newAware, map<string,std::vector<Person*>>& _city, map<int,vector<Person*>>& _intcity);

#endif