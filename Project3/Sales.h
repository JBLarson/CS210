#ifndef SALES_H
#define SALES_H
#include <map>
#include <string>

/**
 * @file Sales.h
 * @brief Defines the Sales class that executes logic to analyze produce sales.
 */

using namespace std;

/**
 * @class Sales
 * @brief Manages sales data and provides sales reporting functionality.
 *
 * The sales class provides a limited sales analytics suite for processing,
 * documenting, and reporting on produce sales records for Corner Grocer.
 *
 */


class Sales {
public:
	/**
    * @brief Constructor instantiates a new Sales object and initializes data processing.
    *
    * The constructor initializes a new sales object by loading produce sales data from an input file,
    * and preparing the Sales object for data reporting operations.
    */
    Sales();

    /**
    * @brief Concatenates the base file path with a given filename.
    *
    * The method is used to generate a full file path for data loading and saving operations.
    *
    * @param fileName The name of the file to concatenate with the base path.
    * @return string The full file path.
    */
	string concatPath(string fileName);
	
    /**
    * @brief Retrieve the quantity sold for a given produce item.
    *
    * @param itemName The name of the item to query.
    * @return int The quantity of the item sold.
    */
    int getProduceQuantity(string itemName);  // get quantity of item from produceItems map

    /**
    * @brief Prints a textual report of all produce items and their sales quantities.
    *
    * This method outputs a list of all produce items stored along with their individual sales quantities.
    */
    void printProduceSalesReport();  // print all pairs stored in the produceItems map

    /**
    * @brief Displays a histogram representing the sales frequency of each produce item.
    *
    * This method outputs a text-based histogram where each line represents a produce item and
    * each item sold is represented by an asterisk.
    */
    void displayProduceSalesHistogram();  // display a histogram for all pairs stored in the produceItems map

private:

    /**
    * @brief Stores sales data with item names as keys and sales frequencies as values.
    *
    * This map stores sales data in key-value format with item names as keys and sales frequencies as values.
    */
	map<string, int> produceItems;  // declare produceItems map

    /**
    * @brief Read sales data from input file to a map.
    *
    * This private method loads data from a specified input file and stores it in the given map.
    *
    * @param mapName Reference to the map where sales data will be stored.
    * @param inFileName Name of the input file to read.
    */
    void readFileToMap(map<string, int>& mapName, string inFileName);  // read input file to a map

    /**
    * @brief Saves sales data from a map to an output file.
    *
    * This private method writes data stored in a given map to a specified output file.
    *
    * @param mapName Reference to the map that contains the data that will be saved.
    * @param outFileName Name of the output file where data should be written. 
    */
    void saveMapToFile(const map<string, int>& mapName, string outFileName);  // save a map to an output file

};
#endif