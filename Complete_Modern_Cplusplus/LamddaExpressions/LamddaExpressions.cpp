
#include <iostream>

int main()
{
    // Anonymous Lambda Expression
    []
    {
        std::cout << "Anonymous Lambda Expression" << std::endl;
    }();

    // Named Lambda Expressions
    auto fn = []
    {
      std::cout << "Named Lambda Expression" << std::endl;  
    };

    fn();

    // Generic lambda expression with arguments and no exceptions
    auto sum = [](const auto x, const auto y)noexcept
    {
        return x+y;
    };

    std::cout << "Sum is equal: " << sum(4.6, 7.3) << std::endl;
    return 0;
}
