// Skilaverkefni3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class FlightBooking {
private:
	int id;
	int capacity;
	int reserved;
	int getPercentage();	
public:
	FlightBooking();
	FlightBooking(int id, int capacity, int reserved);
	~FlightBooking();
	void printStatus();
	bool reserveSeats(int number_of_seats);
	bool cancelReservations(int number_of_seats);
	int getId() { return id; };
};

FlightBooking::FlightBooking() {
	id = 0;
	capacity = 0;
	reserved = 0;
}
FlightBooking::~FlightBooking() {
	cout << "Goodbye" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

void FlightBooking::printStatus() {	
	if (getPercentage() >= 105)
	{
		cout << "Cannot perform this operation" << endl;
	}
	else {
		cout << endl << "Flight " << id << ": " << reserved << "/" << capacity << " " << "(" << getPercentage() << "%) seats taken" << endl;
	}
}

int FlightBooking::getPercentage() {
	return 100 * reserved / capacity;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
	int percentage = 0, seats = 0;
	seats = number_of_seats + reserved;
	percentage = 100 * seats / capacity;	
	if (seats >= 105)
	{
		cout << "Cannot perform this operation" << endl;
		return false;
	}
	else
	{
		reserved += number_of_seats;			
		return true;
	}
}
bool FlightBooking::cancelReservations(int number_of_seats) {
	if ((reserved - number_of_seats) < 0)
	{
		cout << "Cannot perform this operation" << endl;
		return false;
	}
	else
	{
		reserved -= number_of_seats;
		return true;
	}
}
int main()
{

	int reserved = 0, capacity = 0, n = 0;
	cout << "Enter the capacity of the flight: ";
	cin >> capacity;
	cout << "Enter amount of reserved seats: ";
	cin >> reserved;
	FlightBooking booking = FlightBooking(101, capacity, reserved);
	string command;
	stringstream ss;
	while (command != "quit") {		
		ss.clear();
		booking.printStatus();
		cout << "What would you like to do?: ";
		cin >> std::ws;
		getline(cin, command);
		ss << command;
		ss >> command >> n;
		if (command == "add")
		{			
			booking.reserveSeats(n);			
		}
		else if (command == "cancel")
		{
			booking.cancelReservations(n);
		}
		
	}
	return 0;
}