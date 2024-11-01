#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Data.h"  
#include "Initial.h"  
#include "Date.h" 
#include "Address.h"  

using namespace std;

class Hotel {
public:
    void DataEntry(vector<Data>& data);
    void readDataFromFile(vector<Data>& data, const string& fileName);
    void printData(const vector<Data>& data) const;
    void modifyData(vector<Data>& data);
    void deleteData(vector<Data>& data);
    void sortData(vector<Data>& data);
    void saveDataToFile(const vector<Data>& data, const string& fileName) const;
    void searchRoom(int roomNumber, const std::vector<Data>& data) const; 
    void displayRooms() const;
};

#endif // HOTEL_H
