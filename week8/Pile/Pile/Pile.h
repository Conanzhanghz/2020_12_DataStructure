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
    //tempΪ˫�׽��
    T temp = PileArr[i];
    j = 2 * i + 1;
    //i����Ҷ�ӽڵ㣨i�к��ӽڵ㣩
    while (j <= currentSize - 1)
    {
        //���㷨��Ҫ��jָ��ؼ��ֽ�С�ĺ��ӽڵ�
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
    //tempΪ˫�׽��
    T temp = PileArr[i];
    j = 2 * i + 1;
    //i����Ҷ�ӽڵ㣨i�к��ӽڵ㣩
    while (j <= currentSize - 1)
    {
        //���㷨��Ҫ��jָ��ؼ��ֽ�С�ĺ��ӽڵ�
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
        std::cout << "�ѵĴ�С����С��1" << std::endl;
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