#include<bits/stdc++.h>
#include "IBookingFrontdesk.hpp"
#include "BasicBookingFrontdesk.hpp"
using namespace std;

int main(){
	cout<<"Hello, welcome to movie ticket booking portal\n";
	IBookingFrontdesk* bookingFrontDesk = new BasicBookingFrontdesk();
	IBookingFrontdesk* bookingFrontDesk1 = new BasicBookingFrontdesk("Frontdesk 2");

	// bookingFrontDesk1->showMovieList();
	bookingFrontDesk->showMovieList();

	delete bookingFrontDesk;
	delete bookingFrontDesk1;

	return 0;
}