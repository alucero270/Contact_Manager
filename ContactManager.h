#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <string>
#include <iostream>

const int MAX_CONTACTS = 100;

struct Contact {
    int id;
    std::string name;
    unsigned int age;
    char gender;
    float balance;
    bool isActive;
};

// Function declarations
void addContact(Contact contacts[], int& size);
void displayContacts(const Contact contacts[], int size);
void searchContactById(const Contact contacts[], int size, int id);
void updateBalance(Contact contacts[], float newBalance, int size, int id);
void deactivateContact(Contact& contact);
void contactManagerMenu(Contact contacts[], int& size);

#endif
