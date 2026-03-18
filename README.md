Contact Manager

A small console-based C++ application for managing contact records through a menu-driven interface.

This project was built to practice core software engineering concepts in C++, including:

basic data modeling

modular program structure

input validation

user-driven control flow

separation of interface and implementation


Features

Add a new contact

Display all saved contacts in a formatted table

Search for a contact by ID

Update a contact's balance

Deactivate a contact without deleting the record

Validate user input before accepting values


Data Model

Each contact contains the following fields:

id — integer identifier

name — contact name

age — unsigned integer

gender — single-character value (M or F)

balance — floating-point account balance

isActive — status flag indicating whether the contact is active


The application stores contacts in a fixed-size in-memory array with a maximum capacity of 100 records.

Project Structure

Contact_Manager/
├── main.cpp
├── ContactManager.h
├── ContactManager.cpp
├── InputHelper.h
├── InputHelper.cpp
├── Contact_Manager.sln
├── Contact_Manager.vcxproj

File Overview

main.cpp
Entry point for the application. Initializes the contact array and launches the menu loop.

ContactManager.h
Defines the Contact struct, max capacity constant, and function declarations.

ContactManager.cpp
Contains the application’s core logic:

add contact

display contacts

search by ID

update balance

deactivate contact

menu handling


InputHelper.h / InputHelper.cpp
Provides a templated input helper function used to validate user input and retry on invalid entries.


How It Works

The program starts by creating an in-memory array of contacts and passing it into a menu-driven command loop.

From the menu, the user can:

1. add a contact


2. display all contacts


3. search for a contact by ID


4. update an existing contact’s balance


5. deactivate a contact


6. exit the program



Contacts are stored only for the duration of the program run. There is currently no file or database persistence.

Build and Run

Visual Studio

This project currently uses a Visual Studio solution and project file.

1. Open Contact_Manager.sln in Visual Studio


2. Build the solution


3. Run the application from the IDE



Example Workflow

1. Add Contact
2. Display Contacts
3. Search Contact by ID
4. Update Balance
5. Deactivate Contact
0. Exit

A typical session might include:

creating a contact

listing all contacts

searching for one by ID

updating the balance

deactivating the contact when no longer needed


Design Notes

This project emphasizes a few foundational software engineering ideas:

Separation of concerns
Core contact-management logic is separated from input handling.

Structured data representation
Contact information is grouped into a single Contact struct.

Input validation
A templated helper function is used to centralize and simplify validated console input.

Incremental modularization
The project is split into headers and implementation files instead of placing all logic in main.cpp.


Current Limitations

Uses a fixed-size array instead of a dynamic container

Data is stored in memory only and is lost when the program exits

Contact IDs are manually entered rather than automatically generated

No edit-contact workflow beyond balance updates

No duplicate-ID checking

No automated tests

No cross-platform build configuration yet


Planned Improvements

Potential next steps for the project:

Generate unique IDs automatically

Add full contact editing functionality

Prevent duplicate IDs

Replace the fixed-size array with std::vector

Add save/load support using a file format such as CSV or JSON

Add unit tests

Add a CMake build configuration for portability


Why This Project

This project was created as a focused C++ exercise to reinforce:

working with structs and arrays

modular design using header and source files

basic CLI application architecture

reusable input validation patterns


It also serves as a foundation that can be extended into a more robust contact system with persistence, testing, and modern container-based data management.