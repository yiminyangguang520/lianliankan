#pragma once
#include <iostream>  
using namespace std;
#include "Point.h"
#include <vector> 

//存放连线经过的所有点
class PathRecord
{
public:
    //清除集合中所有的元素
    void clear();
    void addPoint(const Point& p);//添加一个点
    void addPointLine(const Point& first, const Point& second);//添加两个点确定的直线上所有的点
    void addPoint(const Point& first, const Point& center1, const Point& second);
    void addPoint(const Point& first, const Point& center1, const Point& center2, const Point& second);
    ~PathRecord();
    Point* operator[](int index);
    int size();

private:
    vector<Point*> pointVector;
};
