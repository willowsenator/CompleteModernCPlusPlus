#include "Savings.h"

Savings::Savings(std::string name, const float balance, const float rate):Account(std::move(name), balance), rate_(rate)
{
}

Savings::~Savings()=default;

float Savings::get_interest_rate() const
{
    return rate_;
}

void Savings::accumulate_interest()
{
    balance_ += (balance_ * rate_);
}


