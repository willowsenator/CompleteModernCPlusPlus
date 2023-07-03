#include <iostream>


template<typename ...Args>
auto sum(Args... args){
    //return (args + ...);  // Unary right fold
    return (... + args); // Unary left fold
}

template<typename ...Args>
auto sum2(Args... args){
    //return (0 + ... + args); // Binary left fold
    return (args + ... + 0); // Binary right fold
}

template<typename ...Args>
bool evenAtLeastOne(Args ...args){
    return (... || (args % 2 == 0)) ;
}

template<typename ...Args>
bool allGreaterThanZero(Args ...args){
    return (... && (args > 0));
}


template<typename ...Args, typename Predicate>
bool evenAtLeastOneLambda(Predicate p, Args ...args){
    return (... || p(args));
}

int main(){
    auto result = sum(1,2,3,4,5);
    std::cout << "Sum: " << result << std::endl;

    result = sum2();
    std::cout << "Sum: " << result << std::endl;

    result = sum2(1,2,3,4,5);
    std::cout << "Sum: " << result << std::endl;

    std::cout << std::boolalpha;
    std::cout << "AnyEven?"  << evenAtLeastOne(10,3,7) << std::endl;
    std::cout << "AnyEvenWithLambda?" << evenAtLeastOneLambda([](int x){
        return x % 2 == 0;
    }, 10,3,7) << std::endl;

    std::cout << "AllGreaterThanZero?" << allGreaterThanZero(3,5,1) << std::endl;

}