#include "song.h"


Song::Song() {
    
}

Song::Song(std::vector<std::string> songDataList) {
    if (songDataList.size() < 9) {
        throw "Error creating Song. Missing values!";
    }
    _errorState = 0;
    fileName = songDataList.at(0);
    songName = songDataList.at(1);
    artistName = songDataList.at(2);
    setSongLength(songDataList.at(3));
    fileSize = songDataList.at(4);
    bitRate = songDataList.at(5);
    setSongBpm(songDataList.at(7));
    sampleRate = songDataList.at(6);
    key = songDataList.at(8);
    
}

void Song::setSongName(std::string newSongName) {
    songName = newSongName;
}

void Song::setArtistName(std::string newArtistName) {
    artistName = newArtistName;
}

void Song::setSongBpm(std::string newBpm) {
    try {
        float value = (int)(stof(newBpm) * 10 + .5);
        bpm = (float)value / 10;
    } catch (...) {
        std::cout << "Error occured getting BPM\n";
        _errorState = 1;
        bpm = -1;
    }
    
}

void Song::setSongLength(std::string newSongLength) {
    int secs = songLengthToSeconds(newSongLength);
    length = secs;
}

int Song::songLengthToSeconds(std::string songLength) {
    int songLen = 0;
    int start = 0;
    int end = songLength.find(":");

    try {
        songLen += 60 * stoi(songLength.substr(start, end - start));
        start = end + 1;
        end = songLength.find(":", start);
        songLen += stoi(songLength.substr(start, end - start));
    } catch (...) {
        std::cout << "Error occured converting song length to seconds\n";
        _errorState = 1;
        songLen = -1;
    }

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

void Song::printSongData() {
    std::cout << "File:\t\t" << fileName << "\nSong:\t\t" << songName
        << "\nArtist:\t\t" << artistName << "\nLength:\t\t" << length
        << "s\nBPM:\t\t" << bpm << "\nSize:\t\t" << fileSize << "\nBit Rate:\t" << bitRate 
        << "\nSample Rate:\t" << sampleRate << "\nKey:\t\t" << key  
        << "\n---------------------------------------------\n";
}

void Song::_printDataList(std::vector<std::string> songDataList) {
    std::cout << "Data List: \n";
    for (int i = 0; i < (int)songDataList.size(); i++) {
        std::cout << songDataList.at(i) << "\n";
    }
    
}