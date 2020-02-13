//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.16 lambda函数编写biggies
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


	stable_sort(words.begin(), words.end(),
			[] (const string s1, const string s2)
			{return s1.size() < s2.size();}); //lambda函数

	cout << "按照长度排序单词"<< endl;
	display(words);

	auto wc = find_if(words.begin(), words.end(),
			[sz] (const string s){return s.size() > sz;}); // 返回首个大于给定长度sz的单词迭代器

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") <<
			" of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [] (const string &s) {cout << s << " ";});
	cout << endl;

}


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};
	vector<string>::size_type sz = 3;
	biggies(words, sz);

	return 0;
}

/*
 * 删除重复后的单词：
fox jump over quick red slow the turtle
按照长度排序单词
fox red the jump over slow quick turtle
5 words of length 3 or longer
jump over slow quick turtle
 *
 */
