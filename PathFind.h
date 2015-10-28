#pragma once 
#include "Point.h" 
#include "Source.h" 
//Ѱ·����Ҫ���߼�ʵ��   
class PathFind
{
public:
    bool Left(const Point& first, const Point& second);
    bool Right(const Point& first, const Point& second);
    bool Top(const Point& first, const Point& second);
    bool Bottom(const Point& first, const Point& second);
    bool Center(const Point& first, const Point& second);

    bool OneLine(TwoPoint& endPoint);
    bool OneLine(const Point& first, const Point& second);
    bool MoreLine(TwoPoint& endPoint);
    bool MoreLine(const Point& first, const Point& second);
    bool Near(TwoPoint& endPoint);
    bool Near(const Point& first, const Point& second);
    bool Search(TwoPoint& endPoint);
    bool Search(const Point& first, const Point& second);

private:
    //�ж��������Ƿ���һ�������ϼ�ͬY
    bool sameY(const Point& first, const Point& second);
    //�ж����ε���Ƿ���һ�������ϼ�ͬX
    bool SameX(const Point& first, const Point& second);
};
