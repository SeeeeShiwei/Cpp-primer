//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.20 从链表list<int>中拷贝奇偶元素到不同deque中。
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
    vector<int> nums{5};
    int num;
    iter cur = nums.begin();
    while (cin >> num)
    	cur = nums.insert(cur, num); //相当于一直在nums头部插入值，insert返回指向新插入元素的迭代器
    for(auto num : nums){
    	cout << num << " ";
    }


	return 0;
}

/*
 输入：1 2 3 4
 输出：4 3 2 1 5 
 */
