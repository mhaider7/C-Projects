/* This program creates a class called Employee and declares generic members which can define any employee (their name, number, and hire date). Then, a class ProductionWorker is created which is a more specific form of an employee. ProductionWorker has its own members and inherits the members of the Employee class. The main function shows the ProductionWorker class on display after creating an object of the class and initializing its member variable.
*/

#include <iostream>
#include <iomanip>
#include <string>
// Only the ProductionWorker class is imported since it is the only class instansiated from, and inherits from
#include "ProductionWorker.hpp"
using namespace std;

int main() {
    // Create an object of class ProductionWorker
    ProductionWorker productionWorker("Mazin Haider", 1234, "11/12/2023", 1, 22.50);
    
    // Displya the data for the productionWorker object
    cout << fixed << setprecision(2); // Format the floating point number to ressemble a currency value
    cout << "Name: " << productionWorker.getEmployeeName() << endl;
    cout << "ID Number: " << productionWorker.getEmployeeNumber() << endl;
    cout << "Hire Date: " << productionWorker.getHireDate() << endl;
    cout << "Shift Number: " << productionWorker.getShiftNumber() << endl;
    cout << "Pay rate: $" << productionWorker.getHourlyPayRate() << " per hour.\n";
    
    return 0;
}
