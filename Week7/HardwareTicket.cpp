#include <iostream>
#include "HardwareTicket.h"

HardwareTicket::HardwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator,
                               const std::string &department, int code)
        : Ticket(date, creator, department), code(code) {}

int HardwareTicket::getCode() const {
    return code;
}

std::string HardwareTicket::toString() const {
    if (getFixedBy() == nullptr || getFix().empty()) {
        return "Ticket " + std::to_string(getId()) + " (Hardwareticket, computerId: " +
               std::to_string(getCode()) + "):" + "\n  " +
               "Status: Open";
    } else {
        return "Ticket " + std::to_string(getId()) + " (Hardwareticket, computerId: " +
               std::to_string(getCode()) + "):" + "\n  " +
               "Status: Solved" + "\n  " +
               getFixedBy()->toString() + ": " + getFix();
    }
}
