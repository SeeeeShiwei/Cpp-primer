//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.26  单迭代器版本erase删除vector和list
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
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
//    vector<int> vec_num;  //vector数组
//    list<int> list_num; //链表
//    for (int i = 0; i < sizeof(ia)/sizeof(ia[0]);i++) // ia数组无size()成员函数，使用sizeof求数组大小
//    {
//    	vec_num.push_back(ia[i]);
//    	list_num.push_back(ia[i]);
//    }
    //或
    vector<int> vec_num(ia,ia + sizeof(ia)/sizeof(ia[0]));  //vector数组
    list<int> list_num(ia,ia + sizeof(ia)/sizeof(ia[0])); //链表

    //从vector中删除偶数元素 , 从list中删除奇数元素
    auto vec_start = vec_num.begin();
    auto list_start = list_num.begin();
    while(vec_start != vec_num.end())
    {
    	if (*vec_start % 2 == 0)
    	{
    		vec_start = vec_num.erase(vec_start); //注意此处，erase成员函数返回删除迭代器指向元素的下一个元素
    		list_start++;
    	}
    	else
    	{
    		vec_start++;
    		list_start = list_num.erase(list_start);
    	}
    }


    for(auto num:vec_num)
    	cout << num << " ";
    cout << endl;
    for (auto list : list_num)
    	cout << list << " ";

	return 0;
}

/*
 输出：
1 1 3 5 13 21 55 89
0 2 8
 */
