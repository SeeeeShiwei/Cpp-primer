//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.47 读入单词文件，最长符合要求单词
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

bool findLongestStr(string s, const string standard)
{
    string res;
	if (s.size() == 0){
        cerr << "word 为空";
    }
    else
    {
    	// find_first_of版本
    	string::size_type pos = 0;
    	while((pos = s.find_first_of(standard, pos)) != string::npos)
    	{
    		return false;
    	}

    }
	return true;

}


int main()
{
	string up_down_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZbdfghijklpqty";
    string wordfile = "words.txt";
    ifstream openfile(wordfile);
    string word;
    int temp = 0;
    string longeststr;
    while(!openfile.eof())
    {
    	getline(openfile, word);
    	if (findLongestStr(word, up_down_str))
    	{
    		if (temp < int(word.size()))
    		{
    			temp = int(word.size());
    			longeststr = word;

    		}
    	}
    }

    cout << "单词文件中最长的单词为： " << longeststr;
    return 0;
}

/*
单词文件：
am
a
students
excuse
me
passwd
computer
seseneeeee
really
yellow
write

输出：
单词文件中最长的单词为： seseneeeee
 */

