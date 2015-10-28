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

//��ѯ�����ӵĵ����
//ÿ�����������κε�������ӣ�������ӳɹ�leftLinkLine+1��������������뼯��Set�У�Set�е�Ԫ�ز������ڿ���
void CheckResult::searchLeftLinkLine()
{
    set<int> list;//��ųɹ����ӵĵ�
    Point* first = NULL;
    Point* second = NULL;
    PathFind pathFind;
    int value1 = 0;
    int value2 = 0;
    for (int i = 0; i < row; i++)
    {
        //��ȡ��һ����
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] == ZERO)
            {
                continue;
            }
            value1 = i*m_hundred + j;//����һ��Ψһ����

            if (list.find(value1) != list.end())//���������ڼ����оͼ���ѭ��
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
        //��ȡ�ڶ����㣬���������Ӳ���
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] == ZERO)
            {
                continue;
            }
            value2 = i*m_hundred + j;//����һ��Ψһ����

            if (list.find(value2) != list.end())//���������ڼ����оͼ���ѭ��
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
            //�ɹ�����
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

//��ѯʣ�µĵ����
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

//��������ʣ��ĵ� 
bool CheckResult::reduce2Point()
{
    if (m_leftPoint >= 2)
    {
        m_leftPoint -= 2;
        return true;
    }

    return false;
}

//�ж��Ƿ�ɹ�
bool CheckResult::isSuccess()
{
    return m_leftPoint < 1;
}

//�Ƿ����޽�
bool CheckResult::isNoSolution()
{
    if (m_leftLinkLine < 1)
    {
        searchLeftLinkLine();
    }
    return m_leftLinkLine < 1;
}