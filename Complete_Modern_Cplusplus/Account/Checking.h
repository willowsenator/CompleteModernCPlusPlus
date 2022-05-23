#pragma once
#include "Account.h"

class Checking:public Account
{
public:
    using Account::Account;
    ~Checking();
    void withdraw(float amount);
};
