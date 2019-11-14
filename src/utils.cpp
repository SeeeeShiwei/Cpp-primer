/*
 * utils.cpp
 *
 *  Created on: 2019年10月31日
 *      Author: 石威（Sesen）
 */

#include "Sales_data_v0.2.h"
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price;
	is >> item.bookno >> item.units_sold >> price;
	item.total_money = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << "书名： " << item.isbn() << " 售出数量： " << item.units_sold <<
    		" 销售总额： " << item.total_money << " 售出单价:" << item.avg_price();
    return os;
}
Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

ostream &showInformation(ostream &os, const Person &item)
{
    os << "姓名：" << item.GetName() << " 现居地址:" <<item.GetAdress();
    return os;
}

