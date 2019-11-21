//============================================================================
// Name        : IOtest_bookstore.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.6：读取销售记录文件，当连续卖出相同的书时，进行汇总，并写入文件。
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
        		print(output,total) << endl; // output此时为文件写入流，直接写入文件，而非打印至输出台
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
 * 输入
 撒哈拉沙漠  3  25.0
撒哈拉沙漠 5 20.0
百面机器学习 2 40.0
Linux从入门到放弃 2 89.0
数据结构 4 56.0
百面机器学习 1 30.0
 */


/*
 * 输出
 书名： 撒哈拉沙漠 售出数量： 8  销售总额： 175 售出单价:21.875
书名： 百面机器学习 售出数量： 2  销售总额： 80 售出单价:40
书名： Linux从入门到放弃 售出数量： 2  销售总额： 178 售出单价:89
书名： 数据结构 售出数量： 4  销售总额： 224 售出单价:56
书名： 百面机器学习 售出数量： 1  销售总额： 30 售出单价:30
 *
 */

