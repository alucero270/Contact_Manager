#include "ContactManager.h"

import ContactsModule; 
/*
    ToDo:
    [] generate uid when contact is created
    [] add update contact functionality
    []
*/
int main() {
    Contact contacts[MAX_CONTACTS];
    int size = 0;
    contactManagerMenu(contacts, size);
    return 0;
}
