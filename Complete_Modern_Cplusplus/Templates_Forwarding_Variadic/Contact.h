#pragma once
#include <string>

class Contact
{
    std::string m_name_;
    int m_phone_;
    std::string m_address_;
    std::string m_email_;
    
public:
    Contact(std::string name, int phone, std::string address, std::string email);
};
