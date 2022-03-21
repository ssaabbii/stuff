#include "sort.h"

vector<string>& _sort::work(vector<string>& commands, vector<string>& input) {
    if (input.empty()) {
        throw runtime_error("Wrong subsequence of commands");
    }
    std::sort(input.begin(), input.end());
    return input;
}