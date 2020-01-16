#ifndef SAXION_CPLUSPLUS_SOFTWARETICKET_H
#define SAXION_CPLUSPLUS_SOFTWARETICKET_H


#include <string>
#include "Ticket.h"

class SoftwareTicket : public Ticket {
private:
    std::string software;

public:
    SoftwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department,
                   const std::string &software);
};


#endif //SAXION_CPLUSPLUS_SOFTWARETICKET_H
