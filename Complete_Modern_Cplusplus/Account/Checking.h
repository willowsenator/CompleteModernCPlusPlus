#pragma once
#include "Account.h"

class Checking:public Account
{
public:
    Checking(std::string name, float balance);
    ~Checking();
    void withdraw(float amount);
};
