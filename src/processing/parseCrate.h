#ifndef PARSE_CRATE_H
#define PARSE_CRATE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "song.h"

const int STX = 02;

std::string parseDatabaseFile(char* filename);
std::vector<Song> parseStringData(std::string fileContents);
std::vector<std::string> splitString(std::string str, std::string del);
std::vector<std::string> splitByTagName(std::string songStr);


#endif