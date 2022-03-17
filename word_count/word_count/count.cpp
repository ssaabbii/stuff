#include "count.h"
#include<map>
#include<fstream>

void count::map_filling(string output_file, string csv_file)
{
	int end_of = 0;
	int s;
	string word;


	while (!end_of)
	{
		s = output_file.get();
		if (isalpha(s) || isdigit(s))
			word += (char)s;
		else if (!word.empty())
		{
			if (csv_map.count(word) == 0)
				csv.insert(pair<srting, int>(word, 1));
			else
				csv_map[word]++;
			word_counter++;
			word.clear();
		}
		if (s == EOF)
			end_of = 1;

	}
}

void printer()
{
	multimap<int, string> sort;
	for (auto item : csv_map)
		sort.insert(pair<int, string>(item.second, item.first));

	for(multimap<int, string>::reverse_iterator it = sort.rbegin(); it != sort.rend; ++it
		fout << it->second << "," << it->first << "," << (double)it->first / word_counter * 100 << endl;
}