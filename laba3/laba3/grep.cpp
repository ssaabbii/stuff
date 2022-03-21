#include "grep.h"


vector<string>& grep::work(vector<string>& commands, vector<string>& input) {
    if (input.empty()) {
        throw runtime_error("Wrong subsequence of commands");
    }
    string word = commands.at(0);
    for (auto line = input.begin(); line != input.end(); ++line)
    {
        if (line->find(word) == string::npos)
        {
            input.erase(line);
            --line;
        }
    }
    return input;
}