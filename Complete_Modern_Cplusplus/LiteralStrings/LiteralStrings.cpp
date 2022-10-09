#include <iostream>
#include <string>

int main()
{
    // Literal Strings
    std::string filename{R"(c:\temp\prueba)"};
    std::cout << filename << std::endl;
    std::string message {R"MSG(C++ introduced Filesystem API" In(C++17)")MSG"};
    std::cout << message << std::endl;

   
    return 0;
}