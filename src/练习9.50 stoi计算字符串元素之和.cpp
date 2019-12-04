//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.50 stoi计算字符串元素之和
//============================================================================

#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>

using namespace std;

using iter = string::iterator;

int calculateSum(vector<string> strings)
{
    int res = 0; // 必须初始化
    for (auto string : strings)
    {
    	int temp = stoi(string);
//    	cout << temp<<endl;
    	res += temp;
    }
    return res;

}


int main()
{
	vector<string> vec{"12","23","1"}; // {}而不是（）
	int ans;
	ans = calculateSum(vec);
	cout << ans;
    return 0;
}

/*
输出：
36
 */

