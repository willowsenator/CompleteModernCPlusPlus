#pragma once
#include "Account.h"

class Savings:public Account
{
    float rate_{};
public:
    Savings(std::string name, float balance, float rate);
    ~Savings() override;

    float get_interest_rate() const;
    void accumulate_interest() override;
};
