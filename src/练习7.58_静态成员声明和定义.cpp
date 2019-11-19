//============================================================================
// Name        : booksotre_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习7.58
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// example.h
class Example
{
public:
    // 修改前
//	static constexpr double rate = 0.5;  //静态成员不是整数类型，不可再类内初始化
//	static const int vectsize = 20; // 可以为静态成员提供const整数类型的类内初始值
//	static vector<double> vec(vectsize); // 静态成员变量在类内声明，在外部定义
	//修改后
	static double rate;
	static constexpr int vectsize = 20; // 必须是constexpr
	static vector<double> vec;

};
// 修改前
// double Example::rate;
// vector<double> Example::vec; // 这是声明
// 修改后
double Example::rate = 6.5; // 对非const整数类型的静态成员进行外部定义
vector<double> Example::vec(vectsize); // 静态成员变量在类内声明，在外部定义

int main() {
    Example A;
	Example *B = &A;
    double rA,rB;
    rA = A.rate; // 通过Example的对象或引用，访问静态成员
    rB = B->rate; // 通过指向Example的指针，访问静态成员
    cout << rA << endl;
    cout << rB << endl;

    vector<double> Vect;
    Vect = A.vec;
    cout << Vect.size() << endl;
	return 0;
}

/*
6.5
6.5
20
 */
