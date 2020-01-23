#include "Ticket.h"

int Ticket::lastId = 0;

Ticket::Ticket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department)
        : id(++lastId), date(date), creator(creator), department(department) {}

int Ticket::getId() const {
    return id;
}

const std::shared_ptr<Employee> &Ticket::getCreator() const {
    return creator;
}

const std::string &Ticket::getDepartment() const {
    return department;
}

const std::shared_ptr<Employee> &Ticket::getFixedBy() const {
    return m_fixedBy;
}

const std::string &Ticket::getFix() const {
    return m_fix;
}

void Ticket::solve(const std::shared_ptr<Employee> &fixedBy, const std::string &fix) {
    m_fixedBy = fixedBy;
    m_fix = fix;
}

std::string Ticket::toString() const {
    return "Ticket " + std::to_string(getId());
}
