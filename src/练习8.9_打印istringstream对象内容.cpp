//============================================================================
// Name        : IOtest.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.9：打印一个istringstream对象的内容
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
	string test = "This is a big deal!";
    //构建字符串输入流对象
	istringstream input_str(test);
	readData(input_str);
	return 0;
}

