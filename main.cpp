#include <iostream>

#include "Book.cpp"
#include "Person.cpp"

int main() {
    bool Quit = false;
    int Option;
    Book * NewBook;
    while (Quit==false) {
        // Ask for user input
        cout << "Please Enter Number of Option \n1. Add\n2. Delete\n3. Find\n4. Change\n5. Display\n6. Quit" << endl;
        cin >> Option;
        // Based on user input, do the desired function
        switch (Option) {
            case 1:
                int FirstName;
                int LastName;
                string PhoneNumber;
                cout << "Please input the person's first name, last name, and phone number" << endl;
                cin >> FirstName;
                cin >> LastName;
                cin >> PhoneNumber;
                Person * NewPerson;
                NewPerson.firstName = FirstName;
                NewPerson.lastName = LastName;
                NewPerson.phoneNumber = PhoneNumber;
                NewBook::addEntry(NewPerson);
            case 2:
                int FirstName;
                int LastName;
                cout << "Please input the person's first name and last name" << endl;
                cin >> FirstName;
                cin >> LastName;
                NewBook::deleteEntry(FirstName, LastName);
            case 3:
                int FirstName;
                int LastName;
                cout << "Please input the person's first name and last name" << endl;
                cin >> FirstName;
                cin >> LastName;
                NewBook::findPerson(FirstName, LastName);
            case 4:
                int FirstName;
                int LastName;
                string NewPhoneNumber;
                cout << "Please input the person's first name, last name, and phone number" << endl;
                cin >> FirstName;
                cin >> LastName;
                cin >> NewPhoneNumber;
                Person * NewPerson;
                NewPerson.firstName = FirstName;
                NewPerson.lastName = LastName;
                NewPerson.phoneNumber = NewPhoneNumber;
                NewBook::changePhoneNumber(NewPerson);
            case 5:
                NewBook::inorderTraversal(NewBook);
            case 6:
                // Needs help
                NewBook::quitAndSavePhoneBook(NewBook, );
                Quit=true;
        }
    }
}