
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <ostream>
#include <set>
#include <string>

#include "model/Contact.h"



const Contact contact1{"Alex", "ax4",
       "921234577", "653214356",
       "alex@email.com", "address1", "company1", Contact::group::family};


const Contact contact2{"Alex2", "ax3",
    "921234527", "653214351",
    "alex2@email.com", "address2", "company2", Contact::group::family};

const Contact contact3{"Alex3", "ax2",
    "911234167", "653214353",
    "alex3@email.com", "address3", "company2", Contact::group::friends};

const Contact contact4{"Alex4", "ax5",
    "911234587", "653214756",
    "alex4@email.com", "address4", "company3", Contact::group::acquaintance};

auto cmp_set = [](const Contact& item1, const Contact& item2)
{
    return item1.get_first_name() < item2.get_first_name();
};

void display_all_contacts_sorted(std::list<Contact> &contacts, const bool is_sorted_by_first_name)
{
    if(is_sorted_by_first_name)
    {
        contacts.sort([](const Contact& contact1, const Contact& contact2)
        {
                return contact1.get_first_name() < contact2.get_first_name();
        });    
    }
    else
    {
        contacts.sort([](const Contact& contact1, const Contact& contact2)
       {
               return contact1.get_last_name() < contact2.get_last_name();
       });    
    }

    for (const auto& contact : contacts)
    {
        contact.display();
    } 
}

void display_first_name_with_first_number(std::list<Contact> &contacts_list)
{
    std::ranges::for_each(contacts_list, [](const Contact& contact)
    {
        std::cout << "{" << contact.get_first_name() << ", " << contact.get_first_phone_number() << "}" << std::endl;
    });
}

void display_contacts_by_company(std::map<std::string, std::list<Contact>> contacts_by_company_map, const std::string& company)
{
    const auto contacts_pair = contacts_by_company_map.find(company);
    if(contacts_pair != contacts_by_company_map.end())
    {
        std::ranges::for_each(contacts_pair->second, [](const Contact& contact)
        {
            contact.display();
        });
    }
    else
    {
        std::cout << "Not found contacts for that company" << std::endl;
    }
}

void display_contacts_by_group(std::map<Contact::group, std::list<Contact>> contacts_by_group_map, const Contact::group& group)
{
    if(const auto contacts_pair = contacts_by_group_map.find(group); contacts_pair != contacts_by_group_map.end())
    {
        std::ranges::for_each(contacts_pair->second, [](const Contact& contact)
        {
            contact.display();
        });
    }
    else
    {
        std::cout << "Not found contacts for that group" << std::endl;
    }
}

void find_contacts_by_first_name_or_second_name(std::set<Contact, decltype(cmp_set)> &contacts_set, const Contact& contact)
{
    if (const auto contact_search = contacts_set.find(contact); contact_search != contacts_set.end())
    {
        contact_search->display();
    }
    else
    {
        std::cout << "Not found contact in the set" << std::endl;
    }
}

void count_contacts_by_company_and_group(std::map<std::string, std::list<Contact>> map_by_company,
    std::map<Contact::group, std::list<Contact>> map_by_group)
{
    
    std::ranges::for_each(map_by_company, [](const auto &contact_pair)
    {
        std::cout << contact_pair.first << ": " << contact_pair.second.size() << std::endl;
    });

    std::ranges::for_each(map_by_group, [](const auto &contact_pair)
    {
        std::cout << Contact::group_to_string(contact_pair.first) << ": " << contact_pair.second.size() << std::endl;
    });
}


int main()
{
    std::list contacts_list = {contact1, contact2, contact3, contact4};

    const std::map<std::string, std::list<Contact>> contacts_by_company_map = {{"company1", {contact1}},
    {"company2",{contact2, contact3}}, {"company3",{contact4}}};

    
    std::map<Contact::group, std::list<Contact>> contacts_by_group_map;
    std::list contacts_family_list{contact1, contact2};
    std::list contacts_friends_list{contact3};
    std::list contacts_acquaintance_list{contact4};
    
    contacts_by_group_map.insert(std::pair(Contact::group::family,contacts_family_list));
    contacts_by_group_map.insert(std::pair(Contact::group::friends,contacts_friends_list));
    contacts_by_group_map.insert(std::pair(Contact::group::acquaintance,contacts_acquaintance_list));

    std::set<Contact, decltype(cmp_set)> contacts_set(cmp_set);
    contacts_set.insert({contact1, contact2, contact3, contact4});


     std::cout << "Sorted by firstName" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    display_all_contacts_sorted(contacts_list, true);

    std::cout << "Sorted by lastName" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    display_all_contacts_sorted(contacts_list, false);

    std::cout << "Display only first name with first number" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_first_name_with_first_number(contacts_list);


    std::cout << R"(Display contacts by company "company1")" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_company(contacts_by_company_map, "company1");

    

    std::cout << R"(Display contacts by company "c" Not found)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_company(contacts_by_company_map, "c");
    

    std::cout << R"(Display contacts by company "company2")" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_company(contacts_by_company_map, "company2");

    std::cout << R"(Display contacts by group "friends")" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_group(contacts_by_group_map, Contact::group::friends);

    std::cout << R"(Display contacts by group "family")" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_group(contacts_by_group_map, Contact::group::family);

    std::cout << R"(Display contacts by group "coworker")" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    display_contacts_by_group(contacts_by_group_map, Contact::group::coworker);

    std::cout << R"(Search contact1 in set)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    find_contacts_by_first_name_or_second_name(contacts_set, contact1);

    std::cout << R"(Search new Contact in set)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    const Contact contact_new{};
    find_contacts_by_first_name_or_second_name(contacts_set, contact_new);


    std::cout << R"(Search contact2 in set)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    find_contacts_by_first_name_or_second_name(contacts_set, contact2);

    std::cout << R"(Count elements by company and group)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    count_contacts_by_company_and_group(contacts_by_company_map, contacts_by_group_map);
    
    return 0;
}
