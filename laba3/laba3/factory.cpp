#include "factory.h"
#include "parser.h"

worker* factory::check_subsequence(const int subsequence, map<int, block> chain) {
    if (chain[subsequence].command == "dump") {
        worker* worker = new dump;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else if (chain[subsequence].command == "grep") {
        worker* worker = new grep;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else if (chain[subsequence].command == "readfile") {
        worker* worker = new readfile;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else if (chain[subsequence].command == "replace") {
        worker* worker = new _replace;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else if (chain[subsequence].command == "sort") {
        worker* worker = new _sort;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else if (chain[subsequence].command == "writefile") {
        worker* worker = new writefile;
        worker->work(chain[subsequence].arguments, input);
        return worker;
    }
    else {
        throw runtime_error("Wrong name of worker!");
    }
}