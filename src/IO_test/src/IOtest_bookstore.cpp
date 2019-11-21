//============================================================================
// Name        : IOtest_bookstore.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : ��ϰ8.6����ȡ���ۼ�¼�ļ���������������ͬ����ʱ�����л��ܣ���д���ļ���
//============================================================================


#include<fstream>
#include<vector>
#include <iostream>
#include <string>
using namespace std;
#include "Sales_data.h"

void process_sold_record(string infile, string outfile)
{
	ifstream input(infile);
	ofstream output(outfile);
	Sales_data total;

	if (read(input,total))
	{
        Sales_data trans;
        while(read(input,trans))
        {
        	if (total.isbn() == trans.isbn())
        		total.combine(trans);
        	else
        	{
        		print(output,total) << endl; // output��ʱΪ�ļ�д������ֱ��д���ļ������Ǵ�ӡ�����̨
        		total = trans;
        	}
        }
        print(output,total);
	}
	else
		cerr << "No data" << endl;
}

int main()
{
    string sold_file;
    string out_file;
    sold_file = "soldbook.txt";
    out_file = "output.txt";
    process_sold_record(sold_file,out_file);

	return 0;
}

/*
 * ����
 ������ɳĮ  3  25.0
������ɳĮ 5 20.0
�������ѧϰ 2 40.0
Linux�����ŵ����� 2 89.0
���ݽṹ 4 56.0
�������ѧϰ 1 30.0
 */

/*
 * ���
 ������ ������ɳĮ �۳������� 8  �����ܶ 175 �۳�����:21.875
������ �������ѧϰ �۳������� 2  �����ܶ 80 �۳�����:40
������ Linux�����ŵ����� �۳������� 2  �����ܶ 178 �۳�����:89
������ ���ݽṹ �۳������� 4  �����ܶ 224 �۳�����:56
������ �������ѧϰ �۳������� 1  �����ܶ 30 �۳�����:30
 *
 */

