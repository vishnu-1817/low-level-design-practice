#pragma once
#include <iostream>
using namespace std;


class Song
{

private :
	string name;
public:
	Song(string name) : name(name) {
		cout<<name<<" created\n";
	}
	~Song() {
		cout<<name <<" destroyed";
	}

	string getName() {
		return name;
	}
	
};