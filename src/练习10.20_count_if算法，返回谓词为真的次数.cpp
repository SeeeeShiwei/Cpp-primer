//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.20 count_if算法，返回谓词为真的次数
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {
	vector<string> words{"the","quick","red","fox","jump","over","the","slow",
		"red","turtle"};
	vector<string>::size_type sz = 3;
	// 使用count_if统计长度超过3的单词数
	auto num = count_if(words.begin(), words.end(), [sz] (string word) {return word.size() > sz;});
    cout << num << endl;
	return 0;
}
