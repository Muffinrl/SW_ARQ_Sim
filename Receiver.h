#pragma once

#include "Sender.h"

class Receiver
{
	public:
		// Constructor
		Receiver(float p_error);

		// ReceiveData is called by the sender when transmission is succesful
		void ReceiveData(int data, int frame);

		// SendACK does an error check, followed by a receiveACK() call on the sender if it succeeds
		bool SendACK();

		// Returns the n_R value
		int getNR();

	private:
		// Latest received integer, default is 0 
		int receivedData; 

		// probability of transmission failing when sending ACK
		float p_error; 

		// n_R
		int n_R;
};

