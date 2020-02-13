//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.15 lambda函数求和两int(捕获列表)
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {
	int fix_int = 1;
	int b = 4;

	auto sum = [fix_int] (int var) {return fix_int + var;};
	cout << sum(b) << endl;

	return 0;
}

