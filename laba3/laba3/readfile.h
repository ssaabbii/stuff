#pragma once
#include "worker.h"
#include <iostream>
#include <fstream>

class readfile : public worker {
public:
    vector<string>& work(vector<string>& commands, vector<string>& input) override;
private:

};
