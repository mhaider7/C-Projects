// Description: This program prints out contents of a joke file and a punchline file. A function is called to read in contents of the joke file and displays its contents. Another function is called which reads in the last line fo the punchline file by seeking to the end of the file and backing up to the beginnng of the last line. It them displays the last line.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Create a function which will display the contents of the joke file
void showFile(fstream &);
// Create a function which will display the last line of the punchline file
void showFileLastLine(fstream &);

int main() {
    // Declare fstream objects for the joke file & punchline file
    fstream jokeFile, punchlineFile;
    
    // Open the joke file
    jokeFile.open("joke.txt", ios::in);
    // Error check whether the file was able to open or not
    if (!jokeFile.fail()) {
        // Call the function which will display the joke.txt contents
        showFile(jokeFile);
    } else {
        // Exit the program if the first file could not open
        cout << "The file could not open.\n";
        return 0;
    }
    
    // Open the punchline file
    punchlineFile.open("punchline.txt", ios::in);
    // Call the function which will print out the last line of the punchline file
    showFileLastLine(punchlineFile);
    cout << endl;
    
    return 0;
}

void showFile(fstream &jFile) {
    // Create a string object which will hold a line of the joke file
    string line;
    // Read in the first line of the file
    getline(jFile, line);
    // While reading in from the file doesn't fail, print the lines from the file
    while (!jFile.fail()) {
        cout << line << endl;
        getline(jFile, line);
    }
    jFile.close();
}

void showFileLastLine(fstream &plFile) {
    // Declare the variable which will hold the byte number to be sought
    long byteNumber = -36;
    // Declare the variable which will hold a character from the file
    char ch;
    // Seek to the position where the last line starts and read in the first character of the last sentence
    plFile.seekg(byteNumber, ios::end);
    plFile.get(ch);
    // While a character is able to be read from the file
    while (!plFile.fail()) {
        // Print out the character and iterate the byteNumber count to read in the next character
        cout << ch;
        byteNumber++;
        plFile.seekg(byteNumber, ios::end);
        plFile.get(ch);
    }
    plFile.close();
}

// Open two files
    // Open the file containing the joke
    // Open the file containing the punchline as the last line

// Create the functions
    // Function 1 should read in every line from the joke and print it out onto the console
        // Use !file.eof and remember to read in the line before the while loop
    // Function 2 should skip the the end of the file using the seekg and rerieving each character from the last line. Test for if the last line length changes

// Call the functions in main which will print the joke.txt and the last line of the punchline.txt onto the console
