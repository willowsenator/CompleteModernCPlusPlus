#include <iostream>
#include "Account.h"

int main()
{
    Account acc("Omar", 2000);
    std::cout << "Initial Balance: " << acc.get_balance() << std::endl;

    acc.withdraw(200);
    acc.deposit(400);
    std::cout << "Current Balance: " << acc.get_balance() << std::endl;
    return 0;
}