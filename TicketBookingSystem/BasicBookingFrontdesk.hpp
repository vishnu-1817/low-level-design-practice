#include <iostream>
#include "IBookingFrontdesk.hpp"
#include <string>
using namespace std;

class BasicBookingFrontdesk : public IBookingFrontdesk {

	string name = "Basic Booking Frontdesk";

public:
	BasicBookingFrontdesk () {
		cout<<name<<" created\n";
	}

	BasicBookingFrontdesk (const string &name): name(name) {
		cout<<name<<" created\n";
	}
	
	~BasicBookingFrontdesk () override {
		cout<<name<<" is deleted\n";
	}

	// virtual functions to show movie list from a hall/city/ hall and city
	void showMovieList () override{
		cout<<"Showing movie name\n";
	}
	// void showMovieList (ICinemaHall* cinemaHall) override{
	// 	cout<<"Showing movie name\n";
	// }
	// void showMovieList (ICity* city) override{
	// 	cout<<"Showing movie name\n";
	// }
	// void showMovieList (ICity* city, ICinemaHall* cinemaHall) override{
	// 	cout<<"Showing movie name\n";
	// }

	//virtual functions to book a movie ticket
	// void bookTicket (ICinemaHall* cinemaHall, IMovie* movie) override{
	// 	cout<<"Booking Ticket";
	// }



};