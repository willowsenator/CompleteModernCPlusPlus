
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

enum class Case{SENSITIVE, INSENSITIVE};
 
size_t Find(
 const std::string &source,         
 const std::string &search_string,  
 Case searchCase = Case::INSENSITIVE,
 size_t offset = 0 ) {                
    switch (searchCase)
    {
        case Case::SENSITIVE:
            return source.find(search_string, offset);
    default:
        const std::string source_to_lower = ToLower(source);
        const std::string search_string_to_lower = ToLower(search_string);

        return source_to_lower.find(search_string, offset);
    }
}


int main()
{
    /*const auto strToTest = "hola"; 
    std::cout << strToTest << std::endl;
    std::cout << ToUpper(strToTest) << std::endl;
    std::cout << ToLower(ToUpper(strToTest)) << std::endl;
    std::cout << ToUpper(nullptr) << std::endl;
    std::cout << ToLower(nullptr) << std::endl;*/

    std::cout << Find("Hola", "h") << std::endl;
    std::cout << Find("HOlO", "l", Case::INSENSITIVE) << std::endl;
    std::cout << Find("HOlO", "a", Case::INSENSITIVE) << std::endl;
    std::cout << Find("HolA", "A", Case::SENSITIVE) << std::endl;
    std::cout << Find("HolA", "i", Case::SENSITIVE) << std::endl;
    return 0;
}
