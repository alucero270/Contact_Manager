import  ContactsModule;
#include "ContactManager.h"

using std::cout;
using std::endl;

// Add contact




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