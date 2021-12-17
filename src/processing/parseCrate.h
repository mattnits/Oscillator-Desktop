#ifndef PARSE_CRATE_H
#define PARSE_CRATE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "string"

const int STX = 02;

std::string parseDatabaseFile(char* filename);
void parseStringData(std::string fileContents);


#endif