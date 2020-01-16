#include "Ticket.h"

int Ticket::lastId = 0;

Ticket::Ticket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department)
        : id(++lastId), date(date), creator(creator), department(department) {}
