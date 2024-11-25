#include "ContactManager.h"
#include "InputHelper.h" // For getInput
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

// Add contact
void addContact(Contact contacts[], int& size) {
    if (size >= MAX_CONTACTS) {
        cout << "Contact list is full. Delete unused contacts before continuing." << endl;
        return;
    }

    Contact newContact;
    newContact.id = getInput<int>("Enter ID: ");
    newContact.name = getInput<std::string>("Enter Name: ", [](const std::string& name) { return !name.empty(); }, "Invalid name.");
    newContact.age = getInput<unsigned int>("Enter Age: ");
    newContact.gender = toupper(getInput<char>("Enter Gender (M/F): ", [](char gender) { return gender == 'M' || gender == 'F'; }, "Invalid input."));
    newContact.balance = getInput<float>("Enter Balance: ");
    newContact.isActive = true;

    contacts[size++] = newContact;
    cout << "Contact added successfully!" << endl;
}

// Display contacts
void displayContacts(const Contact contacts[], int size) {
    cout << std::setw(10) << std::left << "ID"
        << std::setw(20) << std::left << "Name"
        << std::setw(10) << std::left << "Age"
        << std::setw(10) << std::left << "Gender"
        << std::setw(15) << std::left << "Balance"
        << std::setw(10) << std::left << "Active" << endl;

    for (int i = 0; i < size; ++i) {
        cout << std::setw(10) << contacts[i].id
            << std::setw(20) << contacts[i].name
            << std::setw(10) << contacts[i].age
            << std::setw(10) << contacts[i].gender
            << std::setw(15) << contacts[i].balance
            << std::setw(10) << (contacts[i].isActive ? "Yes" : "No") << endl;
    }
}

// Search contact by ID
void searchContactById(const Contact contacts[], int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].id == id) {
            cout << std::setw(10) << contacts[i].id
                << std::setw(20) << contacts[i].name
                << std::setw(10) << contacts[i].age
                << std::setw(10) << contacts[i].gender
                << std::setw(15) << contacts[i].balance
                << std::setw(10) << (contacts[i].isActive ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Contact with ID " << id << " not found." << endl;
}

// Update balance
void updateBalance(Contact contacts[], float newBalance, int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].id == id) {
            contacts[i].balance = newBalance;
            cout << "Balance updated for contact with ID " << id << "." << endl;
            return;
        }
    }
    cout << "Contact with ID " << id << " not found." << endl;
}

// Deactivate contact
void deactivateContact(Contact& contact) {
    contact.isActive = false;
}

// Contact manager menu
void contactManagerMenu(Contact contacts[], int& size) {
    int userSelection;

    do {
        cout << "****************************************************" << endl;
        cout << "*         Welcome to Contact Manager!              *" << endl;
        cout << "*           1. Add Contact                         *" << endl;
        cout << "*           2. Display Contacts                    *" << endl;
        cout << "*           3. Search Contact by ID                *" << endl;
        cout << "*           4. Update Balance                      *" << endl;
        cout << "*           5. Deactivate Contact                  *" << endl;
        cout << "*           0. Exit                                *" << endl;
        cout << "****************************************************" << endl;

        userSelection = getInput<int>("Enter your choice: ", [](int c) { return c >= 0 && c <= 5; }, "Invalid choice.");
        switch (userSelection) {
        case 1: addContact(contacts, size); break;
        case 2: displayContacts(contacts, size); break;
        case 3: {
            int id = getInput<int>("Enter Contact ID to search: ");
            searchContactById(contacts, size, id);
            break;
        }
        case 4: {
            int id = getInput<int>("Enter Contact ID to update balance: ");
            float newBalance = getInput<float>("Enter new balance: ");
            updateBalance(contacts, newBalance, size, id);
            break;
        }
        case 5: {
            int id = getInput<int>("Enter Contact ID to deactivate: ");
            for (int i = 0; i < size; ++i) {
                if (contacts[i].id == id) {
                    deactivateContact(contacts[i]);
                    cout << "Contact deactivated." << endl;
                    break;
                }
            }
            break;
        }
        case 0: cout << "Exiting Contact Manager. Goodbye!" << endl; break;
        }
    } while (userSelection != 0);
}
