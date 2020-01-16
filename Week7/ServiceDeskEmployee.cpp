#include "ServiceDeskEmployee.h"

ServiceDeskEmployee::ServiceDeskEmployee(const std::string &username, const std::string &password,
                                         const std::string &expertise)
        : Employee(username, password, "Helpdesk"), expertise(expertise) {}
