#include <fstream>
#include <iostream>
#include <string>

void write();
void read();

int main()
{
    // File Basics IO
    write();
    read();
}

void write(){
    std::ofstream out {"data.txt"};
    out << "Hello World" << std::endl;
    out << 23 << std::endl;
    out.seekp(5);
    out.put('#');
    out.close();
}

void read(){
    std::ifstream input {"data.txt"};
    // if(!input.is_open())
    // {
    //     std::cout << "Couldn't open the file" << std::endl;
    //     return;
    // }

    if(input.fail())
    {
        std::cout << "Couldn't open the file" << std::endl;
        return;
    }

    input.seekg(-5, std::ios::end);
    std::cout << "Current position: " << input.tellg() << std::endl;
    char ch{};
    while(input.get(ch))
    {
        std::cout << ch;
    }
    
    std::string message;
    std::getline(input, message);
    int value {};
    input >> value;
    input >> value;
    if(input.eof())
    {
        std::cout << "End of file reached" << std::endl;
    }
    else if(input.good())
    {
        std::cout << "I/O Operations are successful" << std::endl;
    }
    else
    {
        std::cout << "Some I/O Operations failed" << std::endl;
    }
    input.setstate(std::ios::failbit);
    input.clear();
    input.close();
    std::cout << message << ":" << value << std::endl;
}
