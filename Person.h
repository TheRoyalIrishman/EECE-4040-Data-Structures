#pragma once

#include <string>

using namespace std;

class Person {
    public:
        string firstName;
        string lastName;
        string phoneNumber;

        bool operator<(const Person& rhs) const;
};