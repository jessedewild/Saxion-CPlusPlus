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

    void addEmployee(const std::shared_ptr<Employee> &employee);

    void printEmployees();
};


#endif //SAXION_CPLUSPLUS_ADMINISTRATION_H
