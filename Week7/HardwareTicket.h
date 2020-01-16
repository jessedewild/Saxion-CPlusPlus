#ifndef SAXION_CPLUSPLUS_HARDWARETICKET_H
#define SAXION_CPLUSPLUS_HARDWARETICKET_H


#include "Ticket.h"

class HardwareTicket : public Ticket {
private:
    int code;

public:
    HardwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department,
                   int code);
};


#endif //SAXION_CPLUSPLUS_HARDWARETICKET_H
