#include "lexer.hpp"

void removeSpace(string *input)
{
    int isThereSpace = 1;
    while (isThereSpace)
    {
        if (' ' == input->at(0))
        {
            *input = input->substr(1, input->length());
        }
        else
        {
            isThereSpace = 0;
        }
    }
}

void printVectorToken(vector<Token *> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        Token *token = vec.at(i);
        switch (token->kind)
        {
        case OpenTagToken:
            cout << "(open)";
            break;
        case CloseTagToken:
            cout << "(close)";
            break;
        case StringToken:
            cout << "(string)";
            break;
        default:
            break;
        }
    }
}

void lexer(vector<Token *> *tokenSequence, string inputData)
{
    regex openTagRegex("< *([a-z]*) *>");
    regex closeTagRegex("</ *([a-z]*) *>");
    regex stringRegex("[^<]*");

    while (!inputData.empty())
    {

        removeSpace(&inputData);

        switch (inputData.at(0))
        {
        case '<':
            if (inputData.at(1) == '/')
            {

                smatch m;
                regex_search(inputData, m, closeTagRegex);
                string matchedString = m[1];
                Token *token = new Token();
                token->kind = CloseTagToken;
                token->value = matchedString;
                tokenSequence->push_back(token);

                inputData = inputData.substr(m.length(0), inputData.length());
            }
            else
            {

                smatch m;
                regex_search(inputData, m, openTagRegex);
                string matchedString = m[1];
                Token *token = new Token();
                token->kind = OpenTagToken;
                token->value = matchedString;
                tokenSequence->push_back(token);

                inputData = inputData.substr(m.length(0), inputData.length());
            }
            break;
        default:

            smatch m;
            regex_search(inputData, m, stringRegex);
            string matchedString = m[0];
            Token *token = new Token();
            token->kind = StringToken;
            token->value = matchedString;
            tokenSequence->push_back(token);

            inputData = inputData.substr(m.length(0), inputData.length());
            break;
        }
    }
}
