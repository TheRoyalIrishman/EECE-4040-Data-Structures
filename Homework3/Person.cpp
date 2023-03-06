#include "Person.h"

bool Person::operator<(const Person& rhs) const {
    if (this->lastName == rhs.lastName) {
        return this->firstName < rhs.firstName;
    }
    return this->lastName < rhs.lastName;
}
