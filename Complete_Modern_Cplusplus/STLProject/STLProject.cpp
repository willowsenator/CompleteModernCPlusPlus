
#include <iostream>

#include "model/Contact.h"
#include <list>

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

int main()
{
    const Contact contact1{"Alex", "ax4",
        "911234567", "653214356",
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

    std::list<Contact>contacts = {contact1, contact2, contact3, contact4};

    std::cout << "Sorted by firstName" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    display_all_contacts_sorted(contacts, true);

    std::cout << "Sorted by lastName" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    display_all_contacts_sorted(contacts, false);
    
    
    
    return 0;
}
