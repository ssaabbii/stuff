#pragma once
#include<string>
#include<map>
#include<fstream>
#include<iostream>

using namespace std;

class count 
{
	int word_counter = 0;
	map<string, int> csv_map;

public:
	void printer(string output_file, string csv_file);
	void map_filling(string output_file, string csv_file);

};