#include "Receiver.h"

Receiver::Receiver(float p_error)
{
	// Initialize variables
	this->p_error = p_error;
	this->receivedData = 0;
	this->n_R = 0;
}

void Receiver::ReceiveData(int data, int frame)
{
	// Validate the received frame as new
	if (frame % 2 == n_R) {
		receivedData = data;

		// Toggle the n_R value from 0 to 1 or vice-versa
		n_R = (n_R + 1) % 2;
	}
}

bool Receiver::SendACK()
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

int Receiver::getNR() {
	return n_R;
}

