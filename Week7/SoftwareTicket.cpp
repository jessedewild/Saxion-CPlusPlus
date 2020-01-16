#include "SoftwareTicket.h"

SoftwareTicket::SoftwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator,
                               const std::string &department, const std::string &software)
        : Ticket(date, creator, department), software(software) {}
