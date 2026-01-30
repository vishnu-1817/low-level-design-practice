#include "./IAudioDeviceAdapter.hpp"
#pragma once

class SpeakerAdapter : public IAudioDeviceAdapter{
	Song* currentSong;
public:
	SpeakerAdapter() {}
	~SpeakerAdapter() {}

	void  connect() override{}
	void  disconnect() override{}

	void play(Song* song) override{
		currentSong = song;
		cout<<"Playing song : "<<song->getName()<<endl;
	}
	
	void pause () override{
		if (currentSong == nullptr) {
			cout<<"Invalid pause command, no song is being played\n";
			return;
		}
		cout<<"Pausing song : "<<currentSong->getName()<<endl;
		return;
	}
};