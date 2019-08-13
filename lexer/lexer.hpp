#ifndef HLEXER
#define HLEXER

#include <iostream>
#include <string>
#include <regex>
#include "../token/token.hpp"

using namespace std;

void lexer(vector<Token *> *tokenSequence, string inputData);
void printVectorToken(vector<Token *> vec);

#endif