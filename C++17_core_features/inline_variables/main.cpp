#include <iostream>
#include "vars.h"
int main(){
    std::cout << global << std::endl;
    std::cout << Test::data << std::endl;
    Test::data = 10;
    std::cout << Test::data << std::endl;
    std::cout << Test::PATH_SIZE << std::endl;
    return 0;
}