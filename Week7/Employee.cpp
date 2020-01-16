#include "Employee.h"

Employee::Employee(const std::string &username, const std::string &password, const std::string &department) : username(
        username), password(password), department(department) {}

const std::string &Employee::getUsername() const {
    return username;
}

const std::string &Employee::getDepartment() const {
    return department;
}
