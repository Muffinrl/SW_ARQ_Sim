#pragma once

#include "Package.h"
#include "Receiver.h"

class Sender
{
	public:
		// Constructor
		Sender(float p_error, Package *package);

		// Simulates a package transmission, has a p_error probability to fail
		bool SendPackage();

		// ReceiveACK 
		void ReceiveACK();

		// Indicates whether or not the sender has sent a package.
		bool hasSent;

	private:
		// Probability of failure during any given data transmission epoch
		float p_error;

		// POINTER to the package which contains data to be sent
		Package *package;

};

