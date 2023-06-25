#pragma once
#include "Account.h"

class Checking:public Account
{
using Account::Account;
public:
    ~Checking() override;
    void withdraw(float amount) override;
};
