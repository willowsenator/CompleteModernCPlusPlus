#pragma once
#include "Account.h"

class Checking:public Account
{
public:
    using Account::Account;
    ~Checking() override;
    void withdraw(float amount) override;
};
