Contact Manager
===============

Contact Manager is a small console-based C++ application for creating, viewing, editing, searching, and deactivating contacts from a menu-driven interface.

The project is intentionally simple. It focuses on foundational C++ structure rather than persistence or a large feature set:

- small domain model
- separate headers and source files
- reusable input validation helpers
- straightforward command-line interaction

Features
--------

- add a contact with an auto-assigned ID
- display active contacts by default, with explicit views for all or inactive contacts
- search for a contact by ID
- edit an existing contact's name, age, gender, or balance
- deactivate a contact without deleting it
- validate all user input before accepting it

Data Model
----------

Each contact stores:

- `id`: integer identifier assigned by the application
- `name`: contact name
- `age`: unsigned integer
- `gender`: `M` or `F`
- `balance`: floating-point account balance
- `isActive`: active/inactive status flag

Soft-Delete Behavior
--------------------

Deactivation is implemented as a soft delete:

- deactivated contacts remain in memory
- default listing shows active contacts only
- the menu includes an explicit view for all contacts or inactive contacts
- search by ID still finds inactive contacts and shows their active status
- editing by ID is still allowed for inactive contacts

Persistence Approach
--------------------

Contacts are stored in memory inside `ContactBook` for the life of the process. There is currently no file or database persistence, so all data is lost when the program exits.

Project Layout
--------------

```text
Contact_Manager/
|-- include/
|   |-- ContactBook.h
|   |-- ContactMenu.h
|   `-- InputHelper.h
|-- src/
|   |-- ContactBook.cpp
|   |-- ContactMenu.cpp
|   |-- InputHelper.cpp
|   `-- main.cpp
|-- CMakeLists.txt
|-- Contact_Manager.sln
`-- Contact_Manager.vcxproj
```

Core Design
-----------

- `ContactBook` owns the collection of contacts and the next generated ID.
- `ContactMenu` handles user-facing workflows and menu control.
- `InputHelper` centralizes validated console input so parsing logic is not duplicated across menu actions.
- The application prefers simple, readable control flow over abstraction-heavy design.

Build And Run
-------------

Visual Studio 2022
------------------

These steps were verified by building the solution with MSBuild in `Release|x64` and running the produced executable.

1. Open `Contact_Manager.sln` in Visual Studio 2022.
2. Select the `Release` configuration and `x64` platform.
3. Build the solution.
4. Run with `Local Windows Debugger`, or launch `x64\Release\Contact_Manager.exe`.

Command line equivalent:

```powershell
$vsPath = & "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" `
  -latest -products * -requires Microsoft.Component.MSBuild -property installationPath
$msbuild = Join-Path $vsPath 'MSBuild\Current\Bin\MSBuild.exe'
& $msbuild Contact_Manager.sln /t:Build /p:Configuration=Release /p:Platform=x64
.\x64\Release\Contact_Manager.exe
```

CMake
-----

This path was also tested from the terminal:

```powershell
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
.\build\contact_manager.exe
```

Sample Session
--------------

The transcript below is based on a real run of the current executable:

```text
****************************************************
*         Welcome to Contact Manager!              *
*           1. Add Contact                         *
*           2. Display Active Contacts             *
*           3. Search Contact by ID                *
*           4. Edit Contact                        *
*           5. Deactivate Contact                  *
*           6. View All/Inactive Contacts          *
*           0. Exit                                *
****************************************************
Enter your choice: 1
Enter Name: Alice Johnson
Enter Age: 29
Enter Gender (M/F): F
Enter Balance: 125.50
Contact added successfully! ID: 1

Enter your choice: 2
ID        Name                Age       Gender    Balance        Active
1         Alice Johnson       29        F         125.5          Yes

Enter your choice: 0
Exiting Contact Manager. Goodbye!
```

Current Limitations
-------------------

- data is in-memory only
- no duplicate-contact checks beyond generated IDs
- no automated tests yet
- the interface is console-only

Repository Hygiene
------------------

- JetBrains Rider and other IDE-generated files are ignored through `.gitignore`.
- The repository keeps source, build configuration, and workflow files only; generated build outputs should stay untracked.
