#pragma once

#include "Person.h"

#include <iostream>

using namespace std;

struct BST_Node {
    Person m_person;
    struct BST_Node * left;
    struct BST_Node * right;
};

class Book {
    BST_Node logbook;
};