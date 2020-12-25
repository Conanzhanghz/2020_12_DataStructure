#ifndef POLY_H_INCLUDED
#define POLY_H_INCLUDED
#include<iostream>
using namespace std;
int defaultSize3 = 100;
template<class T>
class PolyNode
{
public:
    int n;
    double coef;
    PolyNode<T>* next;
public:
    PolyNode();
    PolyNode(int nx, double coefx, PolyNode<T>* link = nullptr);
};

template<class T>
PolyNode<T>::PolyNode()
{
    next = nullptr;
}
template<class T>
PolyNode<T>::PolyNode(T e, PolyNode<T>* link)
{
    info = e;
    next = link;
}

template<class T>
class PolyList
{
public:
    PolyNode<T>* header;
    int length;
public:
    LinkList(T v[], int n);
    ~LinkList();
    bool insertElem(int i, T e);
    T findElem(const int num);
    bool deleteElem(int num);
    void Write();
};


template<class T>
LinkList<T>::LinkList(T v[], int n)
{
    PolyNode<T>* p = new PolyNode<T>(v[0], nullptr);
    header = new PolyNode<T>(0, p);
    length = n;
    for (int i = 2; i <= length; i++)
    {
        p->next = new PolyNode<T>(v[i - 1], nullptr);
        p = p->next;
    }
}

template<class T>
LinkList<T>::~LinkList()
{
    PolyNode<T>* p = header->next;
    while (header->next->next!=nullptr)
    {
        p = header->next;
        header->next = p->next;
        delete p;
    }
    delete header->next;
    delete header;
}

template<class T>
T LinkList<T>::findElem(const int num)
{
    PolyNode<T>* ptr = header->next;
    for (int i = 1; i != num; i++) { ptr = ptr->next; }
    return ptr->info;
}

template<class T>
bool LinkList<T>::deleteElem(int num)
{
    PolyNode<T>* ptr = header->next;
    if (num > length || num < 1)
        return false;
    else if (num == 1)
    {
        header = ptr->next;
        length--;
        return true;
    }
    else if (num == length)
    {
        for (int i = 1; i !=length-1; i++){ptr = ptr->next;}
        ptr->next = nullptr;
        length--;
        return true;
    }
    else
    {
        for (int i = 1; i != num-1; i++) { ptr = ptr->next; }
        PolyNode<T>* q = ptr->next;
        ptr->next = ptr->next->next;
        delete q;
        length--;
        return false;
    }
}

//�ڵ�i���ڵ�֮�����e
template<class T>
bool LinkList<T>::insertElem(int i, T e)
{
    if (i == 0) {
        header->next = new PolyNode<T>(e, header->next);
        length++;
        return true;
    }
    else {
        PolyNode<T>* ptr = header->next;
        for (int j = 2; j != i; j++) { ptr = ptr->next; }
        ptr->next = new PolyNode<T>(e, ptr->next);
        length++;
        return true;
    }
}
template<class T>
void LinkList<T>::Write()
{
    cout<<endl;
    PolyNode<T>* ptr = header;
    for (int i = 1; i <= length; i++)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
}


template<class T>
PolyNode<T>* findAdress(LinkList<T> &listx, int i)
{
    PolyNode<T>* ptr = listx.header->next;
    if(i>listx.length||i<1){return nullptr;}
    else
    {
        for(int j = 1;j!=i;j++){ptr = ptr->next;}
        return ptr;
    }
}

template<class T>
int statique(LinkList<T> &listx, T e)
{
    int count = 0;
    for(    PolyNode<T>* ptr = listx.header->next;
            ptr->next != nullptr;
            ptr = ptr->next)
            {
                if(ptr->info == e)
                {
                    count++;
                }
            }
    return count;
}
#endif // POLY_H_INCLUDED
