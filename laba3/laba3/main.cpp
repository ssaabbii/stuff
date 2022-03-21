#include <stdexcept>
#include <iostream>
#include "parser.h"
#include "factory.h"
using namespace std;


int main() {
    string file = "desc.txt";
    parser redactor;
    redactor.parse(file);
    factory dungeon_master;
    for (int i : redactor.subsequence) {
        dungeon_master.check_subsequence(i, redactor.chain);
    }
    return 0;
}