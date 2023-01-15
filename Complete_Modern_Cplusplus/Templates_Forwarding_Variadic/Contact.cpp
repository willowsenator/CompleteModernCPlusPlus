#include "Contact.h"

#include <iostream>

Contact::Contact(std::string name, int phone, std::string address, std::string email):m_name_{name}, m_phone_{phone},
                                                                                      m_address_{address}, m_email_{email}
{
    const auto contact_creation 
        {R"(Contact: {)" + m_name_ + ", " + std::to_string(m_phone_) + ", " + m_address_ + ", " + m_email_ + R"(})"};

    std::cout << contact_creation << std::endl;
}

