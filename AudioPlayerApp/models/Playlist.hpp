#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Playlist
{

private:
	string name;
	vector<Song*>songList;

public:
	Playlist(string name) : name (name){
		cout<<name<<" created\n";
	}
	~Playlist() {
		cout<<name<<" destroyed\n";
	}


	string getName() {
		return name;
	}

	vector<Song*> getSongList(){
		return songList;
	}

	void addSong(Song* song){
		songList.push_back(song);
		cout<<song->getName()<<" added in playlist "<<name<<endl;
	}

	void deleteSong(Song* requiredSong) {
	    auto it = find(songList.begin(), songList.end(), requiredSong);

	    if (it != songList.end()) {
	        cout << "Song : "<< (*it)->getName() <<" deleted from playlist " << name << endl;
	        songList.erase(it);
	    } else {
	        cout << "Song not found in playlist " << name << endl;
	    }
	}

};