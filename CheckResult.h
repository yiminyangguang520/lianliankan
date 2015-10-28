#pragma once 
#include <set>
#include "Point.h"
#include "Source.h"
#include "PathFind.h"

//结果判定-判定是死局或是已通关
class CheckResult
{
public:
    CheckResult();
    CheckResult(int _leftPoint);

    int leftPoint() const;//返回剩下的点
    int leftLinkLine();//可连接的点对数
    void searchLeftLinkLine();//查询可连接的点对数
    void searchLeftPoint();//查询剩下的点个数
    bool reduce2Point();//减少两个剩余的点 
    bool isSuccess();//判断是否成功
    bool isNoSolution();//是否是无解

private:
    int m_leftPoint;//剩下的点用于判断是否结束
    volatile int m_leftLinkLine;//可连接的点对数 用于判断是否死局 
    static const int m_hundred = 100;
};
