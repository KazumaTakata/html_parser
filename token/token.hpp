#ifndef HTOKEN
#define HTOKEN

#include <iostream>
#include <string>

using namespace std;

enum TokenKind
{
    OpenTagToken,
    CloseTagToken,
    StringToken
};

typedef struct Token
{
    TokenKind kind;
    string value;
} Token;
#endif