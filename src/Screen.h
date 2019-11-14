/*
 * Screen.h
 *
 *  Created on: 2019年11月7日
 *      Author: 石威（Sesen）
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include<string>
#include<ostream>
#include<vector>
using namespace std;

class Screen;

class Window_mgr
{
public:
	// index 窗口中每个屏幕的编号
	Window_mgr() = default;

    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
//private:
    vector<Screen> Screens;
};


class Screen
{
	/*
	 *string:记录屏幕内容
	 *pos:记录光标位置和屏幕宽高
	 */
//friend友元类：使友元类内的成员函数，可以访问Screen的私有成员
//friend class Window_mgr;
friend  void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos; // 方式一：自定义类型别名
//    using pos = string::size_type; // 方式二：等价使用类型别名

    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht * wd, c) { };
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') { };
    char get() const  // 读取光标处的字符
    {
    	return contents[cursor]; //
    }

    char get(pos r, pos c) const; //声明常量成员函数
    pos size() const;
    Screen &move(pos r, pos c);
    Screen &set(char); //设置光标某一未知的字符
    Screen &set(pos, pos,char); //成员函数重载，设置任意位置字符

    //根据对象是否是const，重载display函数
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    {
    	do_display(os);
    	return *this;
    }

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;

    void do_display(ostream &os) const
    {
    	os << contents;
    }

}; // 类名结束加分号


//inline内联成员函数应该与相应的类定义在同一个头文件中
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this; //
}


inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this; //set成员函数的返回值是调用set的对象的引用，返回对象本身
}

Screen::pos Screen::size() const
{
    return height * width;
}


void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = Screens[i];
//    cout << s.contents << endl;
    s.contents = string(s.height * s.width, ' ');
}

#endif /* SCREEN_H_ */
