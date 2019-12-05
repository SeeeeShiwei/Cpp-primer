//============================================================================
// Name        : Sequential_Container.cpp
// Author      : Seseneee
// Version     :
// Copyright   : Your copyright notice
// Description : 练习9.51 构建处理不同格式年月日类
//============================================================================

#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
#include<map>
using namespace std;


class solveDate
{
public:
	// 定义构造函数
	solveDate(const string &datestr){
	 // explicit关键字不接受隐式转换,
	 //此构造函数需要处理各种格式的日期输入，无构造函数初始值列表，需经处理输出

		if(datemap.empty())
		{
			initMap();
	    }
		// 检测格式是否正确
		if(!checkFormat(datestr))
		{
			errorInit();  // 格式不正确时，全部置为1970/1/1.
			return;
		}

		// 拆分输入日期字符串
		string yearstr = datestr.substr(0,datestr.find_first_of(", /")); // substr(pos,n) pos位置开始，拷贝n个字符
		string monthstr = datestr.substr(datestr.find_first_of(", /")+1,
				datestr.find_last_of(", /") - (datestr.find_first_of(", /") +1));
		string daystr = datestr.substr(datestr.find_last_of(", /")+1, datestr.size()); //超出部分，取到字符串结尾即可

//		cout << monthstr << endl;
		// 判断输入日期是否符合要求
		if(!tryToInit({yearstr, monthstr, daystr}))
		{
			errorInit();
		}
		cout << "year: " <<  year << endl;
		cout << "month: " << month << endl;
		cout << "day:" << day << endl;
	}



private:

	bool checkFormat(const string &datestr)
		{
			if(datestr.empty())  // 输入字符串为空
				return false;
			if(datestr.find_first_of(", /") == string::npos)  // 输入字符串无空格，逗号或分号隔开
				return false;
			if(datestr.find_first_of(", /") == datestr.size()) // 输入字符串以空格，逗号或分号结尾
				return false;
			if(datestr.find_first_of(", /") == datestr.find_last_of(", /"))  //输入字符串空格，逗号或分号数为1
				return false;
			return true;
		}

	void errorInit()
	{
		year = 1970;
		month = 1;
		day = 1;
	}

	bool tryToInit(const vector<string> &data)
	{
		try
		{
			year = stoul(data[0]);  // year字符串转unsigned long，数值转换
			day = stoul(data[2]);
		}catch(invalid_argument &error) // 非法参数异常
		{
			return false;
		}


		try
		{
			month = stoul(data[1]);
		}catch(invalid_argument & error)  // 若catch的参数异常，通过哈希表，将英文月份转为unsigned long类型
		{
			// try 块在不同的情境下会抛出不同的异常，这个时候可以尝试罗列多个 catch 语句，用于捕获不同类型的异常。
			if(datemap.find(data[1]) == datemap.end())
			{
				cout << data[1] << endl;
				return false;
			}

			month = datemap[data[1]];
		}

		return checkDate();  // 年月日均转成了unsigned类型，再检查是否符合范围。
	}

	//cheakYear 检测闰年
	bool checkYear(unsigned year)//检测闰年
	{
		 return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? true : false;
	}


	bool checkDate()
	{
		if(year > 10000 || month > 12 || day > 31)
		{
			cout << "year 应小于10000， 月份不超过12， 日期不超过31天。" << endl;
			return false;
		}


		if (month==4 || month == 6 || month == 9 || month == 11)
		{
			if(day > 30)
			{
				cout << "4,6,9,11月每月最多30天。" << endl;
				return false;
			}

		}

		if(month == 2)
		{
			if(checkYear(year) && day > 29)
				return false;
			if (!checkYear(year) && day > 28)
				return false;
		}

		return true;
	}


	unsigned year;
	unsigned month;
	unsigned day;
	static void initMap(); // static必须在类内声明，在类外定义  ； static静态成员变量不属于类的任何一个对象，一旦被定义，就将一直存在于程序的整个生命周期中
	static map<string,unsigned> datemap;
};



map<string,unsigned> solveDate::datemap;
void solveDate::initMap()
{
	datemap.insert(make_pair<string,unsigned>("January",1));
	datemap.insert(make_pair<string,unsigned>("Jan",1));
	datemap.insert(make_pair<string,unsigned>("February",2));
	datemap.insert(make_pair<string,unsigned>("Feb",2));
	datemap.insert(make_pair<string,unsigned>("March",3));
	datemap.insert(make_pair<string,unsigned>("Mar",3));
	datemap.insert(make_pair<string,unsigned>("April",4));
	datemap.insert(make_pair<string,unsigned>("Apr",4));
	datemap.insert(make_pair<string,unsigned>("May",5));
	datemap.insert(make_pair<string,unsigned>("June",6));
	datemap.insert(make_pair<string,unsigned>("Jun",6));
	datemap.insert(make_pair<string,unsigned>("July",7));
	datemap.insert(make_pair<string,unsigned>("Jul",7));
	datemap.insert(make_pair<string,unsigned>("August",8));
	datemap.insert(make_pair<string,unsigned>("Aug",8));
	datemap.insert(make_pair<string,unsigned>("September",9));
	datemap.insert(make_pair<string,unsigned>("Sep",9));
	datemap.insert(make_pair<string,unsigned>("October",10));
	datemap.insert(make_pair<string,unsigned>("Oct",10));
	datemap.insert(make_pair<string,unsigned>("November",11));
	datemap.insert(make_pair<string,unsigned>("Nov",11));
	datemap.insert(make_pair<string,unsigned>("December",12));
	datemap.insert(make_pair<string,unsigned>("Dec",12));
}


int main()
{

	cout << "请依次输入年月日，三者之间请使用空格，逗号或斜线隔开" << endl;
	string datestr("2000,4,31");
	solveDate date(datestr);
	string s;

//	while(cin >> s)
//	{
//		solveDate mydate(s);
//	}


    return 0;
}

