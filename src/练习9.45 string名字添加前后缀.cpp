//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.45 迭代器insert-append-string名字添加前后缀
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>

using namespace std;

using iter = string::iterator;

void combine_pre_suffix(string &name, const string prefix, const string suffix)
{
    if (name.size() == 0){
        cerr << "name 不能为空";
    }
    else
    {
    	iter start = name.begin();
        name.insert(start, prefix.cbegin(), prefix.cend());
//        iter end = name.end();
        name.append(suffix);
    }

}


int main()
{
	string name = "Jerry";
	string prefix = "Ms.";
	string suffix = "III";

    combine_pre_suffix(name , prefix, suffix);
    cout << name << endl;

    return 0;
}

/*
输出：
Ms.JerryIII
*/
