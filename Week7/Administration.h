#ifndef SAXION_CPLUSPLUS_ADMINISTRATION_H
#define SAXION_CPLUSPLUS_ADMINISTRATION_H


#include <vector>
#include <memory>
#include "Employee.h"
#include "Ticket.h"

class Administration {
private:
    std::vector<std::shared_ptr<Employee>> employees;
    std::vector<Ticket> tickets;

public:
    const std::vector<std::shared_ptr<Employee>> &getEmployees() const;

    std::shared_ptr<Employee> getEmployeeByName(const std::string& name);

    void addEmployee(const std::shared_ptr<Employee> &employee);

    void printEmployees();

    const std::vector<Ticket> &getTickets() const;

    Ticket getTicketById(int id);

    void addTicket(const Ticket &ticket);

    void printTickets();

    void solveTicket(int id, const std::string &fixedBy, const std::string &fix);
};


#endif //SAXION_CPLUSPLUS_ADMINISTRATION_H
