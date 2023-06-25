#pragma once
#include <string>

class Employee
{
    std::string m_name_;
    int m_id_;
    int m_salary_;
public:
    Employee(std::string name, int id, int salary);
};
