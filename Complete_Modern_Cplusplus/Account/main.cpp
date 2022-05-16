#include <iostream>
#include "Account.h"
#include "Checking.h"

int main()
{
    Account acc("Omar", 2000);
    std::cout << "Initial Balance: " << acc.get_balance() << std::endl;

    acc.withdraw(200);
    acc.deposit(400);
    std::cout << "Current Balance: " << acc.get_balance() << std::endl;

    Checking check("Clari", 3000);
    std::cout << "Initial Balance:" << check.get_balance() << std::endl;
    check.withdraw(2970);
    check.withdraw(2940);
    check.withdraw(10);
    std::cout << "Current Balance: " << check.get_balance() << std::endl;
    return 0;
}
