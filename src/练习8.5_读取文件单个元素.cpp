//============================================================================
// Name        : IO_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习8.5：读文件，将每个独立元素存于string类型的vector中
//============================================================================

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;




void read_word(string fileName)
{
	vector<string> result_vec;
	string word;

	ifstream input(fileName); //构建ifstream文件流，并打开文件
	while(!input.eof()) // 判断文件是否达到结尾
	{
	    input >> word;
	    result_vec.push_back(word);
	}
	for(auto ele : result_vec)
	{
	    cout << ele << endl;
	}
}

int main()
{
	string file_name;
	file_name = "iotest_file.txt";
	read_word(file_name);
	return 0;
}
