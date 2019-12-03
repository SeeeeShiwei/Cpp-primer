//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.43 迭代器替换string中单词
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>

using namespace std;

using iter = string::iterator;

void replaceStr(string &s, string oldVal, string newVal)
{
    if (s.size() == 0){
        cerr << "S 不能为空";
    }
    else
    {
    	auto start = s.begin();
    	auto len = oldVal.size();
    	while(start <= s.end() - oldVal.size())
    	{
    		if(string(start, start+len) == oldVal)
    		{
    			start = s.erase(start,start + len); // string erase函数，iterator erase(const_iterator first, const_iterator last)
    			start = s.insert(start, newVal.cbegin(), newVal.cend()); // 插入迭代器首尾位置
    			start += newVal.size();
    		}
    		else start += 1;
    	}

    }

}


int main()
{
	string s = "What do I discover thotho? It looks as tho it might clear up tho.";
	string oldVal = "tho";
	string newVal = "though";
    replaceStr(s,oldVal, newVal);
    cout << s << endl;

    //以下字符串用于测试函数能否正确地替换最后一个字符
    string ss("who I am?");
    cout << "原string：" << ss << "\n替换后为：";
    replaceStr(ss, "?", "...");
    cout << ss << endl;

    return 0;
}

/*
输出:
What do I discover thoughthough? It looks as though it might clear up though.
原string：who I am?
替换后为：who I am...
*/
