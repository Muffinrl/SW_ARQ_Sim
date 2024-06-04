#pragma once
#include <iostream>
#include <vector>

class Package
{
	public:
		// Package Constructor
		Package(std::string loc); 

		// Get Current Data Method, returns the current data integer to be sent
		int getCurrentData();

		// Returns the frame number 
		int getCurrentFrame();

		// Returns the length of the data file.
		int getPackageSize();

		// Iterate Data to Next, adds +1 to frame
		void Next();
	
	private:
		// Loads data from the file at the given input file location and stores the received data in *data.
		void LoadData();

		std::string fileLocation;

		// All data integers
		std::vector<int> data;

		// Current position in data array
		int frame;

		// Length of data file
		int len;
};

