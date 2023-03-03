#pragma once

#include "Person.h"

#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct BST_Node {
    Person m_person;
    struct BST_Node * left;
    struct BST_Node * right;

    BST_Node(Person newPerson) {
        this->m_person;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~BST_Node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class Book {
    public:
        BST_Node * logbook;

        Book() {
            logbook = nullptr;
        }

        ~Book() {
            if (logbook)
                delete logbook;
        }

        void addEntry(Person newPerson); // already implemented
        void inorderTraversal(BST_Node * node) const; // already implemented - not complete though
        void deleteEntry(const string& firstName, const string& lastName); // partially impleneted
        string findPhoneNumber(const string& firstName, const string& lastName) const; // already implemented
        void changePhoneNumber(
            const string& firstName,
            const string& lastName,
            string newPhoneNumber
        );                       // already implemented
        void displayPhoneBook(); // needs to be implemented
        void quitAndSavePhoneBook(); // needs to be implemented
    private:
        // First element is the person in question, second element is the parent element
        pair<BST_Node *, BST_Node *> findPerson(const string& firstName, const string& lastName) const;
};