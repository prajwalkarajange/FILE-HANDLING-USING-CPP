#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream outFile(filename, ios::out);  // Open file in write mode

    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    string data;
    cout << "Enter data to write to file (end with 'exit'):" << endl;
    
    // Writing data to the file
    while (true) {
        getline(cin, data);
        if (data == "exit") {
            break;
        }
        outFile << data << endl;
    }

    outFile.close();
    cout << "Data written to file successfully!" << endl;
}

void readFromFile(const string& filename) {
    ifstream inFile(filename, ios::in);  // Open file in read mode

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    cout << "Reading data from file:" << endl;
    
    // Reading and displaying data from the file
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void appendToFile(const string& filename) {
    ofstream outFile(filename, ios::app);  // Open file in append mode

    if (!outFile) {
        cout << "Error opening file for appending!" << endl;
        return;
    }

    string data;
    cout << "Enter data to append to file (end with 'exit'):" << endl;
    
    // Appending data to the file
    while (true) {
        getline(cin, data);
        if (data == "exit") {
            break;
        }
        outFile << data << endl;
    }

    outFile.close();
    cout << "Data appended to file successfully!" << endl;
}

int main() {
    string filename = "data.txt";
    int choice;

    cout << "File Handling Program" << endl;
    cout << "1. Write data to file" << endl;
    cout << "2. Read data from file" << endl;
    cout << "3. Append data to file" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // To discard the newline left by cin

    switch (choice) {
        case 1:
            writeToFile(filename);
            break;
        case 2:
            readFromFile(filename);
            break;
        case 3:
            appendToFile(filename);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
