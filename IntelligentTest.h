#pragma once
#include <algorithm>

//���ܲ���
class IntelligentTest
{
public:
    IntelligentTest();
    void Remove(const Point& p);//ɾ���Ѿ����ӳɹ��ĵ�
    Point getFirstPoint();//��ȡ��һ����
    Point getSecondPoint();//��ȡ�ڶ�����
    void addHasReadPoint(const Point& p);//���Ѿ��������õ㣨��ʱû���ҵ�����ƥ��ĵ㣩����hasReadList��

private:
    void initDataBind();//�����зǿյĵ�����꣨ĳ��ֵ�����뼯��noReadList��
    int firstIndex;//��һ�����ڼ����е�����
    int secondIndex;//�ڶ������ڼ����е�����
    vector<int> hasReadList;//����Ѿ����˵ĵ���Ϣ
    vector<int> noReadList;//���ʣ�µĵ���Ϣ
    static const int Hundred = 100;
};

IntelligentTest::IntelligentTest()
    : firstIndex(0)
    , secondIndex(1)
{
    initDataBind();
}

//���Ѿ��������õ㣨��ʱû���ҵ�����ƥ��ĵ㣩����hasReadList��
void IntelligentTest::addHasReadPoint(const Point& p)
{
    int value = p.X*Hundred + p.Y;
    vector<int>::iterator item = find(hasReadList.begin(), hasReadList.end(), value);

    if (item == hasReadList.end())
    {
        hasReadList.push_back(value);
    }
}

//��ȡ�ڶ�����
Point IntelligentTest::getSecondPoint()
{
    if (secondIndex >= noReadList.size())
    {
        secondIndex = 0;
    }

    int value = noReadList[secondIndex++];
    return Point(value / Hundred, value%Hundred);
}

//��ȡ��һ����
Point IntelligentTest::getFirstPoint()
{
    if (firstIndex >= noReadList.size())
    {
        firstIndex = 0;
    }

    if (hasReadList.size() > 0)
    {
        vector<int>::iterator item = find(hasReadList.begin(), hasReadList.end(), noReadList[firstIndex]);
        while (item != hasReadList.end())
        {
            if (++firstIndex == noReadList.size())
            {
                firstIndex = 0;
                hasReadList.clear();
                break;
            }

            item = find(hasReadList.begin(), hasReadList.end(), noReadList[firstIndex]);
        }
    }

    int value = noReadList[firstIndex++];
    return Point(value / Hundred, value%Hundred);

}

//�����зǿյĵ�����꣨ĳ��ֵ�����뼯��noReadList��
void IntelligentTest::initDataBind()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (A[i][j] != ZERO)
            {
                noReadList.push_back(i*Hundred + j);
            }
        }
    }
}

//ɾ���Ѿ����ӳɹ��ĵ�
void IntelligentTest::Remove(const Point& p)
{
    int value = p.X*Hundred + p.Y;
    vector<int>::iterator item = find(hasReadList.begin(), hasReadList.end(), value);

    if (item != hasReadList.end())
    {
        hasReadList.erase(item);
    }

    item = find(noReadList.begin(), noReadList.end(), value);

    if (item != noReadList.end())
    {
        noReadList.erase(item);

        if (firstIndex < noReadList.size())
        {
            if (noReadList[firstIndex] > value && firstIndex > 0)
            {
                firstIndex--;
            }
        }

        if (secondIndex < noReadList.size())
        {
            if (noReadList[secondIndex] > value && secondIndex > 0)
            {
                secondIndex--;
            }
        }
    }
}