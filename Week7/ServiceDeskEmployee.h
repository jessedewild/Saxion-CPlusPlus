#ifndef SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H
#define SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H


#include <string>
#include "Employee.h"

class ServiceDeskEmployee : public Employee {
    std::string expertise;

public:
    ServiceDeskEmployee(const std::string &username, const std::string &password, const std::string &expertise);

    const std::string &getExpertise() const;

    std::string toString() const override;
};


#endif //SAXION_CPLUSPLUS_SERVICEDESKEMPLOYEE_H
