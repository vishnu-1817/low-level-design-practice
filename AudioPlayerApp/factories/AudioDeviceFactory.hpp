#pragma once

#include "../enums/AudioDeviceType.hpp"
#include "../adapters/WiredMediaAdapter.hpp"
#include "../adapters/SpeakerAdapter.hpp"
#include "../adapters/BluetoothAdapter.hpp"
#include "../adapters/IAudioDeviceAdapter.hpp"

using namespace std;

class AudioDeviceFactory {

public:
	AudioDeviceFactory () {}
	~AudioDeviceFactory () {}

public:
	IAudioDeviceAdapter* create (AudioDeviceType type){


		if (type == AudioDeviceType::BLUETOOTH)
		{	
			return new BluetoothAdapter();
		}
		else if (type == AudioDeviceType::WIRED_MEDIA)
		{
			return new WiredMediaAdapter();
		}
		else {
			return new SpeakerAdapter();
		}
	
	}
};