#pragma once
#pragma warning(default:4716)
#include <string>
#include <vector>

using namespace std;


class worker {
public:
    virtual vector<string>& work(vector<string>& commands, vector<string>& input) { }
};

