#include "writefile.h"

vector<string>& writefile::work(vector<string>& commands, vector<string>& input) {
    if (input.empty()) {
        throw runtime_error("Wrong subsequence of commands");
    }
    ofstream output(commands.at(0));
    for (const auto& line : input) {
        output << line << '\n';
    }
    input.clear();
    return input;
}