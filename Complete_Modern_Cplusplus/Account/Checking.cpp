#include "Checking.h"

#include <iostream>
#include <utility>


Checking::Checking(std::string _name, const float _balance): Account(std::move(_name), _balance)
{
}

Checking::~Checking()
= default;

void Checking::withdraw(float amount)
{
    if(balance_ - amount >= 50)
    {
        balance_ -= amount;
    }
    else
    {
        std::cout << "Insufficient Balance!! You can leave account with less than 50!!" << std::endl;
    }
}
