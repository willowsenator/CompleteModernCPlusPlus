#pragma once
#include <string>

class Contact
{
public:
    enum class group
    {
        friends, family, coworker, acquaintance
    };

    Contact();

    Contact(std::string first_name, std::string last_name, std::string first_phone_number,
            std::string second_phone_number, std::string email, std::string address
            , std::string company,
            group group);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_first_phone_number() const;
    std::string get_second_phone_number() const;
    std::string get_email() const;
    std::string get_address() const;
    std::string get_company() const;
    group get_group() const;

    void display() const;
    static constexpr const char* group_to_string(const group group) noexcept
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
    
private:
    std::string first_name_;
    std::string last_name_;
    std::string first_phone_number_;
    std::string second_phone_number_;
    std::string email_;
    std::string address_;
    std::string company_;
    group group_;
    
};
