#include "CheckResult.h"

CheckResult::CheckResult()
    : m_leftPoint(0)
    , m_leftLinkLine(0)
{
    searchLeftLinkLine();
    searchLeftPoint();
}

CheckResult::CheckResult(int _leftPoint)
    : m_leftPoint(_leftPoint)
{
    searchLeftLinkLine();
}

int CheckResult::leftPoint() const
{
    return m_leftPoint;
}

int CheckResult::leftLinkLine()
{
    if (m_leftLinkLine <= 0)
    {
        searchLeftLinkLine();
    }

    return m_leftLinkLine;
}

//查询可连接的点对数
//每个点与其他任何点进行连接，如果连接成功leftLinkLine+1；将这两个点加入集合Set中，Set中的元素不在用于考虑
void CheckResult::searchLeftLinkLine()
{
    set<int> list;//存放成功连接的点
    Point* first = NULL;
    Point* second = NULL;
    PathFind pathFind;
    int value1 = 0;
    int value2 = 0;
    for (int i = 0; i < row; i++)
    {
        //获取第一个点
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] == ZERO)
            {
                continue;
            }
            value1 = i*m_hundred + j;//构成一个唯一的数

            if (list.find(value1) != list.end())//如果这个数在集合中就继续循环
            {
                continue;
            }

            first = new Point(i, j);
            break;
        }

        if (first == NULL)
        {
            continue;
        }
        //获取第二个点，并进行连接测试
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] == ZERO)
            {
                continue;
            }
            value2 = i*m_hundred + j;//构成一个唯一的数

            if (list.find(value2) != list.end())//如果这个数在集合中就继续循环
            {
                continue;
            }

            if (A[first->X][first->Y] != A[i][j])
            {
                continue;
            }

            second = new Point(i, j);

            if (*first == *second)
            {
                continue;
            }

            bool isOK = pathFind.Search(*first, *second);
            if (!isOK)
            {
                continue;
            }
            //成功连接
            delete first;
            first = NULL;
            delete second;
            second = NULL;
            list.insert(value1);
            list.insert(value2);
            ++m_leftLinkLine;
            break;
        }

        if (first != NULL)
        {
            delete first;
            first = NULL;
        }
    }
}

//查询剩下的点个数
void CheckResult::searchLeftPoint()
{
    m_leftPoint = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] != ZERO)
            {
                ++m_leftPoint;
            }
        }
    }
}

//减少两个剩余的点 
bool CheckResult::reduce2Point()
{
    if (m_leftPoint >= 2)
    {
        m_leftPoint -= 2;
        return true;
    }

    return false;
}

//判断是否成功
bool CheckResult::isSuccess()
{
    return m_leftPoint < 1;
}

//是否是无解
bool CheckResult::isNoSolution()
{
    if (m_leftLinkLine < 1)
    {
        searchLeftLinkLine();
    }
    return m_leftLinkLine < 1;
}