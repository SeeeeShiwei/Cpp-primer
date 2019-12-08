//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.1-10.2 count元素出现次数
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
	vector<int> nums{1,2,3,4,1,3,2,1};
	int n;
	n = count(nums.cbegin(), nums.cend(),1); // count函数接收待统计迭代器范围和待计数元素
	cout << n << endl;

	list<string> strs;
	string word;
	while(cin >> word)
	{
		strs.push_back(word);
	}
	cout << count(strs.cbegin(), strs.cend(),"abc") << endl;
	return 0;
}
