//============================================================================
// Name        : bookstore_v0.2.cpp
// Author      : shiwei
// Version     : v0.2
// Copyright   : Your copyright notice
// Description : P240 �������Ժ��bookstore����
//============================================================================

#include <iostream>
#include <string>
using namespace std;
#include "Sales_data_v0.2.h"
#include "Person.h"
#include "Screen.h"

class X;
class Y; // ǰ������

class X{
public:
    X() = default; //���캯��
    void print(ostream &os)
    {
    	os << "I am X";
    }
//private:
    Y *p; //����ָ��Y��ָ��;Y����������δ���壬��˴�Ϊ����ȫ����
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
//    //��ϰ7.21
//	//���õ�һ�ֹ��캯��
//	Sales_data book1;
//	print(cout,book1) << endl;
//
//	//���õڶ��ֹ��캯��
//	Sales_data book2("�������Ĺ���");
//	print(cout,book2) << endl;
//
//	//���õ������캯��
//	Sales_data A("as",2,30.0), B("as",3,20.0);
//    print(cout,A.combine(B)) << endl;
//
//
//    //���õ����ֹ��캯��
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
//	// ��ϰ7.22
//    Person C("shiwei","hangzhou");
//    showInformation(cout,C) << endl;

//    Screen myScreen(5,6,'x');
//    const Screen blank(5,3);
//    myScreen.set(3,2,'#').display(cout); //���÷ǳ����汾
//    blank.display(cout); //���ó����汾
//    myScreen.move(4,0).set('#').display(cout) ;
//    cout << endl;
//    myScreen.display(cout);
//    cout << '\n';

//    //��ϰ7.31 ����������X��Y������X����һ��ָ��Y��ָ�룬Y����һ������ΪX�Ķ���
//	// ���������໥����ã��ص���Ҫ�ڶ���֮ǰ������������
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
	cout << "ԭʼ��Ļ��";
    myScreen.display(cout);
    cout << endl;

    Window_mgr MGR;
    MGR.Screens.push_back(myScreen);
    MGR.clear(0);
    cout << "�����Ļ��";
//    myScreen.display(cout);

    MGR.Screens[0].display(cout);
    cout << myScreen.size();
	return 0;
}
