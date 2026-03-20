#include "ContactBook.h"

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

bool ContactBook::updateContact(int id, const Contact& updatedContact)
{
    Contact* contact = findById(id);
    if (contact == nullptr)
    {
        return false;
    }

    contact->name = updatedContact.name;
    contact->age = updatedContact.age;
    contact->gender = updatedContact.gender;
    contact->balance = updatedContact.balance;

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
