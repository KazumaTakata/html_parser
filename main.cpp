#include <iostream>
#include <string>
#include <regex>
#include "token/token.hpp"
#include "lexer/lexer.hpp"
#include "node.hpp"

using namespace std;
int tokenIndex = 0;
vector<Node *> *parseTags(vector<Token *> tokenSequence);

Node *parseTag(vector<Token *> tokenSequence)
{
    Node *node = new Node();
    vector<Node *> *childNode;

    Token *token = tokenSequence.at(tokenIndex);
    switch (token->kind)
    {
    case OpenTagToken:
        // Node *node = new Node();
        node->kind = OpenCloseNode;
        node->openToken = token;
        childNode = parseTags(tokenSequence);
        node->childnodes = childNode;
        break;
    case StringToken:
        cout << "(string)";
        break;
    case CloseTagToken:
        break;
    default:
        break;
    }
    return node;
}

vector<Node *> *parseTags(vector<Token *> tokenSequence)
{
    Node *node = parseTag(tokenSequence);
    vector<Node *> *nodes = parseTags(tokenSequence);
    (*nodes).push_back(node);
    return nodes;
}

int main()
{
    vector<Token *> tokenSequence;
    string inputData = "     <html>ffwefew fewf < body > fewfew <p></p>  </ body> </ html>";

    lexer(&tokenSequence, inputData);
    printVectorToken(tokenSequence);

    vector<Node *> *nodes = parseTags(tokenSequence);

    return 0;
}
