#include "Checking.h"

#include <iostream>
#include <utility>


Checking::Checking(std::string name, const float balance): Account(std::move(name), balance)
{
}

Checking::~Checking()
= default;

void Checking::withdraw(const float amount)
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
