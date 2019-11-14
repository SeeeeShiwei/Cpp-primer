/*
 * Screen.h
 *
 *  Created on: 2019��11��7��
 *      Author: ʯ����Sesen��
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
	// index ������ÿ����Ļ�ı��
	Window_mgr() = default;

    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
//private:
    vector<Screen> Screens;
};


class Screen
{
	/*
	 *string:��¼��Ļ����
	 *pos:��¼���λ�ú���Ļ���
	 */
//friend��Ԫ�ࣺʹ��Ԫ���ڵĳ�Ա���������Է���Screen��˽�г�Ա
//friend class Window_mgr;
friend  void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos; // ��ʽһ���Զ������ͱ���
//    using pos = string::size_type; // ��ʽ�����ȼ�ʹ�����ͱ���

    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht * wd, c) { };
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') { };
    char get() const  // ��ȡ��괦���ַ�
    {
    	return contents[cursor]; //
    }

    char get(pos r, pos c) const; //����������Ա����
    pos size() const;
    Screen &move(pos r, pos c);
    Screen &set(char); //���ù��ĳһδ֪���ַ�
    Screen &set(pos, pos,char); //��Ա�������أ���������λ���ַ�

    //���ݶ����Ƿ���const������display����
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

}; // ���������ӷֺ�


//inline������Ա����Ӧ������Ӧ���ඨ����ͬһ��ͷ�ļ���
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
    return *this; //set��Ա�����ķ���ֵ�ǵ���set�Ķ�������ã����ض�����
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
