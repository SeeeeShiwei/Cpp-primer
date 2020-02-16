//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.21 lambda递减捕获变量值
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {

	int num = 3;
	auto f = [&num] {return num > 0;};
	while(f())
	{
		num--;
	}
	cout << num << endl;
	return 0;
}
