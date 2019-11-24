//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.13 类型不同，需用迭代器范围来初始化
//============================================================================

#include <iostream>
#include <vector>
#include <list>
using namespace std;

using iter = list<int>::iterator;


int main() {
	list<int> bilist{1,2,3};
	vector<int> vec{4,5,6};
	vector<double> vec1(bilist.begin(), bilist.end());
	vector<double> vec2(vec.begin(), vec.end());


	cout << vec1[2] << endl;
	cout << vec2[2] << endl;


	return 0;
}
