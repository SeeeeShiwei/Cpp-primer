//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.28 编写函数，接受一个单向forward_list<string和stringA，stringB三个参数，在链表中查找
//               stringA，并将stringB插入其后；若链表不含有stringA，则将stringB插入链表尾部。
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
using namespace std;

void process(forward_list<string> &list_str, string strA, string strB)
{
	int count = 0;
	auto cur = list_str.begin();
	while(cur != list_str.end())
	{
    	if (*cur == strA)
    		{count++;
	    	cur = list_str.insert_after(cur,strB);} // 在cur后插入stringB字符串，并返回指向最后一个插入元素的迭代
	    cur++;
	}

	//  若不含strA，则将strB插入链表尾部
//	cout << count << endl;
	if(count == 0)
	{
		auto pre = list_str.begin();
		auto it = list_str.begin();
		while(1)
		{
			pre = it++;
			if(it == list_str.end())
			{
				break;
			}
		}
		list_str.insert_after(pre,strB);
	}
}

int main()
{

	forward_list<string> list_str1 = {"AA","CC","DD","AA"};
	forward_list<string> list_str2 = {"CC","DD"};
    string stringA = "AA";
    string stringB = "BB";

    process(list_str1,stringA,stringB);
    process(list_str2,stringA,stringB);



    //从vector中删除偶数元素 , 从list中删除奇数元素

    for(auto str:list_str1)
    	cout << str << " ";
    cout << endl;
    for(auto str:list_str2)
    	cout << str << " ";

	return 0;
}

/*
 输出：
AA BB CC DD AA BB
CC DD BB
 */
