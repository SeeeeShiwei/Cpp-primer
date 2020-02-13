//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.11 stable_sort函数维持相等元素原有顺序
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
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 原位排序
    // unique 函数指向不重复单词之后的一个迭代器
    auto end_unique = unique(words.begin(), words.end());
    // erase:向量操作，删除重复单词
    words.erase(end_unique, words.end());
}

bool isShorter(const string s1, const string s2)
{
    return s1.size() < s2.size();
}


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};

	elimDups(words);
    cout << "erase擦除重复后的单词："<< endl;
    display(words);


    stable_sort(words.begin(), words.end(), isShorter); //稳定排序，不改变相等元素的原有顺序
    cout << endl;
    cout << "按照长度排序单词"<< endl;
    display(words);

	return 0;
}
