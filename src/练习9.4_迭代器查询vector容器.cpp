//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.4  使用迭代器，在vector数组中查找target是否存在。返回bool值。
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

bool find_target(vector<int> &nums, int target)
{
	bool res = false;
	for(auto iter = nums.begin();iter < nums.end();iter++)
	{
        if(*iter == target) // 迭代器解引用
        {
        	res = true;
        	return res;
        }
	}
	return res;
}
int main() {
	vector<int> nums = {1,23,45,2,123,34,45};
	int target = 2;
	bool ans = find_target(nums,target);
	cout << boolalpha << ans << endl; // 输出bool值，而非0-1.
	return 0;
}
