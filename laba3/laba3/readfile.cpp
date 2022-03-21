#include "readfile.h"

vector<string>& readfile::work(vector<string>& commands, vector<string>& input) {
    ifstream output(commands.at(0));
    if (!output.is_open())
    {
        throw runtime_error("Couldn't find this file");
    }

    string line;
    while (getline(output, line))
    {
        input.push_back(line);
    }

    return input;
}