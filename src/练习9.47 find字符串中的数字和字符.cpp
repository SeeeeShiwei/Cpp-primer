//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.47 find字符串中的数字和字符
//============================================================================

#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>

using namespace std;

using iter = string::iterator;

string findNumStr(string &s, const string standard)
{
    string res;
	if (s.size() == 0){
        cerr << "s 不能为空";
    }
    else
    {
    	// find_first_of版本
    	string::size_type pos = 0;
    	while((pos = s.find_first_of(standard, pos)) != string::npos)
    	{
    		res += s[pos];
    		pos++;
    	}

    }
	return res;

}


int main()
{
	string readystr = "J2H3df6sd5";
	string nums = "1234567890";
	string alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string numsOfstr, alphasOfstr;
    //查找数字
	numsOfstr = findNumStr(readystr, nums);
    cout << numsOfstr << endl;
    //查找字母
    alphasOfstr = findNumStr(readystr, alphas);
    cout << alphasOfstr << endl;

    return 0;
}

/*
 *输出
 2365
JHdfsd
 */

