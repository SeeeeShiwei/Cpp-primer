//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.22 bind绑定函数代替lambda
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <functional>

using namespace std;
using namespace placeholders;

bool check_size(const string word, const vector<string>::size_type sz)
{
	return word.size() > sz;
}


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};
	vector<string>::size_type sz = 3;
	// 使用count_if统计长度超过3的单词数
	auto num = count_if(words.begin(), words.end(), bind(check_size,_1,sz));
	//等价于
//	auto num = count_if(words.begin(), words.end(),[sz] (const string word){return word.size() > sz;});
    cout << num << endl;
	return 0;
}
