#include "Account.h"

#include <iostream>

int Account::acc_generator_ = 1000;
Account::Account(std::string name, const float balance):name_(std::move(name)), balance_(balance)
{
    acc_num_ = ++acc_generator_;
}

Account::~Account() = default;

std::string Account::get_name() const
{
    return name_;
}

float Account::get_balance() const
{
    return balance_;
}

int Account::get_acc_num() const
{
    return acc_num_;
}

void Account::accumulate_interest()
{
}

void Account::withdraw(const float amount)
{
    if(amount <= balance_)
    {
        balance_ -= amount;
    }
    else
    {
        std::cout << "Insufficient balance!!!" << std::endl;
    }
}

void Account::deposit(const float amount)
{
    balance_ += amount;
}

float Account::get_interest_rate() const
{
    return 0.0f;
}
