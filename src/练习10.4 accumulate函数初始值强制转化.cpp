//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.4 accumulate函数初始值强制转化
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {
	vector<double> nums{1.1,3.2,4.3,1.5,3,2,1};
	// accumulate求和函数：（首迭代器，尾迭代器，求和结果初始值）
	// 初始值为int 0 时，vector中的double类型值会强制转换为int
	auto sum = accumulate(nums.cbegin(), nums.cend(),0);

	cout << sum << endl;


	return 0;
}
