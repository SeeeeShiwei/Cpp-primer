/*
 * Sales_data.h
 *
 *  Created on: 2019年10月31日
 *      Author: 石威（Sesen）
 */

#ifndef SALES_DATA_V0_2_H_
#define SALES_DATA_V0_2_H_

#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
// 为Sales_data的非成员函数做友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&,const Sales_data&);
//访问说明符
public:
	//构造函数
	Sales_data() = default;
	Sales_data(const string &s): bookno(s) {};
	Sales_data(const string &s, unsigned n, double p):
		bookno(s),units_sold(n),total_money(p*n) {};
	Sales_data(istream&);

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

//Sales_data接口的非成员函数声明，定义在utils.cpp中，因声明了友元函数，所以可以使用private成员
Sales_data add(const Sales_data&, const Sales_data&);
istream &read(istream&, Sales_data&);
ostream &print(ostream&,const Sales_data&);


inline
double Sales_data::avg_price() const
{
	return units_sold ? total_money / units_sold : 0;
}


#endif /* SALES_DATA_V0_2_H_ */
