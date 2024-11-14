/*
Challenge: Contact Management System
Create a simple command-line contact management system.
It should allow users to add, display, and search for contacts.
Each contact will have basic details such as an ID, name, age,
and phone number, and include various operations that make
use of different data types.

*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <algorithm>
#include <functional>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::numeric_limits;
using std::streamsize;

const int MAX_CONTACTS = 100;

struct Contact
{
	int id; //(unique ID for each contact)
	string name; //(contact's name)
	unsigned int age; //(contact's age, ensuring it is non-negative)
	char gender; //('M' for Male, 'F' for Female, etc.)
	float balance; //(contact's balance with decimal values)
	bool isActive; //(whether the contact is active or inactive)
};

#include <functional>

// Helper function to validate input with an optional validator
template <typename T>
T getInput(const std::string& prompt, const std::function<bool(T)>& validator = [](T) { return true; }, const std::string& errorMsg = "Invalid input. Please try again: ") {
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


// addContact function
void addContact(Contact contacts[], int& size) {
	if (size >= MAX_CONTACTS) {
		std::cout << "Contact list is full. Delete unused contacts before continuing." << std::endl;
		return;
	}

	Contact newContact;
	newContact.id = getInput<int>("Enter ID: ");
	newContact.name = getInput<std::string>("Enter Name: ", [](const string& name) { return !name.empty(); }, "Invalid name.");
	newContact.age = getInput<unsigned int>("Enter Age: ");
	newContact.gender = getInput<char>("Enter Gender (M/F): ", [](char gender) { return gender == 'M' || gender == 'F'; }, "Invalid gender.");
	newContact.balance = getInput<float>("Enter Balance: ");
	newContact.isActive = true;

	contacts[size++] = newContact;
	std::cout << "Contact added successfully!" << std::endl;
}


/*- Display details of all contacts in the array.*/
void displayContacts(const Contact contacts[], int size)
{
	/* list all contacts*/
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

/*- Search for a contact by their ID and display the details if found.*/
void searchContactById(const Contact contacts[], int size, int id)
{
	for (int i = 0; i < size; ++i) {
		cout << std::setw(10) << contacts[i].id
			<< std::setw(20) << contacts[i].name
			<< std::setw(10) << contacts[i].age
			<< std::setw(10) << contacts[i].gender
			<< std::setw(15) << contacts[i].balance
			<< std::setw(10) << (contacts[i].isActive ? "Yes" : "No") << endl;
	}
}

/*- Update a contact’s balance using the provided value.*/
void updateBalance(Contact& contact, float newBalance)
{
	contact.balance = newBalance;
}

/*- Change a contact’s isActive status to false.*/
void deactivateContact(Contact& contact)
{
	contact.isActive = false;
}

void contactManagerMenu(Contact contacts[], int& size) {
	int userSelection;

	// Handle user selection...
	do
	{
		// ANSI escape codes for coloring (works in most Unix-based terminals)
		const string reset = "\033[0m";
		const string cyan = "\033[36m";

		cout << cyan; // Set text color to cyan
		cout << "****************************************************" << endl;
		cout << "*                                                  *" << endl;
		cout << "*         Welcome to Contact Manager!              *" << endl;
		cout << "*         Please select an option from below:      *" << endl;
		cout << "*                                                  *" << endl;
		cout << "*           1. Add Contact                         *" << endl;
		cout << "*           2. Display Contacts                    *" << endl;
		cout << "*           3. Search Contact by ID                *" << endl;
		cout << "*           4. Update Balance                      *" << endl;
		cout << "*           5. Deactivate Contact                  *" << endl;
		cout << "*           0. Exit                                *" << endl;
		cout << "*                                                  *" << endl;
		cout << "****************************************************" << endl;
		cout << reset; // Reset text color to default
		userSelection = getInput<int>("Enter your choice: ", [](int c) { return c >= 0 && c <= 5; }, "Invalid choice.");
		/*while (userSelection > 6 || userSelection < 0)
		{
			cout << "Wait, that is not valid" << endl;
			cout << "Please enter a valid selection:" << endl;
			cin >> userSelection;
		}*/
		switch (userSelection) {
		case 1: addContact(contacts, size); break;
		case 2:
			displayContacts(contacts, size);
			break;
		case 3: {
			int id = getInput<int>("Enter Contact ID to search: ");
			searchContactById(contacts, size, id);
			break;
		}
		case 4: {
			int id = getInput<int>("Enter Contact ID to update balance: ");
			float newBalance = getInput<float>("Enter new balance: ");
			for (int i = 0; i < size; ++i) {
				if (contacts[i].id == id) {
					updateBalance(contacts[i], newBalance);
					cout << "Balance updated." << endl;
					break;
				}
			}
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


int main()
{
	Contact contacts[MAX_CONTACTS];
	int size = 0;
	contactManagerMenu(contacts, size);
	return 0;
}
