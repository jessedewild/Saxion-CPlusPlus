#ifndef SAXION_CPLUSPLUS_EMPLOYEE_H
#define SAXION_CPLUSPLUS_EMPLOYEE_H


#include <string>

class Employee {
private:
    std::string username;
    std::string password;
    std::string department;
public:
    Employee(const std::string &username, const std::string &password, const std::string &department);

    const std::string &getUsername() const;

    const std::string &getDepartment() const;
};


#endif //SAXION_CPLUSPLUS_EMPLOYEE_H
