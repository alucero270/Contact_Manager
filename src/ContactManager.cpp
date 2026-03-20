#include "../include/ContactManager.h"
#include "../include/InputHelper.h"
#include <iomanip>
#include <iostream>

// Store Contacts
int ContactBook::add(Contact contact)
{
    int assignedId = nextId_;
    contact.id = assignedId;
    contacts_.push_back(contact);
    nextId_++;
    return assignedId;
}

Contact* ContactBook::findById(int id)
{
    for (Contact& contact : contacts_)
    {
        if (contact.id == id)
        {
            return &contact;
        }
    }
    return nullptr;
}

const Contact* ContactBook::findById(int id) const
{
    for (const Contact& contact : contacts_)
    {
        if (contact.id == id)
        {
            return &contact;
        }
    }
    return nullptr;
}

const std::vector<Contact>& ContactBook::all() const
{
    return contacts_;
}

bool ContactBook::updateBalance(int id, float newBalance)
{
    Contact* contact = findById(id);
    if (contact == nullptr)
    {
        return false;
    }

    if (newBalance < 0.0f)
    {
        return false;
    }

    contact->balance = newBalance;
    return true;
}

bool ContactBook::deactivate(int id)
{
    Contact* contact = findById(id);
    if (contact == nullptr)
    {
        return false;
    }

    contact->isActive = false;
    return true;
}

namespace
{
    Contact* promptForExistingContact(ContactBook& book, const std::string& prompt)
    {
        while (true)
        {
            int id = promptIntInRange(
                prompt,
                1,
                1000000,
                "Invalid ID. Enter a positive whole number."
            );

            Contact* contact = book.findById(id);
            if (contact != nullptr)
            {
                return contact;
            }

            std::cout << "Contact with that ID was not found. Please try again." << '\n';
        }
    }
}

// Contact manager menu
void contactManagerMenu(ContactBook& book)
{
    int userSelection;

    do
    {
        std::cout << "****************************************************" << '\n';
        std::cout << "*         Welcome to Contact Manager!              *" << '\n';
        std::cout << "*           1. Add Contact                         *" << '\n';
        std::cout << "*           2. Display Contacts                    *" << '\n';
        std::cout << "*           3. Search Contact by ID                *" << '\n';
        std::cout << "*           4. Update Balance                      *" << '\n';
        std::cout << "*           5. Deactivate Contact                  *" << '\n';
        std::cout << "*           0. Exit                                *" << '\n';
        std::cout << "****************************************************" << '\n';

        userSelection = promptIntInRange(
            "Enter your choice: ",
            0,
            5,
            "Invalid choice. Enter a number from 0 to 5."
        );

        switch (userSelection)
        {
        case 1:
        {
            Contact newContact;
            newContact.name = promptRequiredText(
                "Enter Name: ",
                "Name cannot be empty."
            );
            newContact.age = promptIntInRange(
                "Enter Age: ",
                0,
                150,
                "Invalid age. Enter a whole number from 0 to 150."
            );
            newContact.gender = promptGender(
                "Enter Gender (M/F): ",
                "Invalid gender. Enter M or F."
            );
            newContact.balance = promptFloatInRange(
                "Enter Balance: ",
                0.0f,
                1000000.0f,
                "Invalid balance. Enter a non-negative number."
            );
            newContact.isActive = true;

            int assignedId = book.add(newContact);
            std::cout << "Contact added successfully! ID: " << assignedId << '\n';
            break;
        }
        case 2:
        {
            if (book.all().empty())
            {
                std::cout << "There are no contacts to display." << '\n';
                break;
            }

            std::cout << std::setw(10) << std::left << "ID"
                << std::setw(20) << std::left << "Name"
                << std::setw(10) << std::left << "Age"
                << std::setw(10) << std::left << "Gender"
                << std::setw(15) << std::left << "Balance"
                << std::setw(10) << std::left << "Active" << '\n';

            for (const Contact& contact : book.all())
            {
                std::cout << std::setw(10) << contact.id
                    << std::setw(20) << contact.name
                    << std::setw(10) << contact.age
                    << std::setw(10) << contact.gender
                    << std::setw(15) << contact.balance
                    << std::setw(10) << (contact.isActive ? "Yes" : "No") << '\n';
            }
            break;
        }
        case 3:
        {
            if (book.all().empty())
            {
                std::cout << "There are no contacts to search." << '\n';
                break;
            }

            int id = promptIntInRange(
                "Enter Contact ID to search: ",
                1,
                1000000,
                "Invalid ID. Enter a positive whole number."
            );

            const Contact* contact = book.findById(id);

            if (contact != nullptr)
            {
                std::cout << std::setw(10) << contact->id
                    << std::setw(20) << contact->name
                    << std::setw(10) << contact->age
                    << std::setw(10) << contact->gender
                    << std::setw(15) << contact->balance
                    << std::setw(10) << (contact->isActive ? "Yes" : "No") << '\n';
            }
            else
            {
                std::cout << "Contact with ID " << id << " not found." << '\n';
            }
            break;
        }
        case 4:
        {
            if (book.all().empty())
            {
                std::cout << "There are no contacts to update." << '\n';
                break;
            }

            Contact* contact = promptForExistingContact(
                book,
                "Enter Contact ID to update balance: "
            );

            float newBalance = promptFloatInRange(
                "Enter new balance: ",
                0.0f,
                1000000.0f,
                "Invalid balance. Enter a non-negative number."
            );

            book.updateBalance(contact->id, newBalance);
            std::cout << "Balance updated for contact with ID " << contact->id << "." << '\n';
            break;
        }
        case 5:
        {
            if (book.all().empty())
            {
                std::cout << "There are no contacts to deactivate." << '\n';
                break;
            }

            Contact* contact = promptForExistingContact(
                book,
                "Enter Contact ID to deactivate: "
            );

            book.deactivate(contact->id);
            std::cout << "Contact deactivated." << '\n';
            break;
        }
        case 0:
            std::cout << "Exiting Contact Manager. Goodbye!" << '\n';
            break;
        }
    }
    while (userSelection != 0);
}