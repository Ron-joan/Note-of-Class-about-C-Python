#include <iostream>
#include <cmath>
#include "string.h"
using namespace std;
class Point
{
private:
    int x,y;
    static int number;                                          // ����һ����̬����,��̬������ͬһ�����µ����ж�����ֻ����һ��
    char *pname;
public:
    Point(int x1 = 1,int y1 = 0,char* pn = "normal");           // ��������������,���ں����ĳ�ʼ��,���Ʊ���Ϊ����,���β��ѱ���ʼ��,�������ʱ()�ɼӿɲ���;���û��,��һ��Ҫ��
    Point(const Point &s);                                      // ���ǿ�����������,��������������,���ڶ���֮��ĸ���,�βα���Ϊ�������,�������Ϊ����
    void cout_x()const;                                         // ����һ����������,�����ص��Ǹ�֪���ǲ�����ͨ����ȥ�޸�˽�ܲ��ֱ�����ֵ
    double distance_line(int a,int b,int c);                    // ����һ��һ���Ա����,���ĺ����������Ķ�����
    friend Point operator+(const Point& a,const Point& b);      // ����һ�����������غ���,ͨ��������������޸Ĳ������Ĳ�����Χ������������
    void setpoint(int x1,int y1)                                // ����һ��һ���Ա����,һ����˵�����岻�������еĺ������ǽ����ŵ�����,����Ϊ��������
    {
        x = x1,y = y1;
    }
    static void tatol()                                         // ����һ����̬��Ա����,�����ص�Ϊ�������������,����û�ж�����Ա�����
    {
        cout << "All point is " << number << endl;
    }
    double distance_piont(int x2,int y2)
    {
        cout << "distance is " << sqrt(pow(x2 - x,2) + pow(y2 - y,2)) << endl;
        return sqrt(pow(x2 - x,2) + pow(y2 - y,2));
    }
    ~Point();                                                   // ����һ����������,��ֻ�ڶ�������ʱ�ű�����,���ĺ�����Ϊ ~ + ����
};
int Point::number = 0;                                          // ��̬�����ĳ�ʼ�������������ʽΪ �������� + ����:: + ������
Point::Point(int x1,int y1,char *pn):x(x1),y(y1),pname(pn)      // �������������ĺ�����,�ββ��ó�ʼ��;ð��֮���ǵ��ñ�,���ڸ���Ա������ֵ
{                                                               // ��������ֻ���ڴ�������ʱ����
    number++;                                                   // ����ͷ����Ϊ ����::����
    cout << " It's name is " << pn << endl;
    pname = new char[strlen(pn) + 1];
    if(pname) strcpy(pname,pn);
}
Point ::Point(const Point &s)                                   // ����һ��������������,���ڶ���֮��Ŀ���,�����ڿ���һЩ�����ױ仯�ı�����:ָ��
{                                                               // ���Ҫ�Ѽ׵����ݸ��Ƶ���,���ڿ�������������Ҫȷ�����е�����Ҫ�ͷ�
    number++;
    cout << "All point is " << number << " It's name is " << s.pname << endl;
    pname = new char[strlen(s.pname) + 1];
    if(pname) strcpy(pname,s.pname);
}
Point::~Point()
{
    number--;
}
double Point::distance_line(int a,int b,int c)                  // һ���Ա�����ĺ�����,ûʲô��˵��,����: ������ + ����:: + ������
{
    double down;
    int up;
    up = a*x+b*y+c;
    if(up<0)
        up = -1*up;
    down = sqrt(pow(a,2) + pow(b,2));
    return up/down;
}
void Point::cout_x()const                                       // ����Ա����,��һ���Ա�������const
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
