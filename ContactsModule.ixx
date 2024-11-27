module;

#include <iomanip>
#include <string>
#include <iostream>
#include <functional>
#include <string>
#include <limits>
export module ContactsModule;


using std::cout;
using std::cin;
using std::endl;

export template <typename T>
T getInput(const std::string& prompt) {
    return getInput<T>(prompt, [](T) { return true; }, "Invalid input. Please try again: ");
}



export template <typename T>
T getInput(const std::string& prompt, const std::function<bool(T)>& validator, const std::string& errorMsg) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && validator(value)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << errorMsg;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

export struct Contact {
    int id;
    std::string name;
    unsigned int age;
    char gender;
    float balance;
    bool isActive;
};
export const int MAX_CONTACTS = 100;

export void addContact(Contact contacts[], int& size) {
    if (size >= MAX_CONTACTS) {
        cout << "Contact list is full. Delete unused contacts before continuing." << endl;
        return;
    }

    Contact newContact;
    newContact.id = getInput<int>("Enter ID: ");
    newContact.name = getInput<std::string>("Enter Name: ",
        [](const std::string& name) { return !name.empty(); },
        "Invalid name.");
    newContact.age = getInput<unsigned int>("Enter Age: ");
    newContact.gender = toupper(getInput<char>("Enter Gender (M/F): ",
        [](char gender) { return gender == 'M' || gender == 'F'; },
        "Invalid input."));
    newContact.balance = getInput<float>("Enter Balance: ");
    newContact.isActive = true;

    contacts[size++] = newContact;
    cout << "Contact added successfully!" << endl;
}

// Display contacts
export void displayContacts(const Contact contacts[], int size) {
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
export void searchContactById(const Contact contacts[], int size, int id) {
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
export void updateBalance(Contact contacts[], float newBalance, int size, int id) {
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
export void deactivateContact(Contact& contact) {
    contact.isActive = false;
}