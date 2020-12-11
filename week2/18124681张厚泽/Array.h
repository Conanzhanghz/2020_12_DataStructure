#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include<iostream>
using namespace std;
int defaultSize = 100;
template<class T>
class LinearList
{
public:
    int length;
    T* header;
public:
    LinearList(T v[], int n, int ListSize = defaultSize);
    LinearList(int ListSize = defaultSize);
    ~LinearList();
    bool insertElem(int i, const T& e);
    int findElem(const T& e);
    T getValue(int num);
    bool deleteElem(int num);
    void Write();
};

template<class T>
LinearList<T>::LinearList(int ListSize)
{
    ListSize = 100;
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
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << header[i] << " ";
    }
}
template<class T>
LinearList<T>::LinearList(T v[], int n, int ListSize)
{
    if (n > ListSize)
        return;
    header = new T[ListSize];
    length = n;
    for (int i = 0; i < length; i++)
    {
        header[i] = v[i];
    }
}
template<class T>
bool LinearList<T>::insertElem(int i, const T& e)
{
    if (i<0 || i>length)
        return false;
    for (int j = length; j > i; j--)
    {
        header[j] = header[j - 1];
    }
    header[i] = e;
    length++;
    return true;
}
template<class T>
int LinearList<T>::findElem(const T& e)
{
    for (int i = 0; i < length; i++)
    {
        if (header[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
template<class T>
bool LinearList<T>::deleteElem(int num)
{
    if (num<1 || num>length)
        return false;
    else
    {
        for (int n = num; n < length; n++)
        {
            header[n - 1] = header[n];
        }
        length--;
        return true;
    }
}
template<class T>
T LinearList<T>::getValue(int num)
{
    return *(header + num - 1);
}

template<class T>
T DeleteMiniElement(LinearList<T>& listx)
{
    int index = 0;
    for (int i = 1; i < listx.length; i++)
    {
        if (listx.header[i] < listx.header[index])
        {
            index = i;
        }
    }
    T flag = listx.header[index];
    listx.header[index] = listx.header[listx.length - 1];
    listx.deleteElem(listx.length);
    return flag;
}

template<class T>
void deleteAll(LinearList<T>& listx, T e)
{
    for (int i = 0; i < listx.length; i++)
    {
        if (listx.header[i] == e)
        {
            listx.deleteElem(i + 1);
            i--;
        }
    }
}

template<class T>
void deleteOthers(LinearList<T>& listx)
{
    int flag;
    for (int i = 0; i < listx.length; i++)
    {
        flag = listx.header[i];
        for (int j = i + 1; j < listx.length; j++)
        {
            if (listx.header[j] == flag)
            {
                listx.deleteElem(j + 1);
                j--;
            }
        }
    }
}
#endif // ARRAY_H_INCLUDED
