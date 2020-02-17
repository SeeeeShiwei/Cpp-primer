//============================================================================
// Name        : GenerticAlgorithm.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习10.36 反向迭代器find最后一个0元素
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;



int main() {
	vector<int> nums{0, 2, 0, 4, 0, 6, 0, 8, 9};
    auto iter = find(nums.crbegin(), nums.crend(), 0);
    cout << *iter << endl;  // 0
    cout << *iter.base() << endl; // 转为普通迭代器  8

    string line{"F I R S T, M I D D L E, L A S T"};
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << *comma << endl;  // ,
    cout << string(line.cbegin(), comma) << endl;  // F I R S T

    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << *rcomma << " " << *rcomma.base() << endl; // , 空格
    cout << string(rcomma.base(), line.cend()) << endl; //  L A S T


	return 0;
}
