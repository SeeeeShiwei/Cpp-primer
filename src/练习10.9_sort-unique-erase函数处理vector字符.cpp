//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.9  sort-unique-erase函数处理vector字符
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
		cout << word << endl;
	}
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 原位排序
    cout << "sort排序后的单词："<< endl;
    display(words);
    // unique 函数指向不重复单词之后的一个迭代器
    auto end_unique = unique(words.begin(), words.end());
    cout << "unique去除重复后的单词："<< endl;
    display(words);
    // erase:向量操作，删除重复单词
    words.erase(end_unique, words.end());
    cout << "erase擦除重复后的单词："<< endl;
    display(words);

}

int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};

	elimDups(words);
	return 0;
}
