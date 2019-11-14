/*
 * Person.h
 *
 *  Created on: 2019��10��30��
 *      Author: ʯ����Sesen��
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
    //�������캯��
    Person() = default;
    Person(const string &s): name(s) {};   //�������ǳ�ʼֵ�б�
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


//�����ӿں�����������Դ�ļ��н��ж���
ostream &showInformation(ostream&, const Person&);


#endif /* PERSON_H_ */
