//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.3 accumulate求vector<int>元素之和
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {
	vector<double> nums{1,3,4,1,3,2,1};
	auto sum = accumulate(nums.cbegin(), nums.cend(),0); // accumulate求和函数：（首迭代器，尾迭代器，求和结果初始值）
	cout << sum << endl;


	return 0;
}
