#pragma once
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    bool isINF; //是否是无穷远点
    Point(int x = 0, int y = 0, bool isINF = false);
    friend ostream& operator<< (ostream& out, const Point& p);
    bool operator ==(const Point& p);
    void Output(ostream& out) const;
};

class Elliptic_Curve
{
private:
    int p;
    int a, b;
public:
    Elliptic_Curve(int p, int a, int b);
    bool Is_Inverse(const Point& p1, const Point& p2); //判断两个点是否互逆
    bool Test_Is_Elliptic_Curve(); //检查当前参数是否能构成椭圆曲线
    bool Is_On_Elliptic_Curve(const Point& p); //判断p点是否在椭圆曲线上 
    Point Add(const Point& p1, const Point& p2); //进行点加运算
    Point Add_K_Times(Point p, int k); //对点p进行k倍加
    int Ord_Of_Point(const Point& p); //计算点p的阶
    int Ord_Of_Elliptic_Curve(); //计算此椭圆曲线的阶#E
    int Show_All_Points(); //展示出椭圆曲线上的所有点
};