#include "Sender.h"


Sender::Sender(float p_error, Package *package)
{
	// Initialize variables
	this->p_error = p_error;
	this->package = package; // NOTE: this->package is a POINTER
	this->hasSent = false;
}

bool Sender::SendPackage()
{
	// Generate a random float between 0 and 1
	float random_prob;
	random_prob = ((double) rand() / RAND_MAX);

	/*
		If no error takes place in transmission, return
		Else, return false, indicating a retry on the next timestep
	*/
	return (random_prob <= p_error);
}

void Sender::ReceiveACK()
{
	// Iterate to the next data entry
	package->Next();
}
