//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.37 反向迭代器逆向拷贝
//               给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;



int main() {
	vector<int> nums{0,1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int> list_num(5,0); // 必须初始化，未用插入迭代器
    reverse_copy(nums.cbegin()+3, nums.cbegin()+8, list_num.begin());
    for(auto &num : list_num)
    {
    	cout << num << " "; // 7 6 5 4 3
    }
    cout << endl;

	list<int> list_num0; // 无需初始化，用到了插入迭代器
    reverse_copy(nums.cbegin()+3, nums.cbegin()+8, back_inserter(list_num0));
    for(auto &num : list_num0)
    {
    	cout << num << " "; // 7 6 5 4 3
    }
    cout << endl;


    list<int> list_num1; // 无需初始化
    copy(nums.crbegin()+2, nums.crend()-3, back_inserter(list_num1));
    for(auto &num : list_num1)
    {
    	cout << num << " "; // 7 6 5 4 3
    }

	return 0;
}

