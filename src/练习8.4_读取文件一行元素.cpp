//============================================================================
// Name        : IO_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.4：读文件，将每行元素存于string类型的vector中
//============================================================================

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


int main()
{
    vector<string> result_vec;
    string file_name;
    string line;

    file_name = "iotest_file.txt"; //iotest_file.txt存放位置为工程目录下，而非src内
    ifstream input(file_name); //构建ifstream文件流，并打开文件
    while(!input.eof())
    {
    	getline(input,line);
    	result_vec.push_back(line);
    }
    for(auto l : result_vec)
    {
    	cout << l << endl;
    }
}
