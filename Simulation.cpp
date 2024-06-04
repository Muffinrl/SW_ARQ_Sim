#include "Simulation.h"

Simulation::Simulation(std::string file, float p_send, float p_rec) {
	// Create objects for simulation
	package = new Package(file);
	sender = new Sender(p_send, package);
	receiver = new Receiver(p_rec);

	time = 0;

	isDone = false;
}

void Simulation::run() {

	// This is how many time steps the sender will wait between messages
	const int SENDER_PERIOD = 5;

	// Was sending a package succesful?
	bool s_succes = false;

	// Was sending an ACK succesful?
	bool ack_succes = false;

	// Did the receiver receive data?
	bool received_data = false;

	while (!isDone) {

		/*
			Sending / Receiving the ACK
		*/

		// Receiving must be handled before sending
		if (ack_succes) {
			std::cout << "[" << time << "]" << " - ACK received!" << std::endl;

			sender->ReceiveACK();
			ack_succes = false;
		}
		
		if (received_data) {
			std::cout << "[" << time << "]" << " - data received: " << package->getCurrentData() << std::endl;
			ack_succes = receiver->SendACK();
			received_data = false;
		}

		/*
			Sending / Receiving Data
		*/

		// Receiving must be handled before sending
		if (s_succes) {
			receiver->ReceiveData(package->getCurrentData(), package->getCurrentFrame());
			s_succes = false;
			// received_data is set to true to send an ACK next timestep.
			received_data = true;
		}

		if (time % SENDER_PERIOD == 0) {
			//std::cout << "[" << time << "]" << " Sending Package." << std::endl;
			s_succes = sender->SendPackage();
		}

		//  Stop the simulation when all lines have been simulated
		if (package->getCurrentFrame() == package->getPackageSize()) {
			isDone = true;

			std::cout << time << std::endl;
		}

		if (time > 100) {
			std::cout << "Simulation timeout" << std::endl;
			isDone = true;
		}

		time++;
	}
}