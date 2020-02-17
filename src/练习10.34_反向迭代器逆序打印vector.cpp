//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.34 反向迭代器逆序打印vector
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;



int main() {
	vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto r_iter = nums.crbegin(); r_iter != nums.crend(); r_iter++)
    {
    	cout << *r_iter << " "; // 9 8 7 6 5 4 3 2 1
    }

	return 0;
}
