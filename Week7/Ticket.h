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

    std::shared_ptr<Employee> m_fixedBy;
    std::string m_fix;

public:
    Ticket(const std::string &date, const std::shared_ptr<Employee> &creator, const std::string &department);

    int getId() const;

    const std::shared_ptr<Employee> &getCreator() const;

    const std::string &getDepartment() const;

    const std::shared_ptr<Employee> &getFixedBy() const;

    const std::string &getFix() const;

    void solve(const std::shared_ptr<Employee> &fixedBy, const std::string &fix);

    virtual std::string toString() const;
};


#endif //SAXION_CPLUSPLUS_TICKET_H
