//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.18 编写程序，从标准输入读取string序列，存入一个deque中。编写循环，使用迭代器打印deque中的元素。
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
using namespace std;

using iter = deque<string>::iterator;


int main() {
	string str;
	deque<string> str_deque;
	while (cin >> str)
	{
		str_deque.push_back(str);
	}

	// 迭代器循环输出
	iter start = str_deque.begin();
	iter end = str_deque.end();
	while(start != end)
	{
		cout << *start << endl; //迭代器解引用，得指代得值
		start++;
	}

	//索引循环输出
	for(int i = 0; i != int(str_deque.size());i++)
	{
		cout << str_deque[i]<<endl;
	}

	return 0;
}
