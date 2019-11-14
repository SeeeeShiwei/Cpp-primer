//============================================================================
// Name        : bookstore_v0.2.cpp
// Author      : shiwei
// Version     : v0.2
// Copyright   : Your copyright notice
// Description : P240 第七章以后的bookstore程序
//============================================================================

#include <iostream>
#include <string>
using namespace std;
#include "Sales_data_v0.2.h"
#include "Person.h"
#include "Screen.h"

class X;
class Y; // 前向声明

class X{
public:
    X() = default; //构造函数
    void print(ostream &os)
    {
    	os << "I am X";
    }
//private:
    Y *p; //定义指向Y的指针;Y仅仅声明，未定义，则此处为不完全类型
};


class Y{
public:
	Y() = default;
    void print(ostream &os)
    {
    	os << "I am Y";
    }
//private:
    X a;
};

int main()
{
//    //练习7.21
//	//调用第一种构造函数
//	Sales_data book1;
//	print(cout,book1) << endl;
//
//	//调用第二种构造函数
//	Sales_data book2("撒哈拉的故事");
//	print(cout,book2) << endl;
//
//	//调用第三构造函数
//	Sales_data A("as",2,30.0), B("as",3,20.0);
//    print(cout,A.combine(B)) << endl;
//
//
//    //调用第四种构造函数
//    Sales_data book4(cin),book5(cin);
//    if(book4.isbn() == book5.isbn())
//    {
//        print(cout,add(book4, book5)) << endl;
//    }
//    else
//    {
//    	print(cout,book4) << endl;
//       	print(cout,book5) << endl;
//    }
//
//	// 练习7.22
//    Person C("shiwei","hangzhou");
//    showInformation(cout,C) << endl;

//    Screen myScreen(5,6,'x');
//    const Screen blank(5,3);
//    myScreen.set(3,2,'#').display(cout); //调用非常量版本
//    blank.display(cout); //调用常量版本
//    myScreen.move(4,0).set('#').display(cout) ;
//    cout << endl;
//    myScreen.display(cout);
//    cout << '\n';

//    //练习7.31 定义两个类X和Y，其中X包含一个指向Y的指针，Y包含一个类型为X的对象
//	// 由于两个类互相调用，重点需要在定义之前先声明两个类
//    X x;
//    Y y;
//    x.print(cout);
//    cout << endl;
//    y.print(cout);
//    cout << endl;
//
//    y.a.print(cout);
//    cout << endl;
//    x.p->print(cout);

	Screen myScreen(5,6,'x');
	cout << "原始屏幕：";
    myScreen.display(cout);
    cout << endl;

    Window_mgr MGR;
    MGR.Screens.push_back(myScreen);
    MGR.clear(0);
    cout << "清除屏幕：";
//    myScreen.display(cout);

    MGR.Screens[0].display(cout);
    cout << myScreen.size();
	return 0;
}
