#pragma once
#include "worker.h"
#include <iostream>
#include <fstream>

class writefile : public worker {
public:
    vector<string>& work(vector<string>& commands, vector<string>& input) override;
private:

};
