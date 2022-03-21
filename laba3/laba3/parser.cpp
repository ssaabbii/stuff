#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

parser::parser() {

}

void parser::parse(const string& s1) {
    ifstream input(s1);
    string line;
    if (!input.is_open()) {
        throw runtime_error("Couldn't find this file");
    }
    else {
        getline(input, line);
        int t = 0;
        if (line != "desc") {
            throw runtime_error("Wrong type of file");
        }
        else if (input.eof()) {
            throw runtime_error("Wrong type of file");
        }
        else {
            while (getline(input, line)) {
                if (line == "csed") {
                    t += 1;
                    break;
                }
                stringstream ss(line); //разбиваем строку на слова
                string x;
                int num = 0;
                string com;
                vector<string> arg;
                ss >> x;
                int n = x.length() - 1;
                for (char i : x) {
                    if (!isdigit(i)) {
                        throw runtime_error("Wrong type of data (id is missing)");
                    }
                    else {
                        int deg = pow(10, n);
                        num += deg * i - 48 * deg;
                        n--;
                    }
                }
                ss >> x;
                if (x == "->") {
                    throw runtime_error("Wrong type of data (csed is missing)");
                }
                else if (x[0] != '=' && x.length() > 1) {
                    throw runtime_error("Wrong type of data (sign '=' is missing)");
                }
                ss >> x;
                if (x != "dump" && x != "grep" && x != "readfile" && x != "replace" && x != "sort" && x != "writefile") {
                    throw runtime_error("Wrong type of data (name of method is missing)");
                }
                else {
                    com = x;
                }
                while (ss >> x) {
                    arg.push_back(x);
                }
                block spisok;
                spisok.command = com;
                spisok.arguments = arg;
                chain[num] = spisok;
            }
            if (t == 0) {
                throw runtime_error("Wrong type of data (csed is missing)");
            }

        }

    }
    int flag = 0;
    if (!getline(input, line)) {
        throw runtime_error("Subsequence is missing!");
    }
    else {
        stringstream ss(line); //разбиваем строку на слова
        string x;
        int i = 0;
        while (ss >> x) {
            int num = 0;
            if (isdigit(x[0])) {
                int n = x.length() - 1;
                for (char i : x) {
                    if (!isdigit(i)) {
                        throw runtime_error("Wrong type of data (incorrect format of number)");
                    }
                    else {
                        int deg = pow(10, n);
                        num += deg * i - 48 * deg;
                        n--;
                    }
                }
                subsequence.push_back(num);
                if (flag != 0) {
                    throw runtime_error("Wrong type of data (sign '->' is missing)");
                }
                flag += 1;
            }
            else {
                if (x != "->") {
                    throw runtime_error("Wrong type of data (sign '->' is missing)");
                }
                if (flag != 1) {
                    throw runtime_error("Wrong type of data");
                }
                flag -= 1;
            }
        }
    }
}