// This program return the number of words in a string that is entered by the user
//  main.cpp
//  CH10Assignment

#include <iostream>
#include <cctype>
using namespace std;

void input(char [], int); // Function holds the prompts for the user to enter a sentence
int counter(char *); // Functons returns a pointer to the character array and returns and integer

int main() {
    // Variable declaration
    const int size = 100;
    char sentence[size];
            // Call the function that prompts the user
        input(sentence, size);
        // Print the results by calling the counter function
        cout << "The number of words in the string are " << counter(sentence) << "." << endl;
        
    return 0;
}

void input(char str[], int SIZE) {
    cout << "Enter a string: ";
    cin.getline(str, SIZE); // Uses getline to be able to read input w/ any spaces entered into str character array
}

int counter(char *string) { // string is a pointer to the character array
    int word = 0; // Word counter declaration
    
    while (*string != '\0') { // While the c-string hasn't reach the last element(null)
        if (isprint(*string) && !isspace(*string)) { // If the character is a letter/digit and not a space
            word++; // Increment the word couter
            while (!isspace(*string)) { // Skip through all the characters in the word until a space is read
                string++;
            }
        }
        string++; // Increment to the next address after the whitespace
    }
    
    return word; // Return the number of words
}
