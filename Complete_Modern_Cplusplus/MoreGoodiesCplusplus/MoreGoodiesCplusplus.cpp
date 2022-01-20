
#include <iostream>
#include <string>

std::string ToUpper(const std::string &str)
{
    std::string result("");
    if(!str.empty())
    {
        for(auto &c:str)
            result += static_cast<char>(toupper(c));
    }
    return result;
}
std::string ToLower(const std::string &str)
{
    std::string result("");
    if(!str.empty())
    {
        for(auto &c: str)
            result += static_cast<char>(tolower(c));
    }
    return result;
}


int main()
{
    /*const auto strToTest = "hola"; 
    std::cout << strToTest << std::endl;
    std::cout << ToUpper(strToTest) << std::endl;
    std::cout << ToLower(ToUpper(strToTest)) << std::endl;
    std::cout << ToUpper(nullptr) << std::endl;
    std::cout << ToLower(nullptr) << std::endl;*/
    
    return 0;
}
