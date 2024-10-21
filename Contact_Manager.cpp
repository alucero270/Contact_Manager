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

using std::cout;
using std::cin;
using std::endl;
using std::array;

struct Contact
{
	int id; //(unique ID for each contact)
	std::string name; //(contact's name)
	unsigned int age; //(contact's age, ensuring it is non-negative)
	char gender; //('M' for Male, 'F' for Female, etc.)
	float balance; //(contact's balance with decimal values)
	bool isActive; //(whether the contact is active or inactive)
};

/*- Prompt the user to input details for a new contact and add it to the array.*/
void addContact(Contact contacts[], int& size) 
{
	/*
		Enter ID: 101
		Enter Name: Alex
		Enter Age: 30
		Enter Gender (M/F): M
		Enter Balance: 100.50
		Contact added successfully!
		
	*/
}

/*- Display details of all contacts in the array.*/
void displayContacts(const Contact contacts[], int size) 
{
	/* list all contacts*/
}

/*- Search for a contact by their ID and display the details if found.*/
void searchContactById(const Contact contacts[], int size, int id) 
{
	/*
		Enter your choice: 2
		ID: 101, Name: Alex, Age: 30, Gender: M, Balance: 100.50, Active: true
	*/
}

/*- Update a contact’s balance using the provided value.*/
void updateBalance(Contact& contact, float newBalance) 
{

}

/*- Change a contact’s isActive status to false.*/
void deactivateContact(Contact& contact) 
{

}

void contactManagerMenu()
{

}

int main()
{
	/*
	Implement main to offer a simple menu allowing the user to:
		- Use appropriate input/output prompts and error checking to ensure valid entries.
	*/
	int userSelection;

	// ANSI escape codes for coloring (works in most Unix-based terminals)
	const std::string reset = "\033[0m";
	const std::string cyan = "\033[36m";

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
	cout << "Enter your choice: ";
	cin >> userSelection;

	// Handle user selection...
	do
	{
		while (userSelection > 6 || userSelection < 0)
		{
			cout << "Wait, that is not valid" << endl;
			cout << "Please enter a valid selection:" << endl;
			cin >> userSelection;
		}
		switch (userSelection)
		{
		case 1:
			cout << "addContact";
			return 0;
		case 2:
			cout << "displayContacts";
			return 0;
		case 3:
			cout << "searchContactById";
			return 0;
		case 4:
			cout << "updateBalance";
			return 0;
		case 5:
			cout << "deactivateContact";
			return 0;
		case 0:
			cout << "Have a nice day!";
		default:
			return 0;
		}
	} while (userSelection != 5);
	
	
}

