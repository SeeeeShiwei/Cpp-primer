//============================================================================
// Name        : IOtest.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.10：istringstream Record对象定义在循环内和循环外，strm.str(s)将string s拷贝到strm中
//============================================================================


#include<fstream>
#include<vector>
#include<iostream>
#include<sstream>
#include <string>
using namespace std;

/*
 * 从标准输入读取人员联系方式，并存入电话本
 */

struct PersonInfo
{
	string name;
    vector<string> phones;
};

ostream &print(ostream &os, PersonInfo &items)
{
	os << items.name << " ";
	for (auto phone : items.phones)
		os << phone << " ";
	return os;
}

int main()
{
    vector<PersonInfo> people; // 联系人
	string line,phone_num; // 标准输入每行记录,电话号码
    PersonInfo info; // 人员

    istringstream Record;
    while(getline(cin,line))
    {
//        istringstream Record(line);
    	Record.clear();
    	Record.str(line); // 将line拷贝到Record中
        Record >> info.name;
        while(Record >> phone_num)
        {
        	info.phones.push_back(phone_num);
        }
        people.push_back(info);
        info.phones.clear();
    }

    // 存入电话本
    string phone_Note = "phone_Note.txt";
    ofstream file_write(phone_Note); // 建立写入流，并打开文件
    for (auto line : people)
    {
    	print(file_write, line)  <<  endl;
    }

    return 0;
}
