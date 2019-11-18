//============================================================================
// Name        : booksotre_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习7.41
// 重点：理解委托构造函数执行顺序
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Sales_data
{
friend istream &read(istream&, Sales_data&);
public:
//	//原始构造函数
//	Sales_data() = default;
//	Sales_data(const string &s): bookno(s) {};
//	Sales_data(const string &s, unsigned n, double p):
//		bookno(s),units_sold(n),total_money(p*n) {};
//	Sales_data(istream&);

	//委托构造函数
	Sales_data(const string &s, unsigned n, double p):
			bookno(s),units_sold(n),total_money(p*n) {
		cout << "三参数构造函数" << endl;
	}
	Sales_data():Sales_data(" ", 0, 0) {
        cout << "无参数构造函数委托三参数构造函数" << endl;
	}
	Sales_data(string s): Sales_data(s, 0, 0){
		cout << "一参数构造函数委托三参数构造函数" << endl;
	}
	Sales_data(istream &is): Sales_data() {
		cout << "cin构造函数委托无参数构造函数" << endl;
        read(is, *this);
	}

    Sales_data &combine(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        total_money += rhs.total_money;
        return *this;
    }
    string isbn() const  {return bookno;}


//私有访问说明符，类内数据成员和实现部分函数
private:
	double avg_price() const;
	string bookno;
    unsigned units_sold = 0;
    double total_money = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
    double price;
	is >> item.bookno >> item.units_sold >> price;
	item.total_money = price * item.units_sold;
	return is;
}

int main() {
	Sales_data test0;
    Sales_data test1("santi");
    Sales_data testcin(cin);
    Sales_data test3("santi",3,40.0);
	return 0;
}
//输出
/*
三参数构造函数
无参数构造函数委托三参数构造函数

三参数构造函数
一参数构造函数委托三参数构造函数

三参数构造函数
无参数构造函数委托三参数构造函数
cin构造函数委托无参数构造函数
 */
