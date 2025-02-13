#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include "dArray.h"

using namespace std;

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    //Open the file
    ifstream inFile("input.txt");
    if (!inFile.good()) {
        cout << "Error opening file" << endl;
        return -1;
    }

    //Add the numbers to the array
    dArray *numberArray = new dArray();
    string input, item;
    while (getline(inFile, input)) {
        stringstream ss(input);
        while (getline(ss, item, ' ')) {
            numberArray->PushBack(stoi(item));
        }
    }
    inFile.close();

    int menuSelection = 0;
    int menuNumber;
    while (menuSelection != 5) {
        cout << "\nARRAY MENU\n";
        cout << "1. Add Integer to Array" << endl;
        cout << "2. Remove Integer from Array" << endl;
        cout << "3. Find Integer in Array" << endl;
        cout << "4. Print Array" << endl;
        cout << "5. Quit" << endl;
        cout << "Please select an operation: ";
        cin >> menuSelection;

        if (menuSelection == 1) {
            try {
                cout << "Please enter a number: ";
                cin >> menuNumber;
                if (cin.fail()) {
                    clear_input();
                    throw invalid_argument("Invalid Input");
                }
                numberArray->PushBack(menuNumber);
            } catch (exception& ex) {
                cout << "Error while trying to add an integer: " << ex.what() << endl;
            }
        } else if (menuSelection == 2) {
            try {
                cout << "Please enter an index to remove: ";
                cin >> menuNumber;
                if (cin.fail()) {
                    clear_input();
                    throw invalid_argument("Invalid Input");
                }
                numberArray->RemoveInteger(menuNumber);
            } catch (exception& ex) {
                cout << "Error while trying to remove an integer: " << ex.what() << endl;
            }

        } else if (menuSelection == 3) {
            try {
                cout << "Please enter an integer to find: ";
                cin >> menuNumber;
                if (cin.fail()) {
                    clear_input();
                    throw invalid_argument("Invalid Input");
                }
                cout << menuNumber << " is at index " << numberArray->FindInteger(menuNumber) << endl;
            } catch (exception& ex) {
                cout << "Error while trying to find an integer: " << ex.what() << endl;
            }
        }
        else if (menuSelection == 4) {
            numberArray->Print();
        }
    }

    return 0;
}
