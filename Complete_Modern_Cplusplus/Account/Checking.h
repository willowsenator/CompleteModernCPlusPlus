#pragma once
#include "Account.h"

class Checking:public Account
{
public:
    Checking(std::string _name, float balance);
    ~Checking();
    void withdraw(float amount);
};
