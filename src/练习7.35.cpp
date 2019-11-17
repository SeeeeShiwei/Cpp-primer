// 练习7.35
#include <string>
#include <iostream>
using namespace std;


typedef string Type;
Type initVal();  //外部Type string类型
class Exercise{
public:
	typedef double Type;
	Type setVal(Type); //内部Type Double类型
	Type initVal() {return 1.0;} //内部Type Double类型
private:
	int val;
};

Exercise::Type Exercise::setVal(Type parm)  //若无Exercise::Type，则是外层string 类型的Type
{
    val = parm + initVal();
    return val;
}

int main()
{
    Exercise test;
    cout << test.setVal(3.0) << endl;
    return 0;
}
