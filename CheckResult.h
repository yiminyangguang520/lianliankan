#pragma once 
#include <set>
#include "Point.h"
#include "Source.h"
#include "PathFind.h"

//����ж�-�ж������ֻ�����ͨ��
class CheckResult
{
public:
    CheckResult();
    CheckResult(int _leftPoint);

    int leftPoint() const;//����ʣ�µĵ�
    int leftLinkLine();//�����ӵĵ����
    void searchLeftLinkLine();//��ѯ�����ӵĵ����
    void searchLeftPoint();//��ѯʣ�µĵ����
    bool reduce2Point();//��������ʣ��ĵ� 
    bool isSuccess();//�ж��Ƿ�ɹ�
    bool isNoSolution();//�Ƿ����޽�

private:
    int m_leftPoint;//ʣ�µĵ������ж��Ƿ����
    volatile int m_leftLinkLine;//�����ӵĵ���� �����ж��Ƿ����� 
    static const int m_hundred = 100;
};
