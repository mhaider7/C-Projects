/* This program prints out information of 3 emplyees which entails their name, their id number, their job description, and their job position in a table fromat. This is done by creating a class named "Employee" that holds information about an employee's name, id number, depratment, and position. 3 constructors are created in the class which are each used in the program. The employee information is then outputted using it's class's accessors in table format
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Create Employee class
class Employee 
{
private:
    string name;            // Employees name
    int idNumber;           // Employees id number
    string department;      // Employees department (where employee works)
    string position;        // job title
    
public:
    // Constructors
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();
    // Mutators (defined in-line)
    // Create mutators that will mutate the attributes of an object
    void setName(string n) {
        name = n;
    }
    void setidNumber(int id) {
        idNumber = id;
    }
    void setDepartment(string d) {
        department = d;
    }
    void setPosition(string p) {
        position = p;
    }
    // Accessors (defined in-line)
    // Create accessors that will return the data of the object
    string getName() {
        return name;
    }
    int getidNumber() {
        return idNumber;
    }
    string getDepartment() {
        return department;
    }
    string getPosition() {
        return position;
    }
};
// Define the constructors
// Constructor that accepts arguments for each member variable
Employee::Employee(string n, int id, string d, string p) {
    name = n;
    idNumber = id;
    department = d;
    position = p;
}
// Constructor that accepts 2 arguments
Employee::Employee(string n, int id) {
    name = n;
    idNumber = id;
    // Initialize the rest to empty strings
    department = "";
    position = "";
}
// Default constructor
Employee::Employee() {
    // Initialize the variables to empty strings or a 0 integer
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

// Create a function that will pass an object and display the objects
// You don't need pass by reference since you aren't changing the data in the object
void displayEmployee(Employee);

int main() {
    // Fill the objects of Employee class with data for table
    // Create 3 intances of the Employee class for the 3 employees
    Employee employee1("Susan Meyers", 47899, "Accounting", "Vice President");       // Calls the first constructor
    Employee employee2("Mark Jones", 39119);                                         // Calls the second constructor
    Employee employee3;                                                              // Calls the thrid (default) constructor
    
    // Fill in the rest of the data through the class's mutator functions
    // For employee 2
    employee2.setDepartment("IT");
    employee2.setPosition("Programmer");
    // For employee 3
    employee3.setName("Joy Rogers");
    employee3.setidNumber(81774);
    employee3.setDepartment("Manufacturing");
    employee3.setPosition("Engineer");
    
    // Create the header for the table
    cout << setw(8) << "Name" << setw(17) << "ID Number" << setw(18) << "Department" << setw(16) << "Position" << endl;
    cout << "______________________________________________________________\n";
    // Call the function passing each object as an argument which will display each employee
    displayEmployee(employee1);
    displayEmployee(employee2);
    displayEmployee(employee3);
    
    return 0;
}

void displayEmployee(Employee employee) {
    // Display the name, id number, department, position of the object passed in
    // Format the spacing to fit the table
    cout << setw(12) << employee.getName() << setw(11) << employee.getidNumber() << setw(21) << employee.getDepartment() << setw(18) << employee.getPosition() << endl << endl;
}
