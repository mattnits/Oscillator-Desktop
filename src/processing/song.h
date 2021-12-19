#ifndef Song_H
#define Song_H
#include <iostream>
#include <string>
#include <vector>

class Song {
    private:
        std::string songName;
        std::string artistName;
        int length;
        std::string fileSize;
        std::string bitRate;
        std::string sampleRate;
        float bpm;
        std::string key;
        
        int songLengthToSeconds(std::string songLength);
    
    public:
        // Constructors
        Song();
        Song(std::string dbSongName, std::string dbArtistName, int dbSongBpm, int dbSongLength);
        
        // Setters
        void setSongName(std::string newSongName);
        void setArtistName(std::string newArtistName);
        void setSongBpm(int newBpm);
        void setSongLength(std::string newSongLength);
        void setFileSize(std::string newFileSize);
        void setBitRate(std::string newBitRate);
        void setSampleRate(std::string newSampleRate);
        void setSongKey(std::string newSongKey);

        // Getters
        std::string getSongName() {return songName;}
        std::string getArtistName() {return artistName;}
        float getSongBpm() {return bpm;}
        int getSongLength() {return length;}
        std::string getFileSize() {return fileSize;}
        std::string getBitRate() {return bitRate;}
        std::string getSampleRate() {return sampleRate;}
        std::string getSongKey() {return key;}
};

#endif