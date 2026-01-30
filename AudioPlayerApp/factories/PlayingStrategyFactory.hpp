#pragma once
#include "../enums/PlayingStrategyType.hpp"
#include "../strategies/PlayingStrategy.hpp"
#include "../strategies/DefaultStrategy.hpp"
#include "../strategies/RandomStrategy.hpp"
#include "../strategies/SequenceStrategy.hpp"


class PlayingStrategyFactory {

public:
	PlayingStrategyFactory () {}
	~PlayingStrategyFactory () {}

public:
	PlayingStrategy* create (Playlist* playlist, PlayingStrategyType type){

		if (type == PlayingStrategyType::SEQUENCE)
		{
			return new SequenceStrategy(playlist);
		}
		else if (type == PlayingStrategyType::RANDOM)
		{
			return new RandomStrategy(playlist);
		}
		else {
			return new DefaultStrategy(playlist);
		}
	
	}
};