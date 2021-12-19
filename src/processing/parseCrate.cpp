#include "parseCrate.h"

const std::array<std::string, 10> tagList = {"tsng", "tart", "tlen", "tsiz", "tbit", "tsmp", "tbpm", "tadd", "tkey", "uadd"};

int main() {
    std::vector<Song> songList;
    char *fname = (char*)"database V2";
    std::string fileContents = parseDatabaseFile(fname);
    songList = parseStringData(fileContents);
    std::cout << songList.size();

    return 1;
}

// Simple split function that splits a string based on a delimiter
/*
    Inputs:
        string str -=- the string to be split
        string del -=- the delimiter
    Outputs:
        Vector -=- a vector containing all the contents of the file split by the delimiter  
*/
std::vector<std::string> splitString(std::string str, std::string del) {
    std::vector<std::string> contentList;

    int start = 0;
    int end = str.find(del);
    while (end != -1) {
        contentList.push_back(str.substr(start, end - start));
        start = end + del.size();
        end = str.find(del, start);
    }
    contentList.push_back(str.substr(start, end - start));

    return contentList;
}

// Parses through a Serato Database file and converts it from binary to a single string
/*
    Inputs:
        char* filename -=- the name of the database file
    Outputs:
        String -=- a string containing all the contents of the file  
*/
std::string parseDatabaseFile(char *filename) {
    std::string fileContents;
    
    FILE *fh = fopen(filename, "rb");
    
    if (fh == NULL) {
        printf("Error, invalid file name\n");
        return NULL;
    }
    
    while (!feof(fh)) {
        unsigned char buffer[1];
        fread(buffer, sizeof(buffer), 1, fh);

        // Gets rid of unwanted characters
        if (buffer[0] >= 32 && buffer[0] < 127) {
            char strbuffer = buffer[0];
            fileContents.push_back(strbuffer);
        }
    }

    return fileContents;
}

// Takes the string data and splits it into critical values
/*
    Inputs:
        string fileContents -=- The contents of the DB file in string form
    Outputs:
        vector -=- A list of song objects
*/
std::vector<Song> parseStringData(std::string fileContents) {
    std::vector<Song> songList;
    std::vector<std::string> songData;
    Song tempSong;
    
    std::vector<std::string> songStringList = splitString(fileContents, "fil");

    // Erase DB info at front
    songStringList.erase(songStringList.begin());

    for (int i=0; i < (int)songStringList.size(); i++) {
        songData = splitByTagName(songStringList.at(i));        
        Song song(songData);
        song.printSongData();
        songList.push_back(song);
    }

    return songList;
}

// Splits a song string into its different attributes
/*
    Inputs:
        string songStr -=- Data of a song in string form
    Outputs:
        vector -=- A list of the inputted songs attributes
*/
std::vector<std::string> splitByTagName(std::string songStr) {

    std::vector<std::string> songData, tempSongData;
    
    tempSongData = splitString(songStr, tagList.at(0));
    songData.push_back(tempSongData.at(0));

    for (int i = 1; i < (int)tagList.size(); i++) {
        
        if (tempSongData.size() > 1) {
            tempSongData = splitString(tempSongData.at(1), tagList.at(i));
        } else {
            tempSongData = splitString(tempSongData.at(0), tagList.at(i));
        }

        tempSongData.size() > 1 ? songData.push_back(tempSongData.at(0)) : songData.push_back("NULL");     
    }

    // Erases the memory location in the array
    songData.erase(songData.begin() + 8);
    

    return songData;
}