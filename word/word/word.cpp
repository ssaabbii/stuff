#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string get_word(istream& fin) // функция, считывающая слово из файла
{
    char s;
    string res = "";
    s = fin.get();
    while (!isalpha(s) && !fin.eof()) // на случай пробела
        s = fin.get();
    while (isalpha(s))
    {
        res.push_back(s);
        s = fin.get();
    }
    return res;
}

int main(int argc, char* argv[])
{
    //  if (argc > 2) 
    // {
    ifstream fin;
    ofstream out;

    //fin.open(argv[1]);
    //out.open(argv[2]);

    fin.open("in.txt");
    out.open("out.csv");

    map<string, int> word_map;
    int word_counter = 0;
    string word;

    while (!(word = get_word(fin)).empty())
    {
        word_map[word]++;
        word_counter++;
    }

    multimap<int, string> sorted_word_map;

    for (auto word = word_map.rbegin(); word != word_map.rend(); word++) // rbegin - Возвращает итератор, указывающий на первый элемент в обратном map.c
        sorted_word_map.insert(pair<int, string>(word->second, word->first)); //rend	- Возвращает итератор, указывающий на положение после последнего элемента в обращенном операторе map .

    word_map.clear();

    for (auto elem = sorted_word_map.rbegin(); elem != sorted_word_map.rend(); elem++) 
        out << elem->second << ',' << elem->first << ',' << elem->first / (double)word_counter * 100 << '%' << endl;
    //}
    //else {
        //std::cout << "Not enough arguments" << std::endl;
        //return 0;
    //}
    cout << "Words have been counted" << endl;
    return 0;
}