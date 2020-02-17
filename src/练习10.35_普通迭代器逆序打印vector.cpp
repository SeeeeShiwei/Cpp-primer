//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.35 普通迭代器逆序打印vector
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;



int main() {
	vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto c_iter = nums.cbegin(); c_iter != nums.cend(); c_iter++)
    {
    	cout << *c_iter << " "; // 1 2 3 4 5 6 7 8 9
    }

	return 0;
}
