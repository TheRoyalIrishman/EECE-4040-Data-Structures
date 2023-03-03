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
        if (nodePtr->left) {
            inorderTraversal(nodePtr);
        }

        cout << "First Name: " << nodePtr->m_person.firstName << endl;
        cout << "Last Name: " << nodePtr->m_person.lastName << endl;
        cout << "Phone Number: " << nodePtr->m_person.phoneNumber << endl;

        if (nodePtr->right) {
            inorderTraversal(nodePtr);
        }
    }
}

pair<BST_Node *, BST_Node *> Book::findPerson(const string& firstName, const string& lastName) const {
    BST_Node * prevNode = nullptr;
    BST_Node * currNode = this->logbook;
    while (currNode) {
        if (lastName < currNode->m_person.lastName) {
            prevNode = currNode;
            currNode = currNode->left;
        } else if (lastName > currNode->m_person.lastName) {
            prevNode = currNode;
            currNode = currNode->right;
        } else if (firstName < currNode->m_person.firstName) {
            prevNode = currNode;
            currNode = currNode->left;
        } else if (firstName > currNode->m_person.firstName) {
            prevNode = currNode;
            currNode = currNode->right;
        } else {
            // both names match
            break;
        }
    }
    return { currNode, prevNode };
}

string Book::findPhoneNumber(const string& firstName, const string& lastName) const {
    BST_Node * currNode = findPerson(firstName, lastName).first;

    if (currNode) {
        return currNode->m_person.phoneNumber;
    } else {
        // It wasn't found
        throw out_of_range("No person with the given name");
    }
}

void Book::deleteEntry(const string& firstName, const string& lastName) {
    auto entries = findPerson(firstName, lastName);
    if (entries.first == nullptr) {
        // Person doesn't exist
        return;
    }

    bool isLeftChild =
        entries.second != nullptr && entries.first == entries.second->left;

    if (entries.first->left == nullptr) {
        if (entries.first->right == nullptr) {
            delete entries.first;
            entries.first = nullptr;
        } else {
            delete entries.first;
            entries.first = entries.first->right;
        }
    } else if (entries.first->right == nullptr) {
        delete entries.first;
        entries.first = entries.first->left;
    } else {
        BST_Node * & nodeToDelete = entries.first;
        BST_Node * previousNode = nodeToDelete;
        BST_Node * currentNode = nodeToDelete->left;

        while (true) {
            if (currentNode->right) {
                previousNode = currentNode;
                currentNode = currentNode->right;
            } else {
                swap(nodeToDelete->m_person, currentNode->m_person);
                delete currentNode;
                previousNode->right = nullptr;
                break;
            }
        }
    }

    if (isLeftChild) {
        entries.second->left = entries.first;
    } else if (entries.second) {
        entries.second->right = entries.first;
    }
}
