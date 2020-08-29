// person.hpp
#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>

namespace person {

class Person {
public:
    explicit Person(const std::string &name);
    std::string sayHello() const;
private:
    std::string m_name;
};

} // #end of person

#endif // PERSON_HPP_