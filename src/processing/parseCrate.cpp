#include "parseCrate.h"
#include "song.h"


int main() {
    // unsigned char buffer[10];
    // FILE *ptr;

    // ptr = fopen("database V2","rb");

    // fread(buffer,sizeof(buffer),1,ptr); 

    // for(int i = 0; i<10; i++) {
    //     printf("%u", buffer[i]); // prints a series of bytes
    //     char c = buffer[i];
    //     printf("%c\n", c);
    // }

    char *fname = (char*)"database V2";
    std::string fileContents = parseDatabaseFile(fname);
    // parseStringData(fileContents);
    std::vector<std::string> myvector = splitString(fileContents, "fil");
    std::cout << myvector.size();


    return 1;
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
         
*/
void parseStringData(std::string fileContents) {
    std::cout << fileContents;

    

    return;
}

// Simple split function that splits a string based on a delimiter
/*
    Inputs:
        string str -=- the string to be split
        string del -=- the delimiter
    Outputs:
        String -=- a string containing all the contents of the file  
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