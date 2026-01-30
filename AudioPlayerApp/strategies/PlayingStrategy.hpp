#pragma once

class PlayingStrategy {
public:
	PlayingStrategy() = default;
	~PlayingStrategy() = default;
	virtual Song* nextSong() = 0;
	virtual Song* prevSong() = 0;
	virtual bool hasNextSong() = 0;
	virtual bool hasPrevSong() = 0;
};