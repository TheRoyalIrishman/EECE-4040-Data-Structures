#pragma once

#include "Person.h"

#include <iostream>
#include <string>

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
        void inorderTraversal(BST_Node * node); // already implemented
        void deleteEntry(string phoneNumber); // needs to be implemented
        string findPhoneNumber(string fullName); // needs to be implemented
        void changePhoneNumber(string fullName, string oldPhoneNumber); // needs to be implemented
        void displayPhoneBook(); // needs to be implemented
        void quitAndSavePhoneBook(); // needs to be implemented

};