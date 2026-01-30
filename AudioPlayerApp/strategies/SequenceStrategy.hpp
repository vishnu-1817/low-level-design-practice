#pragma once
#include "./PlayingStrategy.hpp"

class SequenceStrategy : public PlayingStrategy {
private:
	Playlist* playlist;
public:
	SequenceStrategy (Playlist* playlist) : playlist(playlist) {}
	~SequenceStrategy () {}

	Song* nextSong() override {
		return nullptr;
	}
	Song* prevSong() override {
		return nullptr;
	}
	bool hasNextSong() override {
		return true;
	}
	bool hasPrevSong() override {
		return true;
	}
};