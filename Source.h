#pragma once

typedef char DType;
const int row = 15;           // ����
const int column = 14;        // ����
const int SamePointCount = 10;// ��ͬ��ĸ���
DType A[row][column];         // �������ڴ�����
DType AA[row][column];
TwoPoint endPoint;            // �˵�ڵ�
TwoPoint centerPoint;         // �м������ڵ�

enum Digiter
{
    ZERO = '0',
    ONE = '1',
    TWO = '2',
    THREE = '3',
    FOUR = '4',
    FIVE = '5',
    SIX = '6',
    SEVEN = '7',
    EIGHT = '8',
    NIGHT = '9',
    TEN = 'A',
    ELEVEN = 'B',
    TWELEVE = 'C',
    THIRTEEN = 'D',
    FOURTEEN = 'E',
    FIFTEEN = 'F'
};