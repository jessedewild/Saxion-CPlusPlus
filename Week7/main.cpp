#include <iostream>
#include <memory>
#include <fstream>
#include "Administration.h"
#include "ServiceDeskEmployee.h"
#include "SoftwareTicket.h"
#include "HardwareTicket.h"

std::vector<std::shared_ptr<Employee>> readEmployeesFromFile(const std::string &filePath) {
    std::vector<std::shared_ptr<Employee>> employees;

    std::ifstream input(filePath);
    while (true) {
        std::string username;
        std::string password;
        std::string department;

        input >> username;
        if (input.eof())
            break;
        if (input.fail())
            throw std::runtime_error("Fail username: Failed to parse file");

        input >> password;
        if (input.fail())
            throw std::runtime_error("Fail password: Failed to parse file");

        input >> department;
        if (input.fail())
            throw std::runtime_error("Fail department: Failed to parse file");

        employees.push_back(std::make_shared<Employee>(username, password, department));
    }

    return employees;
}

int main() {
    // Instance of the helpdesk admin class
    Administration admin;

    // Reading the (normal) employees from the employees.txt file
    // Columns in the text file are: username password departement
    std::vector<std::shared_ptr<Employee>> employees = readEmployeesFromFile("../Week7/assets/input.txt");
    for (const std::shared_ptr<Employee> &employee : employees) {
        admin.addEmployee(employee);
    }

    // Added the following helpdesk employees (They are all working on the helpdesk department)
    // username: gerralt, password: catsarecool, expertise: Mice
    std::shared_ptr<ServiceDeskEmployee> gerralt =
            std::make_shared<ServiceDeskEmployee>("gerralt", "catsarecool", "Mice");

    admin.addEmployee(gerralt);

    // Print all employees
    admin.printEmployees();

    // Added the following tickets. Start with id 1
    // // A software ticket with date: 15-01-2018, creator: ruud, "Excel can't calculate the number of days in a year",
    // // software: "Office 365"
    admin.addTicket(SoftwareTicket("15-01-2018", admin.getEmployeeByName("ruud"),
                                   "Excel can't calculate the number of days in a year", "Office 265"));

    // // A hardware ticket with date: 16-01-2018, creator: jeroen, "My mouse doesn't work!", hardwareCode: 5
    admin.addTicket(HardwareTicket("16-01-2018", admin.getEmployeeByName("jeroen"),
                                   "My mouse doesn't work!", 5));

    // // A software ticket with date: 17-01-2018, creator: ruud, "MacOS won't boot on my system", software: "MacOS X"
    admin.addTicket(SoftwareTicket("17-01-2018", admin.getEmployeeByName("ruud"),
                                   "MacOS won't boot on my system", "MacOS X"));

    admin.printTickets();

    // Solved ticket 2 and 3 (The last two)
    // // Ticket 2, solver: gerralt, message: "Try putting it into the USB port instead of the HDMI port."
    admin.solveTicket(2, "gerralt", "Try putting it into the USB port instead of the HDMI port.");

    // // Ticket 3, solver: gerralt, message: "Please replace your Dell laptop with a real system"
    admin.solveTicket(3, "gerralt", "Please replace your Dell laptop with a real system");

    // Print the tickets
    admin.printTickets();

    return 0; // TODO: make sure all allocated memory gets freed at the end of this function
}
