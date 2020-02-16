//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.24 bind绑定函数统计
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(int num, string s)
{
	return num > s.size();
}


int main() {
	vector<int> nums{1, 1, 5, 6, 9, 1,3};
	string s{"family"};
	// 使用count_if统计长度超过3的单词数
	auto value = find_if(nums.begin(), nums.end(), bind(check_size,_1,s));
    cout << *value << endl;

	return 0;
}




