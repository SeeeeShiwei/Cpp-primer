//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.13 partition算法_谓词划分不同长度单词，输出长度大于等于5的单词
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

bool more_than5(const string s1)
{
    return s1.size() >= 5;
}


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};

    auto end_pos = partition(words.begin(), words.end(), more_than5);
    cout << "长度大于等5的单词"<< endl;
    for(auto i = words.begin(); i < end_pos; i++)
    {
    	cout << *i << " ";
    }

	return 0;
}

/*
 * 输出：
 * 长度大于等5的单词
   turtle quick
 */
