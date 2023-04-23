#include "Contact.h"

#include <iostream>

Contact::Contact(std::string first_name, std::string last_name, std::string first_phone_number,
                 std::string second_phone_number, std::string email, std::string address,
                 std::string company, const group group):first_name_(std::move(first_name)),
                                                         last_name_(std::move(last_name)),
                                                         first_phone_number_(std::move(first_phone_number)),
                                                         second_phone_number_(std::move(second_phone_number)),
                                                         email_(std::move(email)),
                                                         address_(std::move(address)),
                                                         company_(std::move(company)), group_(group)
{
    
}

std::string Contact::get_first_name() const
{
    return first_name_;
}
std::string Contact::get_last_name() const
{
    return last_name_;
}
std::string Contact::get_first_phone_number() const
{
    return first_phone_number_;
}
std::string Contact::get_second_phone_number() const
{
    return second_phone_number_;
}
std::string Contact::get_email() const
{
    return email_;
}
std::string Contact::get_address() const
{
    return address_;   
}
std::string Contact::get_company() const
{
    return company_;
}
Contact::group Contact::get_group() const
{
    return group_;
}

constexpr const char* Contact::group_to_string(const group group) noexcept
{
    switch (group)
    {
    case group::acquaintance: return "Acquaintance";
    case group::coworker: return "CoWorker";
    case group::family: return "Family";
    case group::friends: return "Friends";
    }
    return nullptr;
}

void Contact::display() const
{
    std::cout << "{" << first_name_ << ", " << last_name_
    << ", " << first_phone_number_ << ", " << second_phone_number_ <<
        ", " << email_ << ", " << address_ << ", " << company_ << ", " <<
           group_to_string(group_) << "}" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
}




