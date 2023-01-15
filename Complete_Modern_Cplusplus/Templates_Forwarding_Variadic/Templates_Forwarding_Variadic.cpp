#include <complex>
#include <iostream>

#include "Contact.h"
#include "Employee.h"

template <typename T, typename ...Params>
T CreateObject(Params&& ...args)
{
    return T{std::forward<Params>(args)...};
}

int main()
{
    CreateObject<Employee>("Bob",101,1000);

    int p1 = CreateObject<int>(7);
    std::cout << "Integer: " << p1 <<std::endl;

    std::string s = CreateObject<std::string>("TEST");
    std::cout << "String: " << s << std::endl;

    CreateObject<Contact>("Joey",987654321,"Boulevard Road, Sgr","joey@poash.com");
    
    return 0;
}
