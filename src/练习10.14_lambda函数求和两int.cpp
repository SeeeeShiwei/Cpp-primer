//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.14 lambda函数求和两int
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {
	int a = 1;
	int b = 4;

	auto sum = [] (int int1, int int2) {return int1 + int2;};
	cout << sum(a,b) << endl;

	return 0;
}

