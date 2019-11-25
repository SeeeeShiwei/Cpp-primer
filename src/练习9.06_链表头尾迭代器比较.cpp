//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.6 list为双向链表，不可比较头尾迭代器大小，可比较是否相等。
//============================================================================

#include <iostream>
#include <vector>
#include <list>
using namespace std;

using iter = list<int>::iterator;


int main() {
	list<int> lst1;
	iter iter1 = lst1.begin(),iter2 = lst1.end();
//	while(iter1 < iter2)  // wrong
	while(iter1 != iter2) // list保存地址不是连续的，不能比较迭代器地址大小
	{
		cout << 0 << endl;
	}

	return 0;
}
