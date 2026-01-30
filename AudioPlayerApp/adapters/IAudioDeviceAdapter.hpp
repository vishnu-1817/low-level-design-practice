#pragma once

class IAudioDeviceAdapter {

public:
	IAudioDeviceAdapter() = default;
	~IAudioDeviceAdapter() = default;

	void virtual connect() = 0;
	void virtual disconnect() = 0;
	void virtual play(Song* song) = 0;
	void virtual pause () = 0;
};