/*
 * Person.h
 *
 *  Created on: 2019年10月30日
 *      Author: 石威（Sesen）
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
friend ostream& showInformation(ostream&, const Person&);
public:
    //新增构造函数
    Person() = default;
    Person(const string &s): name(s) {};   //：后面是初始值列表
    Person(const string &s1, const string &s2): name(s1),adress(s2) {};

    string GetName() const
        {
        	return name;
        }
        string GetAdress() const
        {
        	return adress;
        }

private:
	string name;
    string adress = "No data";

};


//声明接口函数，在其他源文件中进行定义
ostream &showInformation(ostream&, const Person&);


#endif /* PERSON_H_ */
