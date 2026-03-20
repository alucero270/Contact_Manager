#include "ContactMenu.h"
#include "InputHelper.h"
#include <iomanip>
#include <iostream>

using std::cout;

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

            cout << "Contact with that ID was not found. Please try again." << '\n';
        }
    }
}

// Contact manager menu
void contactMenu(ContactBook& book)
{
    int userSelection;

    do
    {
        cout << "****************************************************" << '\n';
        cout << "*         Welcome to Contact Manager!              *" << '\n';
        cout << "*           1. Add Contact                         *" << '\n';
        cout << "*           2. Display Contacts                    *" << '\n';
        cout << "*           3. Search Contact by ID                *" << '\n';
        cout << "*           4. Edit Contact                        *" << '\n';
        cout << "*           5. Deactivate Contact                  *" << '\n';
        cout << "*           0. Exit                                *" << '\n';
        cout << "****************************************************" << '\n';

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
                newContact.age = static_cast<unsigned int>(promptIntInRange(
                    "Enter Age: ",
                    0,
                    150,
                    "Invalid age. Enter a whole number from 0 to 150."
                ));
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
                cout << "Contact added successfully! ID: " << assignedId << '\n';
            }
            break;
        case 2:
            {
                if (book.all().empty())
                {
                    cout << "There are no contacts to display." << '\n';
                    break;
                }

                cout << std::setw(10) << std::left << "ID"
                    << std::setw(20) << std::left << "Name"
                    << std::setw(10) << std::left << "Age"
                    << std::setw(10) << std::left << "Gender"
                    << std::setw(15) << std::left << "Balance"
                    << std::setw(10) << std::left << "Active" << '\n';
                for (const Contact& contact : book.all())
                {
                    cout << std::setw(10) << contact.id
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
                    cout << "There are no contacts to search." << '\n';
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
                    cout << std::setw(10) << contact->id
                        << std::setw(20) << contact->name
                        << std::setw(10) << contact->age
                        << std::setw(10) << contact->gender
                        << std::setw(15) << contact->balance
                        << std::setw(10) << (contact->isActive ? "Yes" : "No") << '\n';
                }
                else
                {
                    cout << "Contact with ID " << id << " not found." << '\n';
                }
                break;
            }
        case 4:
            {
                if (book.all().empty())
                {
                    cout << "There are no contacts to edit." << '\n';
                    break;
                }

                Contact* contact = promptForExistingContact(
                    book,
                    "Enter Contact ID to edit: "
                );
                Contact updatedContact = *contact;
                int editChoice;

                do
                {
                    cout << "1. Edit Name\n";
                    cout << "2. Edit Age\n";
                    cout << "3. Edit Gender\n";
                    cout << "4. Edit Balance\n";
                    cout << "0. Save and Return\n";

                    editChoice = promptIntInRange(
                        "Choose a field to edit: ",
                        0,
                        4,
                        "Invalid choice. Enter a number from 0 to 4."
                    );

                    switch (editChoice)
                    {
                    case 1:
                        updatedContact.name = promptRequiredText(
                            "Enter new name: ",
                            "Name cannot be empty."
                        );
                        cout << "Name updated." << '\n';
                        break;
                    case 2:
                        updatedContact.age = static_cast<unsigned int>(promptIntInRange(
                            "Enter new age: ",
                            0,
                            150,
                            "Invalid age. Enter a whole number from 0 to 150."
                        ));
                        cout << "Age updated." << '\n';
                        break;
                    case 3:
                        updatedContact.gender = promptGender(
                            "Enter new gender (M/F): ",
                            "Invalid gender. Enter M or F."
                        );
                        cout << "Gender updated." << '\n';
                        break;
                    case 4:
                        updatedContact.balance = promptFloatInRange(
                            "Enter new balance: ",
                            0.0f,
                            1000000.0f,
                            "Invalid balance. Enter a non-negative number."
                        );
                        cout << "Balance updated." << '\n';
                        break;
                    case 0:
                        break;
                    }
                }
                while (editChoice != 0);

                if (book.updateContact(contact->id, updatedContact))
                {
                    cout << "Contact updated for ID " << contact->id << "." << '\n';
                }
                else
                {
                    cout << "Contact with ID " << contact->id << " not found." << '\n';
                }
                break;
            }
        case 5:
            {
                if (book.all().empty())
                {
                    cout << "There are no contacts to deactivate." << '\n';
                    break;
                }

                Contact* contact = promptForExistingContact(
                    book,
                    "Enter Contact ID to deactivate: "
                );

                if (book.deactivate(contact->id))
                {
                    cout << "Contact deactivated." << '\n';
                }
                else
                {
                    cout << "Contact with ID " << contact->id << " not found." << '\n';
                }
                break;
            }
        case 0:
            cout << "Exiting Contact Manager. Goodbye!" << '\n';
            break;
        }
    }
    while (userSelection != 0);
}
