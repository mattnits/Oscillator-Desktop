#ifndef PARSECRATE_H
#define PARSECRATE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "song.h"

std::vector<Song> parseCrate(char *fname);
std::string parseDatabaseFile(char* filename);
std::vector<Song> parseStringData(std::string fileContents);
std::vector<std::string> splitString(std::string str, std::string del);
std::vector<std::string> splitByTagName(std::string songStr);
int checkForErrors(std::string songStr);
void printSongDataToConsole(std::vector<Song> songList);

// Debugging Methods
void _printVectorData(std::vector<std::string> vectorData, std::string tag);

#endif // PARSECRATE_H
