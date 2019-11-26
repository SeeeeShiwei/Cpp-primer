//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.27 查找并删除单向链表奇数元素
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
using namespace std;




int main()
{

	forward_list<int> listNode{0,1,3,4,5,8,9,11};
    auto pre = listNode.before_begin(); //pre指向链表头节点的前一个迭代器，“首前元素”
    auto cur = listNode.begin();

    while(cur != listNode.end())
    {
    	if (*cur % 2 != 0)
    	{
    		cur = listNode.erase_after(pre); // 奇数元素时，删除当前节点，并返回下一个待遍历的节点
    	}
    	else
    	{
    		pre = cur; // 偶数元素，pre向后移动
    		cur ++;
    	}
    }

    //从vector中删除偶数元素 , 从list中删除奇数元素

    for(auto num:listNode)
    	cout << num << " ";

	return 0;
}

/*
 输出：
0 4 8
 */
