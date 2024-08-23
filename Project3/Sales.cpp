#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

#include "Sales.h"

using namespace std;

// default constructor for the Inventory class
Sales::Sales() {

	readFileToMap(produceItems, "CS210_Project_Three_Input_File.txt");  // populate produceItems map from input file
	saveMapToFile(produceItems, "frequency.dat");  // save produceItems map to file
}

// function to concatenate absolute path with file name
string Sales::concatPath(string fileName) {
	return "\\\\apporto.com\\dfs\\SNHU\\Users\\jeroldlarson_snhu\\Documents\\Project3\\" + fileName;
}


// read values from inFileName and save them to the map that is passed by reference
void Sales::readFileToMap(map<string, int>& mapName, string inFileName) {
	ifstream inFS;  // input file stream
	string inFilePath = concatPath(inFileName);  // absolute input file path
	inFS.open(inFilePath);  // open input file

	// verify input file is open - exit program if it is not
	if (!inFS.is_open()) {
		cout << "Failed to open " << inFilePath << endl;
		return;
	}

	string currentItem;  // declare string variable for the currentItem
	while (inFS >> currentItem) {  // iterate through the input file while there is an input file stream
		mapName[currentItem] += 1; // add currentItem to map if it does not exist, increment frequency of currentItem if it does exist
	}
	
	// close input file stream if it is open
	if (inFS.is_open()) {
		inFS.close();
	}

}


// save map to file - map is passed by reference with the const keyword
void Sales::saveMapToFile(const map<string, int>& mapName, string outFileName) {
	ofstream outFS;  // declare output filestream
	outFS.open(concatPath(outFileName));  // open output file

	// verify output file is open - exit program if it is not
	if (!outFS.is_open()) {
		cout << "Failed to open " << outFileName << endl;
		return;
	}

	for (const auto& pair : mapName) {  // iterate over the key-value pairs in the mapName container
		outFS << pair.first << " " << pair.second << endl;
	}


	// close output file stream if it is open
	if (outFS.is_open()) {
		outFS.close();
	}

}


// returns the quantity of an item in the produceItems map
int Sales::getProduceQuantity(string itemName) {
	return produceItems.at(itemName);
}


// print all pairs stored in the produceItems map
void Sales::printProduceSalesReport() {
	cout << "\n" << setfill('-') << setw(32) << "" << endl;
	cout << setw(5) << "" << " Produce Sales Report " << setw(5) << "" << endl;
	cout << setfill('-') << setw(32) << "" << "\n" << endl;

	for (const auto& pair : produceItems) {  // iterate over the key-value pairs in the produceItems container
		cout << pair.first << " " << pair.second << endl;
	}
}

// display a histogram for data stored by all pairs stored in the produceItems map
void Sales::displayProduceSalesHistogram() {
	cout << "\n" << setfill('-') << setw(32) << "" << endl;
	cout << setw(3) << "" << " Produce Sales Histogram " << setw(3) << "" << endl;
	cout << setfill('-') << setw(32) << "" << "\n" << endl;

	for (const auto& pair : produceItems) {  // iterate over the key-value pairs in the produceItems container
		cout << pair.first << " ";
		for (int i = 1; i <= pair.second; ++i) {
			cout << '*';
		}
		cout << endl;
	}
}

