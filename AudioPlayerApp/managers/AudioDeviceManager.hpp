#pragma once
#include <memory>
#include "../enums/AudioDeviceType.hpp"
#include "../factories/AudioDeviceFactory.hpp"

using namespace std;

class AudioDeviceManager
{
private:
	static AudioDeviceManager* instance;
	IAudioDeviceAdapter* currentAudioDevice;
	AudioDeviceFactory* audioDeviceFactory;
	bool isAudioPlaying;

	AudioDeviceManager() {
		audioDeviceFactory = new AudioDeviceFactory();
		isAudioPlaying = false;
		currentAudioDevice = nullptr;
	}

public:
	~AudioDeviceManager() {
		delete audioDeviceFactory;
		delete currentAudioDevice;
		delete instance;
	}

	static AudioDeviceManager* getInstance(){
		if (instance != nullptr) return nullptr;
		instance = new AudioDeviceManager();
		return instance;
	}

	void play(Song* song){

		if (currentAudioDevice == nullptr) {
			cout<<"No device connected.\n";
			return;
		}

		if (song == nullptr){
			cout<<"Invalid song attempted to be played.\n";
			return;
		}

		if (isAudioPlaying) pause();
		isAudioPlaying = true;
		currentAudioDevice->play(song);
		cout<<"Audio Player Started : "<< song->getName()<<endl;
	}

	void pause() {
		if (currentAudioDevice == nullptr) {
			cout<<"No device connected\n";
			return;
		}

		if (isAudioPlaying == false) return;
		isAudioPlaying = false;
		currentAudioDevice->pause();
		cout<<"Audio Paused.\n";
	}

	void connect(AudioDeviceType type){

		IAudioDeviceAdapter* device = audioDeviceFactory->create(type);
		swap(device, currentAudioDevice);
		if (device != nullptr) delete device;
		cout<<"Device connected.\n";
	}
	
};

AudioDeviceManager* AudioDeviceManager::instance = nullptr;