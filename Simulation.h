#pragma once

#include <iostream>
#include <format>

#include "Package.h"
#include "Sender.h"
#include "Receiver.h"

class Simulation
{
public:
	/* 
		The constructor initialises the various actors in the simulation,
		it grabs the file from the disk to create a Package object and then
		binds this Package object to the Sender object.
	 */
	Simulation(std::string file, float p_send, float p_rec);

	Package *package;
	Sender *sender;
	Receiver *receiver;

	void run();

private:
	/* 
		Time Step
		Normally this would be a frame but the usage of the word "frame" has been
		omitted as its meaning is ambiguous in this context.
	 */
	int time;

	// For the simulation loop
	bool isDone;
};

