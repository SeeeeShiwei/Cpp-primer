//============================================================================
// Name        : IO_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.1：接收一个istream&参数，返回值类型为istream&
//============================================================================

#include <iostream>
using namespace std;

istream &readData(istream &is)
{
    int temp;
    while(is >> temp || !is.eof())
    {
    	if(is.eof()){
    		cout << "EOF,到达文件结尾" << endl;
    	}

    	if(is.bad())
    	{
    		throw runtime_error("IO口发生系统及错误");
    	}

    	if(is.fail())
    	{
    		cout << "格式错误，请输入一个整数" << endl;
    		is.clear(); // 使输入流cin有效
    		is.ignore(100,'\n'); //清除数据流中错误的输入内容
    		continue;
    	}
    	cout << temp << endl;

    }
    return is;
}

int main() {
	cout << "请输入一个整形数据" << endl;
	readData(cin);
	return 0;
}

