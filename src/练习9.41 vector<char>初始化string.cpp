//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.41 vector<char>初始化string
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
using namespace std;




int main()
{
    vector<char> vec{'a','b','c','d','e'};
    string s(vec.data(), vec.size());
    cout << s << endl;

}

/*
 输出：
abcde
 */
