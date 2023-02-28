#pragma once

#include "Person.h"

#include <iostream>

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
};

class Book {
    public:
        BST_Node * logbook;

        Book() {
            logbook = nullptr;
        }

        void addEntry(Person newPerson);
        void inorderTraversal(BST_Node * node);
};