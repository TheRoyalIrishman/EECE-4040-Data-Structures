#include "Book.h"
#include <stdexcept>

void Book::addEntry(Person newPerson) {
    BST_Node * newNode = new BST_Node(newPerson);

    if (logbook == nullptr) {
        logbook = newNode;
    } else {
        BST_Node * focusNode = logbook;

        BST_Node * parentNode;

        while (true) {
            parentNode = focusNode;

            if (newPerson < focusNode->m_person) {
                focusNode = focusNode->left;

                if (focusNode == nullptr) {
                    parentNode->left = newNode;
                    return;
                }
            } else {
                focusNode = focusNode->right;


                if (focusNode == nullptr) {
                    parentNode->right = newNode;
                    return;
                }
            }
        }
    }
}

// on how to do an inorder traversal of a BST
void Book::inorderTraversal(BST_Node * nodePtr) const {
    if (nodePtr != nullptr) {
        inorderTraversal(nodePtr->left);
        cout << "First Name: " << nodePtr->m_person.firstName << endl;
        cout << "Last Name: " << nodePtr->m_person.lastName << endl;
        cout << "Phone Number: " << nodePtr->m_person.phoneNumber << endl;
        inorderTraversal(nodePtr->right);
    }
}

string Book::findPhoneNumber(const string& firstName, const string& lastName) const {
    BST_Node * currNode = this->logbook;
    while (currNode) {
        if (lastName < currNode->m_person.lastName) {
            currNode = currNode->left;
        } else if (lastName > currNode->m_person.lastName) {
            currNode = currNode->right;
        } else if (firstName < currNode->m_person.firstName) {
            currNode = currNode->left;
        } else if (firstName > currNode->m_person.firstName) {
            currNode = currNode->right;
        } else {
            // both names match
            return currNode->m_person.phoneNumber;
        }
    }

    // It wasn't found
    throw out_of_range("No person with the given name");
}
