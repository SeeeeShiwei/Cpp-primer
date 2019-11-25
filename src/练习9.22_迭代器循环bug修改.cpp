//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.21
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
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    int someval = 3;
    iter start = nums.begin(), mid = nums.begin() + nums.size() / 2;
    while(start != mid)
    {
    	if (*start == someval)
    		nums.insert(start,2*someval);
    	start++;
    }
    for(auto num : nums)
    	cout << num << " ";
	return 0;
}

