#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H

#include <string>
#include <vector>

struct Contact
{
    int id;
    std::string name;
    unsigned int age;
    char gender;
    float balance;
    bool isActive;
};

enum class ContactFilter
{
    Active,
    Inactive,
    All
};

enum class DeactivateResult
{
    Success,
    NotFound,
    AlreadyInactive
};

class ContactBook
{
public:
    int add(Contact contact);
    Contact* findById(int id);
    const Contact* findById(int id) const;
    const std::vector<Contact>& all() const;
    bool updateContact(int id, const Contact& updatedContact);
    std::vector<Contact> getContacts(ContactFilter filter) const;
    DeactivateResult deactivate(int id);

private:
    std::vector<Contact> contacts_;
    int nextId_ = 1;
};

#endif
