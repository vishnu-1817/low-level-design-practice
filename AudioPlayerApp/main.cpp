
#include <iostream>
#include <string>
#include "./models/Song.hpp"
#include "./models/Playlist.hpp"
#include "./facade.hpp"
#include "./enums/AudioDeviceType.hpp"
#include "./enums/PlayingStrategyType.hpp"
using namespace std;

int main(){
	cout<<"Audio Player Application\n";

	Facade* app = new Facade();

	Song* song1 = new Song("Song1");
	Song* song2 = new Song("Song2");
	Song* song3 = new Song("Song3");


	AudioDeviceType deviceType = AudioDeviceType::SPEAKER;
	app->connectDevice(deviceType);

	app->playSong(song1);
	app->playSong(song2);
	app->pauseSong();

	string playlistName = "Playlist1";
	Playlist* playlist1 = app->createPlaylist(playlistName);
	app->addSongInPlaylist(playlist1, song1);
	app->addSongInPlaylist(playlist1, song2);
	app->deleteSongInPlaylist(playlist1, song1);
	app->addSongInPlaylist(playlist1, song2);
	app->addSongInPlaylist(playlist1, song3);

	// app->playPlayList(playlist1, PlayingStrategyType::RANDOM);
	// app->pausePlaylist();



	return 0;
}

