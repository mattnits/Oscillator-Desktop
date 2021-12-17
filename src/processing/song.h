#ifndef Song_H
#define Song_H
#include <iostream>
#include "string"

class Song {
    private:
        std::string songName;
        std::string artistName;
        int bpm;
    
    public:
        Song(std::string songName, std::string artistName, int bpm);
};

#endif