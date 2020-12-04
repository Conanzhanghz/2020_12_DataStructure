#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include<iostream>
using namespace std;
int defaultSize = 100;
template<class T>
class LinearList
{
protected:
	int length;
	T* header;
public:
    LinearList(T v[], int n, int ListSize = defaultSize);
    LinearList(int ListSize = defaultSize);
    ~LinearList();
//在第i个元素的后面插入e
    bool insertElem(int i, const T& e);
//查找线性表中的元素，返回元素序号,找不到返回0
    int findElem(const T& e);
    bool deleteElem(int num);
    void Write();
};

template<class T>
LinearList<T>::LinearList(int ListSize)
{
    ListSize  = 100;
    header = new T[ListSize];
    length = 0;
}
template<class T>
LinearList<T>::~LinearList()
{
    length = 0;
}
template<class T>
void LinearList<T>::Write()
{
    for(int i = 0;i<length;i++)
    {
        cout<<header[i]<<" ";
    }
}
template<class T>
LinearList<T>::LinearList(T v[], int n, int ListSize)
{
    if(n>ListSize)
        return;
    header = new T[ListSize];
    length = n;
    for(int i = 0;i<length;i++)
    {
        header[i] = v[i];
    }
}
template<class T>
bool LinearList<T>::insertElem(int i, const T& e)
{
    if(i<1 || i>length)
        return false;
    for(int j = length;j>i;j--)
    {
        header[j] = header[j-1];
    }
    header[i] = e;
    length++;
    return true;
}
template<class T>
int LinearList<T>::findElem(const T& e)
{
    for(int i=0;i<length;i++)
    {
        if(header[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}
template<class T>
bool LinearList<T>::deleteElem(int num)
{
    if(num<1 || num>length)
        return false;
    else
    {
        for(int n = num;n<length;n++)
        {
            header[n-1] = header[n];
        }
        length--;
        return true;
    }
}
#endif // ARRAY_H_INCLUDED
