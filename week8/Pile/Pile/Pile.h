#include<iostream>
template<class T>
class Pile
{
private:
    T* PileArr;
    int currentSize;
    int maxSize;
    void FilterDown(int Start);
    void FilterUp(int Start);

public:
    Pile(T a[], int maxSize, int n);
    ~Pile() { delete[]PileArr; }
    void WritePile();

};

template<class T>
void Pile<T>::FilterDown(int Start)
{
    int i = Start;
    int j;
    //temp为双亲结点
    T temp = PileArr[i];
    j = 2 * i + 1;
    //i不是叶子节点（i有孩子节点）
    while (j <= currentSize - 1)
    {
        //该算法需要把j指向关键字较小的孩子节点
        if (j<currentSize - 1 && PileArr[j]>PileArr[j + 1])
            j++;
        if (temp <= PileArr[j])
            break;
        else
        {
            PileArr[i] = PileArr[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    PileArr[i] = temp;
}


template<class T>
void Pile<T>::FilterUp(int Start)
{
    int i = Start;
    int j;
    //temp为双亲结点
    T temp = PileArr[i];
    j = 2 * i + 1;
    //i不是叶子节点（i有孩子节点）
    while (j <= currentSize - 1)
    {
        //该算法需要把j指向关键字较小的孩子节点
        if (j<currentSize - 1 && PileArr[j]<PileArr[j + 1])
            j++;
        if (temp >= PileArr[j])
            break;
        else
        {
            PileArr[i] = PileArr[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    PileArr[i] = temp;
}


template<class T>
Pile<T>::Pile(T a[], int MS, int n)
{
    maxSize = MS;
    if (n <= 0)
    {
        std::cout << "堆的大小不能小于1" << std::endl;
    }
    PileArr = new T[maxSize];
    for (int i = 0; i < n; i++)
    {
        PileArr[i] = a[i];
    }
    currentSize = n;
    int i = (currentSize - 2) / 2;
    while (i >= 0)
    {
        FilterUp(i);
        i--;
        WritePile();
    }
}

template<class T>
void Pile<T>::WritePile()
{
    for (int i = 0; i < currentSize; i++)
    {
        std::cout << PileArr[i]<<" ";
    }
    std::cout << std::endl;
}