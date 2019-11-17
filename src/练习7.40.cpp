//练习7.40 - 再探构造函数：Employee
#include <iostream>
#include <string>
using namespace std;

class Employee{
public:
	//建立构造函数
//	Employee() = default; //有默认实参构造函数时，发生错误call of overloaded 'Employee()' is ambiguous
//    Employee(string s): name(s) { }; // 与默认实参构造函数发生重载
    Employee(string s1 = "Sw"):name(s1) { }
    Employee(string s1,string s2, double m,int w):name(s1),
    		company(s2), money(m), workYears(w) { }

    //成员函数
    void showEmployee() { display();}

private:
    string name;
    string company;
    double money = 0;
    int workYears = 0;
    void display()
    {
        cout << "姓名：" << name << endl;
        cout << "公司：" << company << endl;
        cout << "月工资：" << money << endl;
        cout << "工龄：" << workYears << endl;

    }

};

int main()
{
  Employee test1; //默认实参构造函数
	test1.showEmployee();
	cout << endl;

	Employee test2("Sesen"); //第一种构造函数
	test2.showEmployee();
	cout << endl;

	Employee test3("Ivy", "BT", 2000, 1); // 第二种构造函数
	test3.showEmployee();


	return 0;
}

//输出结果：
姓名：Sw
公司：
月工资：0
工龄：0

姓名：Sesen
公司：
月工资：0
工龄：0

姓名：Ivy
公司：BT
月工资：2000
工龄：1
