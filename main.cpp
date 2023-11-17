/******************************************************************************

Austin Kinnear
Chapter 18 Programming Assingment
10/31/23 - 11/02/23

*******************************************************************************/
#include <iostream>
#include "Necklace.h"
using namespace std;

bool isValidMaterial(const string& material) {
    return (material == "turquoise" || material == "coral" || material == "gold" || material == "copper");
}

int main() {
    Necklace necklace;
    bool initialMenu = true; // Flag to control initial menu display

    while (true) {
        if (initialMenu) { //beggining display
            cout << "**MENU (displayed this time, but in the future, I will just type **DISPLAY MENU )" << endl;
            cout << "1. Append" << endl;
            cout << "2. Insert" << endl;
            cout << "3. Delete" << endl;
            cout << "4. Print" << endl;
            cout << "5. Search" << endl;
            cout << "6. Exit" << endl;
            initialMenu = false;
        } else {
            cout << "**DISPLAY MENU" << endl;
        }
        
        int choice;
        cout << "Please choose a menu option: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string material; //I was using cin.ignore to clear the line but it was creating a break in my i/o
                while (true) {
                    cout << "Enter Bead Material: ";
                    getline(cin, material);

                    if (!isValidMaterial(material)) {
                        cout << "Error: " << material << " is not a metal that we carry." << endl;
                    } else {
                        if (necklace.append(material) == 0) {
                            cout << "Thank you - a " << material << " bead has been added to your necklace at position " << necklace.size() - 1 << "." << endl;
                        }
                        break; // Exit the loop when valid material is entered
                    }
                }
                break;
            }
            case 2: {
                string material;
                int position;
                cout << "Enter Bead Material: ";
                getline(cin, material);
                cout << "Enter Insert Position: ";
                cin >> position;
                cin.ignore(); // Ignore newline characters

                if (!isValidMaterial(material)) {
                    cout << "Error: " << material << " is not a metal that we carry." << endl;
                } else if (necklace.insert(position, material) == 0) {
                    cout << "Thank you - a " << material << " bead has been inserted at position " << position << "." << endl;
                } else {
                    cout << "I’m sorry but bead position " << position << " does not exist." << endl;
                }
                break;
            }
            case 3: {
                int position;
                cout << "What bead position do you wish to delete? ";
                cin >> position;

                if (necklace.deleteNode(position) == 0) {
                    cout << "Node (" << position << ") has been deleted from your list." << endl;
                } else {
                    cout << "I’m sorry but bead position " << position << " does not exist." << endl;
                }
                break;
            }
            case 4:
                necklace.display();
                break;
            case 5: {
                string material;
               
                cout << "Enter material to search for: ";
                getline(cin, material);

                int position = necklace.search(material);
                if (position == -1) {
                    cout << "There is no " << material << " bead in your list." << endl;
                } else {
                    cout << "There is a " << material << " bead at position (" << position << ")" << endl;
                }
                break;
            }
            case 6:
                cout << "Bye! I hope that you are liking your bead choices." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
