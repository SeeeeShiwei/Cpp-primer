//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.19 biggies函数(stable partition)
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;

void display(vector<string> words)
{
	for(auto word : words)
	{
		cout << word << " ";
	}
	cout << endl;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 原位排序
    // unique 函数指向不重复单词之后的一个迭代器
    auto end_unique = unique(words.begin(), words.end());
    // erase:向量操作，删除重复单词
    words.erase(end_unique, words.end());
}


string make_plural(size_t ctr, const string &word, const string &endding)
{
    return ctr > 1 ? word+endding:word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	cout << "删除重复后的单词："<< endl;
	display(words);


	auto wc = stable_partition(words.begin(), words.end(),
			[sz] (const string s1)
			{return s1.size() > sz;}); //lambda函数

	cout << "按照长度化分单词"<< endl; // 划分重新排序，满足条件的在前部分
	display(words);

	auto count = wc - words.begin();
	cout << count << " " << make_plural(count, "word", "s") <<
			" of length " << sz << " or longer" << endl;

	for_each(words.begin(),wc, [] (const string &s) {cout << s << " ";});
	cout << endl;

}


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};
	vector<string>::size_type sz = 3;
	biggies(words, sz);

	return 0;
}
