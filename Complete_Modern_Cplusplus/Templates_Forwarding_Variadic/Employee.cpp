#include "Employee.h"

#include <iostream>

Employee::Employee(std::string name, const int id, const int salary):m_name_{std::move(name)},m_id_{id}, m_salary_{salary}
{
    const auto employee_creation {R"(Employee: {)" + m_name_ + ", " + std::to_string(m_id_) + ", " +
        std::to_string(m_salary_) + R"(})"};
    std::cout << employee_creation << std::endl;
}

