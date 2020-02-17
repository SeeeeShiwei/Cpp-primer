//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.28 插入迭代器应用
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void display(list<int> list_num)
{
	for(auto num : list_num)
	{
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> list_num1; //双向链表
	list<int> list_num2;
	list<int> list_num3;

	copy(nums.begin(), nums.end(), back_inserter(list_num1)); // 1-9
	copy(nums.begin(), nums.end(), front_inserter(list_num2)); // 9-1
	copy(nums.begin(), nums.end(), inserter(list_num3,list_num3.begin())); // 1-9

	display(list_num1);
	display(list_num2);
	display(list_num3);


	return 0;
}
