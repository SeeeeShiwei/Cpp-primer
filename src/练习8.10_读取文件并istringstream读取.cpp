//============================================================================
// Name        : IOtest.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.10：编写程序，将文件行保存vector<string>中，再使用istringstream对象从vector中读取数据元素
//               a每次读取一个单词
//============================================================================


#include<fstream>
#include<vector>
#include<iostream>
#include<sstream>
#include <string>
using namespace std;


istream &readData(istream &is)
{
	string temp;
	while(is >> temp || !is.eof())
	{
		if(is.bad())
     		//cout << "IO系统级错误" << endl;
			throw runtime_error("IO口发生系统及错误");
		if(is.fail())
		{
			cout << "输入类型错误，请输入string字符串类型" << endl;
			is.clear(); // 使输入流cin/istringstream有效
			is.ignore(100,'\n');
			continue;
		}
		cout << temp << endl;
	}
	return is;
}


int main()
{
    string infile = "soldbook.txt";
    ifstream openfile(infile); // 文件输入流，读入文件内容
    string line;
    vector<string> line_stack;
    while(!openfile.eof())
    {
    	getline(openfile,line);
    	line_stack.push_back(line);
    }

	for (auto l : line_stack)
	{
		istringstream input_str(l); // 字符串输入流，读入字符串
		readData(input_str);
	}
	return 0;
}

/*
 * 输入
撒哈拉沙漠  3  25.0
撒哈拉沙漠 5 20.0
百面机器学习 2 40.0
Linux从入门到放弃 2 89.0
数据结构 4 56.0
百面机器学习 1 30.0
 */

/*
 * 输出
 撒哈拉沙漠
3
25.0
撒哈拉沙漠
5
20.0
百面机器学习
2
40.0
Linux从入门到放弃
2
89.0
数据结构
4
56.0
百面机器学习
1
30.0
 */

