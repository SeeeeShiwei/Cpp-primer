//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.19 编写程序，从标准输入读取string序列，存入一个list中。编写循环，使用迭代器打印list中的元素。
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
using namespace std;

using iter = list<string>::iterator;


int main() {
	string str;
	list<string> str_list;
	while (cin >> str)
	{
		str_list.push_back(str);
	}

	// 迭代器循环输出
	iter start = str_list.begin();
	iter end = str_list.end();
	while(start != end)
	{
		cout << *start << endl; //迭代器解引用，得指代得值
		start++;
	}

//	//list对象无法使用索引循环输出
//	for(int i = 0; i != int(str_list.size());i++)
//	{
//		cout << str_list[i]<<endl;
//	}

	return 0;
}
