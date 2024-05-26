// This program determines includes a function that determines the median of an array using pointers
//  main.cpp
//  Chapter9Challenge


#include <iostream>
using namespace std;

double median(int *, int); // Function prototype that carries a pointer to an integer as an argument

int main() {
    // Variable declaraion
    int number;
    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> number;
    
    int *ptr = new int[number]; // Dynamically allocate array
    
    // Prompt the user to enter the elements into the array
    cout << "Now enter the elements of the array in \"ascending\" order: " << endl;
    for (int count = 0; count < number; count++) {
        cin >> ptr[count]; // Subscript notation with the pointer
    }
    
    cout << "The median of the array is: " << median(ptr, number) << endl; // call the function which returns the median value

    return 0;
}

double median(int *arr, int size) { // "arr" in function parameter points to the address of "values" array
    double med;
    
    if (size % 2 == 0) { // Condition of check if the array has an even number of elements
        med = double(*(arr + (size / 2 - 1)) + *(arr + (size / 2))) / 2; // Pointer notation
    }
    else { // If the array has an odd number of elements
        med = arr[size / 2]; // Subscript notation is used with the pointer, no indirection operator is needed

    }
    return med; // Return the median value
}
