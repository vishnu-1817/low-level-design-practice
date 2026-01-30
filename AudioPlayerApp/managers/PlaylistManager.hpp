#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../factories/PlayingStrategyFactory.hpp"
#include "../models/Playlist.hpp"
#include "../enums/PlayingStrategyType.hpp"
#include "./AudioDeviceManager.hpp"

using namespace std;

class PlaylistManager {

private:
	static PlaylistManager* instance;
	vector<Playlist*> playlistCollection;
	Playlist* currentPlaylist;
	PlayingStrategy* currentPlayingStrategy;
	PlaylistManager() { cout<<"PlaylistManager created\n";}

public:
	~PlaylistManager() { cout<<"PlaylistManager destroyed\n";}

	static PlaylistManager* getInstance(){

		if (instance != nullptr) return instance;
		instance = new PlaylistManager();
		return instance;
	}

	Playlist* createPlaylist (string name){
		for (auto playlist : playlistCollection) {
			if (playlist->getName() == name) {
				cout<<"Playlist with the "<<name<<" already available.\n";
				return playlist;
			}
		}
		Playlist* playlist = new Playlist(name);
		playlistCollection.push_back(playlist);
		return playlist;
	}


	void addSongInPlaylist (Playlist* playlist, Song* song){
		auto it = find(playlistCollection.begin(), playlistCollection.end(), playlist);

		if (it == playlistCollection.end()){
			cout<<"Playlist with the name "<<playlist->getName()<<" is not present\n";
			return;
		} else {
			(*it)->addSong(song);
		}

		return;
	}

	void deleteSongInPlaylist (Playlist* playlist, Song* song){
		auto it = find(playlistCollection.begin(), playlistCollection.end(), playlist);

		if (it == playlistCollection.end()){
			cout<<"Playlist with the name "<<playlist->getName()<<" is not present\n";
			return;
		} else {
			(*it)->deleteSong(song);
		}

		return;
	}


	void playPlayList(Playlist* playlist, PlayingStrategyType playingStrategyType){
		auto it = find(playlistCollection.begin(), playlistCollection.end(), playlist);

		if (it == playlistCollection.end()) {
			cout<<"Playlist with the name "<<playlist->getName()<<" is not present\n";
			return;
		}

		currentPlaylist = playlist;
		cout<<"Strategy creating\n";
		PlayingStrategyFactory* factory = new PlayingStrategyFactory();
		currentPlayingStrategy = factory->create( playlist, playingStrategyType);
		delete factory;
		cout<<"Strategy created\n";

		Song* song = currentPlayingStrategy->nextSong();
		AudioDeviceManager* audioDeviceManager = AudioDeviceManager::getInstance();
		audioDeviceManager->play(song);

	}

	void pausePlaylist(){
		(AudioDeviceManager::getInstance())->pause();
	}

	void playNextPlaylistSong(){
		Song* song = currentPlayingStrategy->nextSong();
		(AudioDeviceManager::getInstance())->play(song);
	}

	void playPreviousPlaylistSong(){
		Song* song = currentPlayingStrategy->prevSong();
		(AudioDeviceManager::getInstance())->play(song);
	}
};

PlaylistManager* PlaylistManager::instance = nullptr;