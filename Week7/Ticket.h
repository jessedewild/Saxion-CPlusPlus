#ifndef SAXION_CPLUSPLUS_TICKET_H
#define SAXION_CPLUSPLUS_TICKET_H


#include <memory>
#include "Employee.h"

class Ticket {
private:
    static int lastId;
    int id;

    std::string date;
    std::shared_ptr<Employee> creator;
    std::string department;

    std::shared_ptr<Employee> fixedBy;
    std::string fix;

public:
    Ticket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department);
};


#endif //SAXION_CPLUSPLUS_TICKET_H
