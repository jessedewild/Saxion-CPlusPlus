#include "Administration.h"

void Administration::addEmployee(const std::shared_ptr<Employee> &employee) {
    employees.push_back(employee);
}
