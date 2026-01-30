#include<iostream>
#include <string>
using namespace std;

#pragma once


class IBookingFrontdesk {

public:
	IBookingFrontdesk () {cout<<"IBookingFrontdesk\n";}
	IBookingFrontdesk (string &name){cout<<name<<" IBookingFrontdesk \n";}
	virtual ~IBookingFrontdesk ()  {}

	// virtual functions to show movie list from a hall/city/ hall and city
	virtual void showMovieList () = 0;
	// virtual void showMovieList (ICinemaHall* cinemaHall) = 0;
	// virtual void showMovieList (ICity* city) = 0;
	// virtual void showMovieList (ICity* city, ICinemaHall* cinemaHall) = 0;

	//virtual functions to book a movie ticket
	// virtual void bookTicket (ICinemaHall* cinemaHall, IMovie* movie) = 0;

};