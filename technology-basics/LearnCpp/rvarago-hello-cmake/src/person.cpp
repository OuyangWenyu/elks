// person.cpp
#include "person.hpp"

using person::Person;

Person::Person(const std::string &name) : m_name(name) {}

std::string Person::sayHello() const {
    return m_name + " says hello to you!";
}