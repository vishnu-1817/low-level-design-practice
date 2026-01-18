#include<iostream>
using namespace std;

class ParkingManager {

private:
	string name = "Parking Manager";
	string greetingMessage = "Hello User";

public:
	void greet(){
		cout<<greetingMessage<<"\n";
	}

};

