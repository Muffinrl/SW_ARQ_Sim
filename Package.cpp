#include "Package.h"

#include <fstream>

Package::Package(std::string loc) {

	// Initialize variables
	this->fileLocation = loc;
	frame = 0;
	len = 0;

	// Loads the data from the file into a local array
	LoadData();

}

void Package::LoadData() {
	std::fstream file(fileLocation, std::ios_base::in);

	// Read file size (amount of rows)
	int input;

	// Store all elements in data
	int i = 0;

	while (file >> input) {
		data.push_back(input);
		len++;
	}
}

int Package::getCurrentData() {
	return data[frame];
}

int Package::getCurrentFrame() {
	return frame;
}

int Package::getPackageSize() {
	return len;
}

void Package::Next() {
	frame++;
}