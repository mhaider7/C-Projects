#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>
using namespace std;

// Create a class named employee
class Employee {
// Declare the member variables as private, they can't be accessed "directly" outside of the class
private:
    string employeeName;
    int employeeNumber;
    string hireDate;
public:
    // Create the argument constructor
    Employee(string name, int number, string date) {
        employeeName = name;
        employeeNumber = number;
        hireDate = date;
    }
    
    // Create the mutator functions
    void setEmployeeName(string name) {
        employeeName = name;
    }
    
    void setEmployeeNumber(int number) {
        employeeNumber = number;
    }
    
    void setHireDate(int date) {
        hireDate = date;
    }
    
    // Create the accessor functions
    string getEmployeeName()
    { return employeeName; }
    
    int getEmployeeNumber()
    { return employeeNumber; }
    
    string getHireDate()
    { return hireDate; }
};

#endif /* Employee_hpp */
