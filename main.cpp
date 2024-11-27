#include "ContactManager.h"

import ContactsModule; 
/*
    ToDo:
    [] generate uid when contact is created
    [] add update contact functionality
    [] validate balance input
    [] hide deactive contacts
    [] add gui
    [] write contacts to file
    [] add contacts from file
    [] find duplicates
    []
*/
int main() {
    Contact contacts[MAX_CONTACTS];
    int size = 0;
    contactManagerMenu(contacts, size);
    return 0;
}
