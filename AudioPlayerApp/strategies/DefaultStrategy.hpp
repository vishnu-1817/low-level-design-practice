#pragma once
#include "./PlayingStrategy.hpp"

class DefaultStrategy : public PlayingStrategy {
private:
	Playlist* playlist;
public:
	DefaultStrategy (Playlist* playlist) : playlist(playlist) {}
	~DefaultStrategy () {}

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