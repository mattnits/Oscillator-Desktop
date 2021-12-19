#include "song.h"


Song::Song(std::string dbSongName, std::string dbArtistName, int dbSongBpm, int dbSongLength) {
    songName = dbSongName;
    artistName = dbArtistName;
    bpm = dbSongBpm;
    length = dbSongLength;
}

Song::Song() {
    
}

void Song::setSongName(std::string newSongName) {
    songName = newSongName;
}

void Song::setArtistName(std::string newArtistName) {
    artistName = newArtistName;
}

void Song::setSongBpm(int newBpm) {
    bpm = newBpm;
}

void Song::setSongLength(std::string newSongLength) {
    int secs = songLengthToSeconds(newSongLength);
    length = secs;
}

int Song::songLengthToSeconds(std::string songLength) {
    int songLen = 0;
    int start = 0;
    int end = songLength.find(":");

    songLen += 60 * stoi(songLength.substr(start, end - start));
    start = end + songLength.size();
    end = songLength.find(":", start);
    songLen += stoi(songLength.substr(start, end - start));

    return songLen;
}

void Song::setFileSize(std::string newFileSize) {
    fileSize = newFileSize;
}

void Song::setBitRate(std::string newBitRate) {
    bitRate = newBitRate;
}

void Song::setSampleRate(std::string newSampleRate) {
    sampleRate = newSampleRate;
}

void Song::setSongKey(std::string newSongKey) {
    key = newSongKey;
}