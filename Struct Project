//  Description: This program prompts the user to input quarterly sales for each company's divison. The total sales, and average quarterly sales of each division will be calculated and the data will be printed. (The numbers for quarterly, total, and average quarterly sales will be stored in a structure)

#include <iostream>
#include <iomanip>
using namespace std;

// Create a structure that holds the different numbers for the sales as members of the structure
struct DivisionNumbers {
    string division_name;
    double q_sales[4]; // Stores the quarter sales data in an array rather than 4 separate members
    double total_sales;
    double average_sales;
};
/* Returning a struct is not at all required here, better to use void */
// Create a function that returns a structure of inputted data
DivisionNumbers sales_numbers(DivisionNumbers &);
// Create a function that will print the results for each division
void sales_results(DivisionNumbers);

int main() {
    // Declare variables of the structure denoting the company's division
    DivisionNumbers east { "Division East"}, west { "Division West"}, north { "Division North" }, south { "Division South" };
    // Call the function which that will prompt the user and collect each division's data
    sales_numbers(east);
    sales_numbers(west);
    sales_numbers(north);
    sales_numbers(south);
    cout << endl;
    // Output the numbers for each division
    sales_results(east);
    sales_results(west);
    sales_results(north);
    sales_results(south);
    
    return 0;
}

DivisionNumbers sales_numbers (DivisionNumbers &d) {
    // Initialze the value of total sales to zero
    d.total_sales = 0.0;
    // Prompt the user to enter the numbers for the division's sales
    cout << "Enter the quarterly sales numbers for " << d.division_name << endl;
    // Create a for loop that will allow the user to enter sales numbers into 4 (quartley) different elements of sales array
    for (int quarter = 0; quarter < 4; quarter++) {
        cout << "\tQuarter " << (quarter + 1) << ": ";
        cin >> d.q_sales[quarter];
        // Input validation: If a user entered a negative sale, then prompt the user to enter it again
        if (d.q_sales[quarter] < 0) {
            cout << "Enter a valid sales figure for the quarter: ";
            cin >> d.q_sales[quarter];
        }
        // Use assignment operator to add to the total sales while looping through the quarterly sales
        d.total_sales += d.q_sales[quarter];
    }
    // Calculate the average of the quarterly sales at the end of the loop
    d.average_sales = d.total_sales / 4;
    
    // Return the structure variable that contains all the data
    return d;
}

void sales_results (DivisionNumbers d) {
    // Print the results of the divison's sales for each quarter and the total, average results
    cout << "Here are the figures for " << d.division_name << ".\n";
        
    cout << fixed << showpoint << setprecision(2); // Set to 2 decimal places to show dollar value
        // ...for each quarter
    for (int quarter = 0; quarter < 4; quarter++) {
        cout << "\tSales for quarter " << (quarter + 1) << " are $" << d.q_sales[quarter] << endl;
    }
        // ...the total and the average
    cout << "The total sales are $" << d.total_sales << endl;
    cout << "The average quarterly sales are $" << d.average_sales << endl << endl;
}
