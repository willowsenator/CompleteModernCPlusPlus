#pragma once
#include <string>

class Account
{
    std::string name_;
    int acc_num_;
    static int acc_generator_;
    protected:
        float balance_;
public:
    Account(std::string name, float balance);
    ~Account();
    std::string get_name() const;
    float get_balance() const;
    int get_acc_num() const;

    static void accumulate_interest();
    void withdraw(float amount);
    void deposit(float amount);
    static float get_interest_rate();
};