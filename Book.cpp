#include "Book.h"

void Book::addEntry(Person newPerson) {
    BST_Node * newNode = new BST_Node(newPerson);

    if (logbook == nullptr) {
        logbook = newNode;
    } else {
        
    }
}

// on how to do an inorder traversal of a BST
void Book::inorderTraversal(BST_Node * nodePtr) {
    if (nodePtr != nullptr) {
        inorderTraversal(nodePtr->left);
        cout << "First Name: " << nodePtr->m_person.firstName << endl;
        cout << "Last Name: " << nodePtr->m_person.lastName << endl;
        cout << "Phone Number: " << nodePtr->m_person.phoneNumber << endl;
        inorderTraversal(nodePtr->right);
    }
}