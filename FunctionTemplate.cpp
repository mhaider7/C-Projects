/* This program contains a function template that accepts an argument and returns its absolute value. The program contains, in it's main function, code that tests the function template.
 */

#include <iostream>
#include <string>
using namespace std;

// Create the function template header
template <typename T>
T absValue(T number) {
    // if the number is positive, return the argument that was passed in. If negative, return the postive version of it.
    if (number >= 0)
        return number;
    else
        return -(number);
}


int main() {
    // Declare the variables for ints and doubles
    int intValue1 = 25, intValue2 = -30;
    double doubleValue1 = 22.2, doubleValue2 = -34.32;
    
    // Use the function template to return the absolute values of the numbers
    cout << "The absolute value of integer numbers " << intValue1 << " and " << intValue2 << ", are " << absValue(intValue1) << " and " << absValue(intValue2) << endl;
    cout << "The absolute value of floating-point numbers " << doubleValue1 << " and " << doubleValue2 << ", are " << absValue(doubleValue1) << " and " << absValue(doubleValue2) << endl;
    
    return 0;
}
