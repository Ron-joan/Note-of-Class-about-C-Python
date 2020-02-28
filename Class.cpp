#include <iostream>
#include <cmath>
#include "string.h"
using namespace std;
class Point
{
private:
    int x,y;
    static int number;                                          // 这是一个静态变量,静态变量在同一个类下的所有对象中只存在一个
    char *pname;
public:
    Point(int x1 = 1,int y1 = 0,char* pn = "normal");           // 这里是析构函数,用于函数的初始化,名称必须为类名,若形参已被初始化,则定义对象时()可加可不加;如果没有,就一定要加
    Point(const Point &s);                                      // 这是拷贝析构函数,与析构函数重载,用于对象之间的复制,形参必须为类的引用,最好设置为常量
    void cout_x()const;                                         // 这是一个常量函数,它的特点是告知人们不可以通过它去修改私密部分变量的值
    double distance_line(int a,int b,int c);                    // 这是一个一般成员函数,它的函数体放在类的定义外
    friend Point operator+(const Point& a,const Point& b);      // 这是一个操作符重载函数,通过这个函数可以修改操作符的操作范围赋予更多的能力
    void setpoint(int x1,int y1)                                // 这是一个一般成员函数,一般来说函数体不超过三行的函数我们将它放到类里,称它为内联函数
    {
        x = x1,y = y1;
    }
    static void tatol()                                         // 这是一个静态成员函数,它的特点为它依托类而存在,就算没有对象可以被调用
    {
        cout << "All point is " << number << endl;
    }
    double distance_piont(int x2,int y2)
    {
        cout << "distance is " << sqrt(pow(x2 - x,2) + pow(y2 - y,2)) << endl;
        return sqrt(pow(x2 - x,2) + pow(y2 - y,2));
    }
    ~Point();                                                   // 这是一个析构函数,它只在对象消亡时才被启用,它的函数名为 ~ + 类名
};
int Point::number = 0;                                          // 静态变量的初始化必须在类外格式为 整数类型 + 类名:: + 变量名
Point::Point(int x1,int y1,char *pn):x(x1),y(y1),pname(pn)      // 这是析构函数的函数体,形参不用初始化;冒号之后是调用表,用于给成员变量赋值
{                                                               // 析构函数只能在创建对象时调用
    number++;                                                   // 函数头必须为 类名::类名
    cout << " It's name is " << pn << endl;
    pname = new char[strlen(pn) + 1];
    if(pname) strcpy(pname,pn);
}
Point ::Point(const Point &s)                                   // 这是一个拷贝析构函数,用于对象之间的拷贝,多用于拷贝一些内容易变化的变量如:指针
{                                                               // 如果要把甲的内容复制到乙,则在拷贝析构函数中要确保乙中的内容要释放
    number++;
    cout << "All point is " << number << " It's name is " << s.pname << endl;
    pname = new char[strlen(s.pname) + 1];
    if(pname) strcpy(pname,s.pname);
}
Point::~Point()
{
    number--;
}
double Point::distance_line(int a,int b,int c)                  // 一般成员函数的函数体,没什么好说的,就是: 类型名 + 类名:: + 函数名
{
    double down;
    int up;
    up = a*x+b*y+c;
    if(up<0)
        up = -1*up;
    down = sqrt(pow(a,2) + pow(b,2));
    return up/down;
}
void Point::cout_x()const                                       // 常成员函数,在一般成员函数后加const
{
    cout << "x = " << x << endl;
}
Point operator+(const Point& a,const Point& b)
{
    Point s(0,0);
    s.setpoint(a.x+b.x,a.y+b.y);
    return s;
}
int main(void)
{
    Point::tatol();
    Point p,w(12,3,"one");
    Point a = w;
}
