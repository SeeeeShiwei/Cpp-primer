//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.42 reserve预先分配
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

    string s;
    char temp;
    s.reserve(100);
    while(cin >> temp){
    	s.push_back(temp);
    }
    cout << s.capacity() << endl;

}

/*
 输出：
100
 */
