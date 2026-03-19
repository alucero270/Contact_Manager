#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <string>
#include <vector>

struct Contact {
    int id;
    std::string name;
    unsigned int age;
    char gender;
    float balance;
    bool isActive;
};

class ContactBook {
public:
    void add(const Contact& contact);
    Contact* findById(int id);
    const Contact* findById(int id) const;
    const std::vector<Contact>& all() const;
    bool updateBalance(int id, float newBalance);
    bool deactivate(int id);
private:
    std::vector<Contact> contacts_;
    
};

// Function declarations
void contactManagerMenu(ContactBook& book);

#endif
