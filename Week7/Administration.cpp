#include <iostream>
#include "Administration.h"

const std::vector<std::shared_ptr<Employee>> &Administration::getEmployees() const {
    return employees;
}

std::shared_ptr<Employee> Administration::getEmployeeByName(const std::string &name) {
    for (std::shared_ptr<Employee> employee : employees) {
        if (employee->getUsername() == name) {
            return employee;
        }
    }
    return nullptr;
}

void Administration::addEmployee(const std::shared_ptr<Employee> &employee) {
    employees.push_back(employee);
}

void Administration::printEmployees() {
    std::cout << "Employees:" << std::endl;
    for (const std::shared_ptr<Employee> &employee : getEmployees()) {
        std::cout << employee->toString() << std::endl;
    }
}

const std::vector<Ticket> &Administration::getTickets() const {
    return tickets;
}

Ticket Administration::getTicketById(int id) {
    for (Ticket ticket : tickets) {
        if (ticket.getId() == id) {
            return ticket;
        }
    }
}

void Administration::addTicket(const Ticket &ticket) {
    tickets.push_back(ticket);
}

void Administration::printTickets() {
    std::cout << "Tickets:" << std::endl;
    for (const Ticket &ticket : getTickets()) {
        std::cout << ticket.toString() << std::endl;
    }
}

void Administration::solveTicket(int id, const std::string &fixedBy, const std::string &fix) {
    getTicketById(id).solve(getEmployeeByName(fixedBy), fix);
}
