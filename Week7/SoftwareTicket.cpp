#include "SoftwareTicket.h"

SoftwareTicket::SoftwareTicket(const std::string &date, const std::shared_ptr<Employee> &creator,
                               const std::string &department, const std::string &software)
        : Ticket(date, creator, department), software(software) {}

const std::string &SoftwareTicket::getSoftware() const {
    return software;
}

std::string SoftwareTicket::toString() const {
    if (getFix().empty()) {
        return "Ticket " + std::to_string(getId()) + " (Hardwareticket, Software: " +
               getSoftware() + "):" + "\n  " +
               "Status: Open";
    } else {
        return "Ticket " + std::to_string(getId()) + " (Hardwareticket, Software: " +
               getSoftware() + "):" + "\n  " +
               "Status: Solved" + "\n  " +
               getFixedBy()->toString() + ": " + getFix();
    }
}
