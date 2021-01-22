// Pile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "Pile.h"
using namespace std;



bool isPile(int* list, int length)
{
    int a, b;
    bool MaxPile = 1;
    bool MinPile = 1;
    for (int i = 0; i <= ((length - 1) / 2); i++)
    {
        if (list[i] <= list[2*i + 1])
        {
            if (list[i] <= list[2*i + 2])
            {

            }
            else
            {
                MinPile = 0;
                break;
            }
        }
        else
        {
            MinPile = 0;
            break;
        }
    }
    if (MinPile == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i <= ((length - 1) / 2); i++)
        {
            a = list[i];
            b = list[2*i + 1];
            if (list[i] >= list[2*i + 1])
            {
                a = list[i];
                b = list[2*i + 2];
                if (list[i] >= list[2*i + 2])
                {

                }
                else
                {
                    MaxPile = 0;
                    break;
                }
            }
            else
            {
                MaxPile = 0;
                break;
            }
        }
        if (MaxPile == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}

int main()
{
    int a[10] = { 100,86,48,73,35,39,42,57,66,21 };
    int b[10] = { 12,70,33,65,24,56,48,92,86,33 };
    cout << isPile(a, 10)<<endl;
    cout << isPile(b, 10)<<endl;
    Pile<int> myPile1(a, 100, 9);
    Pile<int> myPile2(b, 100, 10);
    return 0;
    //根据输出结果，第一个数组为最大堆，第二个数组为非堆
}