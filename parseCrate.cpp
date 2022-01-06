#include "parseCrate.h"

const std::array<std::string, 10> tagList = {"tsng", "tart", "tlen", "tsiz", "tbit", "tsmp", "tbpm", "tadd", "tkey", "uadd"};
const std::array<std::string, 2> errorList = {"e: This", "e contains"};

// The main function in ParseCrate that calls all other functions in order
/*
    Inputs:
        char *fname -=- the file location to be parsed
    Outputs:
        Vector<Song> -=- a vector containing all the contents of the database file in Song object form
*/
std::vector<Song> parseCrate(char *fname) {
    std::vector<Song> songList;

    std::string fileContents = parseDatabaseFile(fname);
    if (fileContents != "") {
        songList = parseStringData(fileContents);
        //printSongDataToConsole(songList);
    }

    return songList;
}


// Simple split function that splits a string based on a delimiter
/*
    Inputs:
        string str -=- the string to be split
        string del -=- the delimiter
    Outputs:
        Vector<string> -=- a vector containing all the contents of the file split by the delimiter
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
        return "";
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
        vector<Song> -=- A list of song objects
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
        if (songData.size() > 0) {
            Song song(songData);
            songList.push_back(song);
        }
    }

    return songList;
}

// Splits a song string into its different attributes
/*
    Inputs:
        string songStr -=- Data of a song in string form
    Outputs:
        vector<string> -=- A list of the inputted songs attributes
*/
std::vector<std::string> splitByTagName(std::string songStr) {

    std::vector<std::string> songData, tempSongData;

    if (checkForErrors(songStr) == 1) {
        return songData;
    }

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

// Checks to see if the song string contains an error message
/*
    Inputs:
        string songStr -=- Data of a song in string form
    Outputs:
        int -=- (1) if theres an error, (0) if there isn't
*/
int checkForErrors(std::string songStr) {
    // std::cout << songStr << "\n\n\n";
    for (int i = 0; i < (int)errorList.size(); i++) {
        if (songStr.find(errorList.at(i)) != std::string::npos) {
            return 1;
        }
    }

    return 0;
}

// Prints the vector of songs in the console
/*
    Inputs:
        vector<string> songList -=- list of song objects
    Outputs:
        None
*/
void printSongDataToConsole(std::vector<Song> songList) {
    int errorCnt = 0;
    for (int i = 0; i < (int)songList.size(); i++) {
        if (songList.at(i).inErrorState() != 1) {
            songList.at(i).printSongData();
        }
        else {
            std::cout << "There was an error processing this track: " << songList.at(i).getFileName() << "\n";
            errorCnt++;
        }

    }
    std::cout << "Processed " << songList.size() - errorCnt << " songs successfully!" << "\n"
    << errorCnt << " errors occured\n";

}

// *** DEBUGGING METHOD ***
// Prints the contents of a vector containing strings
/*
    Inputs:
        vector<string> vectorData -=- list of string data
        string tag -=- The tag that is being parsed
    Outputs:
        None
*/
void _printVectorData(std::vector<std::string> vectorData, std::string tag) {
    std::cout << "==================================\n";
    std::cout << tag << "\n\n";
    for (int i = 0; i < (int)vectorData.size(); i++) {
        std::cout << vectorData.at(i) << "\n";
    }
    std::cout << "==================================\n";

}
