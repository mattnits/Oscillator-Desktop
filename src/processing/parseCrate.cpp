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
    


    return 1;
}

// Parses through a Serato Database file and converts it from binary to a single string
/*
    Inputs:
        char* -=- the name of the database file
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

void parseStringData(std::string fileContents) {
    std::cout << fileContents;

    return;
}