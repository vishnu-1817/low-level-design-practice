#pragma once
#include "./PlayingStrategy.hpp"

class RandomStrategy : public PlayingStrategy {
private:
	Playlist* playlist;
public:
	RandomStrategy (Playlist* playlist) : playlist(playlist) {}
	~RandomStrategy () {}

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