#include "../include/ContactManager.h"
#include "../include/InputHelper.h"
#include <iomanip>

using std::cout;

// Store Contacts
int ContactBook::add(Contact contact)
{
    contact.id = nextId_;
    contacts_.push_back(contact);
    nextId_++;
    return contact.id;
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

// Contact manager menu
void contactManagerMenu(ContactBook& book)
{
    int userSelection;

    do
    {
        cout << "****************************************************" << '\n';
        cout << "*         Welcome to Contact Manager!              *" << '\n';
        cout << "*           1. Add Contact                         *" << '\n';
        cout << "*           2. Display Contacts                    *" << '\n';
        cout << "*           3. Search Contact by ID                *" << '\n';
        cout << "*           4. Update Balance                      *" << '\n';
        cout << "*           5. Deactivate Contact                  *" << '\n';
        cout << "*           0. Exit                                *" << '\n';
        cout << "****************************************************" << '\n';

        userSelection = getInput<int>("Enter your choice: ", [](int c) { return c >= 0 && c <= 5; }, "Invalid choice.");
        switch (userSelection)
        {
        default:
            cout << "Invalid choice.\n";
            break;
        case 1:
            {
                Contact newContact;
                newContact.name = getInput<std::string>(
                    "Enter Name: ",
                    [](const std::string& name) { return !name.empty(); },
                    "Invalid name."
                );
                newContact.age = getInput<unsigned int>("Enter Age: ");
                newContact.gender = getInput<char>(
                    "Enter Gender (M/F): ",
                    [](char gender) { return gender == 'M' || gender == 'F'; },
                    "Invalid input."
                );
                newContact.balance = getInput<float>("Enter Balance: ");
                newContact.isActive = true;

                int assignedId = book.add(newContact);
                cout << "Contact added successfully! ID: " << assignedId << '\n';
            }
            break;
        case 2:
            {
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
                int id = getInput<int>("Enter Contact ID to search: ");
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
                int id = getInput<int>("Enter Contact ID to update balance: ");
                float newBalance = getInput<float>("Enter new balance: ");
                if (book.updateBalance(id, newBalance))
                {
                    cout << "Balance updated for contact with ID " << id << "." << '\n';
                }
                else
                {
                    cout << "Contact with ID " << id << " not found." << '\n';
                }
                break;
            }
        case 5:
            {
                int id = getInput<int>("Enter Contact ID to deactivate: ");
                if (book.deactivate(id))
                {
                    cout << "Contact deactivated." << '\n';
                }
                else
                {
                    cout << "Contact with ID " << id << " not found." << '\n';
                }
                break;
            }
        case 0: cout << "Exiting Contact Manager. Goodbye!" << '\n';
            break;
        }
    }
    while (userSelection != 0);
}
