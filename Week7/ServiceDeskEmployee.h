#ifndef SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H
#define SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H


#include <string>
#include "Employee.h"

class ServiceDeskEmployee : public Employee {
    std::string expertise;

public:
    ServiceDeskEmployee(const std::string &username, const std::string &password, const std::string &expertise);
};


#endif //SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H
