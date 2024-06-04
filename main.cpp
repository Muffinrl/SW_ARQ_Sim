#include <iostream>
#include <string>
#include "main.h"

Simulation *sim;

std::string file;
float p_send;
float p_rec;

int main()
{
	std::cout << "Enter the filename: ";
	std::getline(std::cin, file);

	std::cout << "p_send: ";
	std::cin >> p_send;

	std::cout << "p_rec: ";
	std::cin >> p_rec;

	sim = new Simulation(file, p_send, p_rec);

	sim->run();

	std::cin.get();

	return 0;
}


