#pragma once
#include <string>
#include "./managers/AudioDeviceManager.hpp"
#include "./managers/PlaylistManager.hpp"
#include "./enums/PlayingStrategyType.hpp"
#include "./enums/AudioDeviceType.hpp"

class Facade {
private:
	AudioDeviceManager* audioDeviceManager;
	PlaylistManager* playlistManager;

public:
	Facade(){
		playlistManager = PlaylistManager::getInstance();
		audioDeviceManager = AudioDeviceManager::getInstance();
	}
	~Facade(){}

	void connectDevice(AudioDeviceType deviceType){
		audioDeviceManager->connect(deviceType);
	}

	void playSong( Song* song){
		audioDeviceManager->play(song);
	}

	void pauseSong(){
		audioDeviceManager->pause();
	}

	Playlist* createPlaylist(string &name){
		return playlistManager->createPlaylist(name);
	}

	void addSongInPlaylist(Playlist* playlist, Song* song){
		playlistManager->addSongInPlaylist(playlist, song);
	}

	void deleteSongInPlaylist (Playlist* playlist, Song* song){
		playlistManager->deleteSongInPlaylist(playlist, song);
	}

	void playPlayList(Playlist* playlist, PlayingStrategyType playingStrategyType){
		playlistManager->playPlayList(playlist, playingStrategyType);
	}

	void pausePlaylist(){
		playlistManager->pausePlaylist();
	}
};