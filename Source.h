#pragma once

typedef char DType;
const int row = 15;           // 行数
const int column = 14;        // 列数
const int SamePointCount = 10;// 相同点的个数
DType A[row][column];         // 数组用于存数据
DType AA[row][column];
TwoPoint endPoint;            // 端点节点
TwoPoint centerPoint;         // 中间两个节点

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