#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <limits>
#include <string>

#include "Sales.h"

using namespace std;

// void function to display the initial GUI
void displayGUI() {
	cout << setfill('-') << setw(63) << "" << endl;
	cout << setfill('-') << setw(18) << "";
	cout << "  Corner Grocer Analytics  ";
	cout << setfill('-') << setw(18) << "" << endl;
	cout << setfill('-') << setw(63) << "" << "\n" << endl;
	cout << "Welcome to the Corner Grocer Analytics Program." << endl;
	cout << "Select one of the following options to analyze produce sales metrics." << endl;
}

// void function to display the menu of options for the program
void displayMenu() {
	cout << "\n" << setfill('-') << setw(14) << "";
	cout << " Menu Options ";
	cout << setfill('-') << setw(14) << "" << endl;
	cout << "1 - Find Sales Frequency for an Item" << endl;
	cout << "2 - Print Produce Sales Report" << endl;
	cout << "3 - Display Produce Sales Histogram" << endl;
	cout << "4 - Quit Program" << endl;
	cout << setfill('-') << setw(42) << "" << "\n" << endl;
}


int main() {
	int menuChoice = 0;
	string searchItem;

	displayGUI();  // display the initial GUI once

	Sales produceSales;  // instantiate the Inventory class

	while (menuChoice != 4) {
		displayMenu();  // display the menu of options with each loop iteration

		cin >> menuChoice;  // read menu choice from standard input

		if (cin.fail()) {

			cout << "Input must be in numeric form.\n";

			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue;

		}


		switch (menuChoice) {  // handle program flow with a switch statement
		case 1:
			// search functionality with formatted header
			cout << "\n" << setfill('-') << setw(32) << "" << endl;
			cout << setw(5) << "" << " Produce Sales Search " << setw(5) << "" << endl;
			cout << setw(32) << "" << "\n" << endl;

			cout << "Enter item to search" << endl;
			cin >> searchItem;

			// try block to attempt to look up searchItem in the produceSales map
			try {
				cout << "\nCorner Grocer Sold " << produceSales.getProduceQuantity(searchItem) << " units of " << searchItem << endl;
			}
			// if searched item does not exist in the map catch out_of_range exception, display message, and return to menu
			catch (out_of_range& excpt) {
				cout << "Item does not exist in Corner Grocer Sales Records: " << excpt.what() << endl;
				continue;
			}
			break;

		case 2:  // call member method to display the sales report
			produceSales.printProduceSalesReport();
			break;

		case 3:  // call member method to display the sales report in histogram form
			produceSales.displayProduceSalesHistogram();
			break;
		case 4:
			// display exit message
			cout << "\n" << setfill('-') << setw(50) << "" << endl;
			cout << setw(9) << "";
			cout << " Exited Corner Grocer Analytics ";
			cout << setw(9) << "" << endl;
			cout << setfill('-') << setw(50) << "" << endl;
			break;
		default:
			// display instructions and request valid input
			cout << "Invalid input. Select one of the menu options (1-4)." << endl;
			break;
		}
	}
	return 0;
}