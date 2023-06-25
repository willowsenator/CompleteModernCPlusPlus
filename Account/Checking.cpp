#include "Checking.h"

#include <iostream>


Checking::~Checking()
= default;

void Checking::withdraw(const float amount)
{
    if(balance_ - amount >= 50)
    {
       Account::withdraw(amount);
    }
    else
    {
        std::cout << "Insufficient Balance!! You cannot leave account with less than 50!!" << std::endl;
    }
}