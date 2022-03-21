#pragma once
#include "worker.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class _sort : public worker {
public:
    vector<string>& work(vector<string>& commands, vector<string>& input) override;
private:

};