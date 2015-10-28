#pragma once
#include <iostream>  
using namespace std;
#include "Point.h"
#include <vector> 

//������߾��������е�
class PathRecord
{
public:
    //������������е�Ԫ��
    void clear();
    void addPoint(const Point& p);//���һ����
    void addPointLine(const Point& first, const Point& second);//���������ȷ����ֱ�������еĵ�
    void addPoint(const Point& first, const Point& center1, const Point& second);
    void addPoint(const Point& first, const Point& center1, const Point& center2, const Point& second);
    ~PathRecord();
    Point* operator[](int index);
    int size();

private:
    vector<Point*> pointVector;
};
