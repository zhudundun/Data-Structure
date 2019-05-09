#include <iostream>
#include <string>
#include "Pet.h"

void Pet::setFood(std::string nu_food) {
    food_ = nu_food;
}

std::string Pet::getFood() {
    return food_;
}

void Pet::setName(std::string nu_name) {
    name_ = nu_name;
}

std::string Pet::getName() {
    return name_;
}

void Pet::setOwnerName(std::string nu_owner_name) {
    owner_name_ = nu_owner_name;
}

std::string Pet::getOwnerName() {
    return owner_name_ ;
}


std::string Pet::print (){
  return "My name is " + name_;
}

Pet::Pet() : Animal("cat","fish"),name_("Fluffy"), owner_name_("Cinda") { }

Pet::Pet(std::string type, std::string food,std::string name,std::string OwnerName ): Animal(type,food),name_(name),owner_name_(OwnerName) { }
// Pet.cpp
