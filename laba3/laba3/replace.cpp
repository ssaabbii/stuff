#include "replace.h"

vector<string>& _replace::work(vector<string>& commands, vector<string>& input) {
    if (input.empty()) {
        throw runtime_error("Wrong subsequence of commands");
    }
    for (auto& i : input)
    {
        string res(i);

        size_t pos = res.find(commands.at(0));
        while (pos != string::npos) {
            res.replace(pos, commands.at(0).size(), commands.at(1));
            pos = res.find(commands.at(0), pos);
        }
        i = res;
    }

    return input;
}
