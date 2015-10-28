#pragma once
#include <iostream>  
using namespace std;

//��ʾ�������ϵ�һ����[X,Y]
struct Point
{
    Point()
        : X(-1)
        , Y(-1)
    {

    }

    Point(int _x, int _y)
        : X(_x)
        , Y(_y)
    {

    }

    Point(const Point& p)
        : X(p.X)
        , Y(p.Y)
    {

    }

    Point& operator=(const Point& p);

    bool operator==(const Point& p);

    bool operator==(Point& p);

    bool operator!=(const Point& p);

    bool operator!=(Point& p);

    int X;//X��
    int Y;//Y��
};


//���ڼ�¼�û��������������  
class TwoPoint
{
public:
    TwoPoint();
    ~TwoPoint();
    //��ӵ�
    bool addPoint(const Point& p);
    //��ĸ���
    int count() const;

    Point First() const;
    void First(const Point& p);
    Point Second() const;
    void sort();
    void clear();

private:
    TwoPoint(const TwoPoint& p);
    TwoPoint& operator=(const TwoPoint& p);
    Point* first;
    Point* second;
    int m_count;
};