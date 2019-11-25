//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.4  使用迭代器，在vector数组中查找target是否存在，返回一个迭代器指向查询到的元素。若没有，则返回
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

using iter = vector<int>::iterator;

iter find_target(iter left,iter right,int target) // 返回一个迭代器
{


	while(left != right)
	{
        try
        {
			if(*left == target) // 迭代器解引用
			{
				return left;
			}
			else left++;

			if(left == right)
				throw runtime_error("No target");
        }
        catch(runtime_error err)
        {
        	cout << err.what() << endl;
        }
	}
	return right;
}
int main() {
	vector<int> nums = {1,23,45,2,123,34,16};
	int target = 45;
	 /*返回目标的下标*/
	auto i = nums.begin();
	auto res = find_target(nums.begin(),nums.end(),target) - i;
	if(res == nums.size())
		return 0;
	cout << "目标在数组中的index索引为：" << res << endl;
	return 0;
}
