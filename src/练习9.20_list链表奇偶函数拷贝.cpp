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

using iter = list<int>::iterator;


int main()
{
    list<int> nums{1,2,3,4,5,6,7,8,9,0};
    deque<int> oddNums, evenNums;
    iter start = nums.begin();
    while (start != nums.end())
    {
    	if (*start % 2 == 0)
    		evenNums.push_back(*start);
    	else oddNums.push_back(*start);
    	start++;
    }

    cout << "输出偶数元素：" << endl;
    for(auto num : evenNums)
    	cout << num << " ";
    cout << endl;

    cout << "输出奇数元素：" << endl;
    for(auto num : oddNums){
    	cout << num << " ";}
	return 0;
}

/*
输出偶数元素：
2 4 6 8 0
输出奇数元素：
1 3 5 7 9
 * /
