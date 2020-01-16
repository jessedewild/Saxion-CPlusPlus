#include "HardwareTicket.h"

HardwareTicket::HardwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator,
                               const std::string &department, int code)
        : Ticket(date, creator, department), code(code) {}
