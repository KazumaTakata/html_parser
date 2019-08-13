#ifndef HNODE
#define HNODE

#include <iostream>
#include <string>
#include "./token/token.hpp"

using namespace std;

enum NodeKind
{
    OpenCloseNode,
    NodeNode,
    NoneNode
};

typedef struct Node
{
    NodeKind kind;
    Token *openToken;
    Token *closeToken;
    vector<Node *> *childnodes;

} Node;

#endif