//
//  ProductionWorker.hpp
//  CH15Assignment
//
//  Created by Mazin Haider on 11/12/23.
//

#ifndef ProductionWorker_hpp
#define ProductionWorker_hpp

#include <stdio.h>
#include "Employee.hpp"
#include <string>
using namespace std;

// Create the ProductionWorker class which will publicly inherit of the Worker class
class ProductionWorker : public Employee {
// Declare the member variables of this class private
private:
    int shift;
    double hourlyPayRate;
public:
    // Create an argument constructor which initialized the inheriting class's member variables
    ProductionWorker(string name, int number, string date, int shiftNum, double payRate) : Employee(name, number, date) {
        shift = shiftNum;
        hourlyPayRate = payRate;
    }
    
    // Create the mutator functions
    void setShift(int shiftNum) {
        shift = shiftNum;
    }
    
    void setHourlyPayRate(double payRate) {
        hourlyPayRate = payRate;
    }
    
    // Create the accessor functions
    int getShiftNumber()
    { return shift; }
    
    double getHourlyPayRate()
    { return hourlyPayRate; }
};

#endif /* ProductionWorker_hpp */
