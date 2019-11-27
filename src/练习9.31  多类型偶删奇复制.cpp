//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.31 编写函数，完成list/forward_list及其他类型如vector，deque删除偶数值元素，
//               复制奇数值元素
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
using namespace std;


void verify_bilist(list<int> &nums)
{
    auto iter = nums.begin();
    while(iter != nums.end())
    {
    	if (*iter % 2)
    	{
    		iter = nums.insert(iter,*iter);
    		++iter;
    		++iter;
    	}
    	else
    		iter = nums.erase(iter);
    }
}

void verify_flist(forward_list<int> &nums)
{
	auto pre = nums.before_begin();
	auto iter = nums.begin();

	while (iter != nums.end())
	{
		if (*iter%2)
		{
			iter = nums.insert_after(iter,*iter);
			pre = iter;
			++iter;
		}
		else
		{
			iter = nums.erase_after(pre);
		}
	}

}

int main()
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    auto iter = vec.begin();
    while (iter!=vec.end())
    {
    	if (*iter % 2)
    	{
    		iter = vec.insert(iter,*iter); //在iter之前插入，返回新插入元素的迭代器
    		iter += 2;
    	}
    	else
    	{
    	    iter = vec.erase(iter); //删除当前元素，指向删除元素下一个元素迭代器
    	}
    }
    cout << "处理后的vector数组为： ";
    for (auto num:vec)
    	cout << num << "  ";
    cout << endl;

    // 上述代码不适合于list：因为list不支持+操作，即不支持iter += 2，链表存放位置不连续。
    list<int> list_nums{0,1,2,3,4,5,6,7,8,9};
    verify_bilist(list_nums);

    // 上述代码不适合forward_list:因为单向链表不支持insert和erase，仅支持insert_after和erase_after
    forward_list<int> flist_nums{0,1,2,3,4,5,6,7,8,9};
    verify_flist(flist_nums);
    cout << "处理后的list链表为： ";
    for(auto num:list_nums)
    	cout << num << "  ";
    cout << endl;

    cout << "处理后的forward_list单向链表为： ";
    for(auto num : flist_nums)
    	{
    	cout << num << "  ";
    	}

	return 0;
}

/*
 输出：
处理后的vector数组为： 1  1  3  3  5  5  7  7  9  9
处理后的list链表为： 1  1  3  3  5  5  7  7  9  9
处理后的forward_list单向链表为： 1  1  3  3  5  5  7  7  9  9
 */
