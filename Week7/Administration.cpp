#include <iostream>
#include "Administration.h"

const std::vector<std::shared_ptr<Employee>> &Administration::getEmployees() const {
    return employees;
}


void Administration::addEmployee(const std::shared_ptr<Employee> &employee) {
    employees.push_back(employee);
}

void Administration::printEmployees() {
    std::cout << "Employees:" << std::endl;
    for (const std::shared_ptr<Employee> &employee : getEmployees()) {
        std::cout << "  " << employee->getUsername() << " (" << employee->getDepartment() << ")" << std::endl;
    }
}