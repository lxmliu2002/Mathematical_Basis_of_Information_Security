#pragma once
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    bool isINF; //�Ƿ�������Զ��
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
    bool Is_Inverse(const Point& p1, const Point& p2); //�ж��������Ƿ���
    bool Test_Is_Elliptic_Curve(); //��鵱ǰ�����Ƿ��ܹ�����Բ����
    bool Is_On_Elliptic_Curve(const Point& p); //�ж�p���Ƿ�����Բ������ 
    Point Add(const Point& p1, const Point& p2); //���е������
    Point Add_K_Times(Point p, int k); //�Ե�p����k����
    int Ord_Of_Point(const Point& p); //�����p�Ľ�
    int Ord_Of_Elliptic_Curve(); //�������Բ���ߵĽ�#E
    int Show_All_Points(); //չʾ����Բ�����ϵ����е�
};