//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.23 头尾迭代器与front/back头尾元素引用
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
using namespace std;

using iter = vector<int>::iterator;


int main()
{
    vector<int> nums{0};
    if(!nums.empty())
    {
    	auto val1 = *nums.begin(), val2 = nums.front(); //val1头元素迭代器解引用，val2头元素引用
    	auto last = nums.end();
    	auto val3 = *(--last), val4 = nums.back();
    	cout << val1 << " " << val2 << " " << val3 << " " << val4;
    }

	return 0;
}

/*
 输出：0 0 0 0
 */
