
#include <iostream>
#include <string>
#include <vector>

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

std::vector<int> FindAll(
 const std::string &target,             
 const std::string &search_string,      
 Case searchCase = Case::INSENSITIVE,   
 size_t offset = 0) {
     auto result = std::vector<int>{};
     auto current_offset = offset;
     std::string target_copy = target;
     std::string search_string_copy = search_string;
     switch(searchCase)
     {
     case Case::SENSITIVE:
        break;
     default:
         target_copy = ToLower(target);
         search_string_copy = ToLower(search_string);
         break;
     }
    while(current_offset < target.length())
    {
        const auto index = target_copy.find(search_string_copy, current_offset);
        if(index < target.length()){
            result.push_back(index);
            current_offset = index + 1;
        }
        else
        {
            current_offset = index;
        }
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

    /*std::cout << Find("Hola", "h") << std::endl;
    std::cout << Find("HOlO", "l", Case::INSENSITIVE) << std::endl;
    std::cout << Find("HOlO", "a", Case::INSENSITIVE) << std::endl;
    std::cout << Find("HolA", "A", Case::SENSITIVE) << std::endl;
    std::cout << Find("HolA", "a", Case::SENSITIVE) << std::endl;*/

    auto indexArray = FindAll("HosdfaO", "o");
    std::cout << "HosdfaO -> " ;
    for(auto index:indexArray)
        std::cout << index << " ";
    std::cout << std::endl;

    std::cout << "HOdfa -> ";
    auto indexArray2 = FindAll("HOdfa","O",Case::SENSITIVE);
    for(auto index: indexArray2)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    
    std::cout << "HOdfa -> ";
        auto indexArray3 = FindAll("HOdfa","e");
        for(auto index: indexArray3)
        {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    return 0;
}
