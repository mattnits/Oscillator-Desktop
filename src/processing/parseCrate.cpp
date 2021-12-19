#include "parseCrate.h"

const std::array<std::string, 9> tagList = {"tsng", "tart", "tlen", "tsiz", "tbit", "tsmp", "tbpm", "tadd", "tkey"};

int main() {
    char *fname = (char*)"database V2";
    std::string fileContents = parseDatabaseFile(fname);
    parseStringData(fileContents);

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
    Song tempSong;
    
    std::vector<std::string> songStringList = splitString(fileContents, "fil");

    // Erase DB info at front
    songStringList.erase(songStringList.begin());

    // int songListSize = songStringList.size();
    for (int i=0; i < 1; i++) {
        
        tempSong = createSongFromString(songStringList.at(i));
        // std::cout << tempSong.getSongName();
    }

    return songList;
}



Song createSongFromString(std::string songStr) {

    std::vector<std::string> songData, tempSongData;

    Song song("1", "2", 51, 1);
    
    songData = splitByTagName(songStr, songData);
    
    for (int i = 0; i < (int)songData.size(); i++){
        std::cout << songData.at(i) << "\n";
    }
    

    return song;
}

std::vector<std::string> splitByTagName(std::string songStr, std::vector<std::string> songData) {

    std::vector<std::string> tempSongData;

    tempSongData = splitString(songStr, tagList.at(0));

    for (int i = 1; i < (int)tagList.size(); i++) {
        tempSongData = splitString(songStr, tagList.at(i));

        tempSongData.size() > 1 ? songData.push_back(tempSongData.at(1)) : songData.push_back(""); 
        
    }
    
    


    return songData;
}


/*
Music/Melodic Dubstep/Grant & RUNN - Contagious [Monstercat EP Release].mp3
tsngbGrant & RUNN - Contagious [Monstercat EP Release]
tart ARTIST NAME
tlen03:36.82
tsiz5.0MB
tbit192.0kbps
tsmp44.1k
tbpm103.00
tadd1584818735
tkeyEuadd^vj/ulblu
tme_Lu
tpcsbavbhr
tbmisbplyblopbi
tubovcbcrtbirobwlbbwllbunsbbglbkrko
trk7
ttypmp3p



*/