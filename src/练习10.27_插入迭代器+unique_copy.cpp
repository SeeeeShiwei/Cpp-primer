//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.27 插入迭代器+unique_copy
//               插入迭代器三种：back_inserter(创建使用push_back的迭代器)
//                             front_inserter(创建使用push_front的迭代器)
//                             inserter(创建使用insert的迭代器，接受两个参数) 
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;


int main() {
	vector<int> nums{1, 1, 5, 6, 9, 1, 3,5};
	list<int> list_num;
    // 将nums中不重复的元素拷贝到list中
	// unique：删除”所有相邻的重复元素”；unique_copy:去除重复元素再执行copy运算
	sort(nums.begin(), nums.end());
	unique_copy(nums.begin(), nums.end(), inserter(list_num,list_num.begin()));
	for(auto num : list_num)
	{
		cout << num << " ";  // 1 3 5 6 9
	}
	return 0;
}
