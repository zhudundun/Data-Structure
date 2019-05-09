// Pet.h
#pragma once

#include <string>
#include "Animal.h"


class Pet: public Animal {
    private:
        std::string name_;
        std::string owner_name_;

    public:
        Pet();
        Pet(std::string type, std::string food, std::string name, std::string ownerName);

        void setFood(std::string nu_food);
        std::string getFood();
        void setName(std::string nu_name);
        std::string getName();
        void setOwnerName(std::string nu_owner_name);
        std::string getOwnerName();
        std::string print();
};
