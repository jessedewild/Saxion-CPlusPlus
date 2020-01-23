#include "ServiceDeskEmployee.h"

ServiceDeskEmployee::ServiceDeskEmployee(const std::string &username, const std::string &password,
                                         const std::string &expertise)
        : Employee(username, password, "Helpdesk"), expertise(expertise) {}

const std::string &ServiceDeskEmployee::getExpertise() const {
    return expertise;
}

std::string ServiceDeskEmployee::toString() const {
    return getUsername() + " (" + getDepartment() + ", " + getExpertise() + ")";
}