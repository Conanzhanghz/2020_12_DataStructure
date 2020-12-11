#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include<iostream>
using namespace std;
int defaultSize2 = 100;
template<class T>
class node
{
public:
    T info;
    node<T>* next;
public:
    node();
    node(T e, node<T>* link = nullptr);
};

template<class T>
node<T>::node()
{
    next = nullptr;
}
template<class T>
node<T>::node(T e, node<T>* link)
{
    info = e;
    next = link;
}

template<class T>
class LinkList
{
public:
    node<T>* header;
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
    node<T>* p = new node<T>(v[0], nullptr);
    header = new node<T>(0, p);
    length = n;
    for (int i = 2; i <= length; i++)
    {
        p->next = new node<T>(v[i - 1], nullptr);
        p = p->next;
    }
}

template<class T>
LinkList<T>::~LinkList()
{
    node<T>* p = header->next;
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
    node<T>* ptr = header->next;
    for (int i = 1; i != num; i++) { ptr = ptr->next; }
    return ptr->info;
}

template<class T>
bool LinkList<T>::deleteElem(int num)
{
    node<T>* ptr = header->next;
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
        node<T>* q = ptr->next;
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
        header->next = new node<T>(e, header->next);
        length++;
        return true;
    }
    else {
        node<T>* ptr = header->next;
        for (int j = 2; j != i; j++) { ptr = ptr->next; }
        ptr->next = new node<T>(e, ptr->next);
        length++;
        return true;
    }
}
template<class T>
void LinkList<T>::Write()
{
    cout<<endl;
    node<T>* ptr = header;
    for (int i = 1; i <= length; i++)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
}


template<class T>
node<T>* findAdress(LinkList<T> &listx, int i)
{
    node<T>* ptr = listx.header->next;
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
    for(    node<T>* ptr = listx.header->next;
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

#endif // LIST_H_INCLUDED
