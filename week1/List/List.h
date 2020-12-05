#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include<iostream>
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
node<T>::node(T e, node<T> *link)
{
    info = e;
    next = link;
}



template<class T>
class LinkList
{
protected:
    node<T>* header;
    int length;
public:
    LinkList(T v[], int n);
    bool insertElem(int i, T e);
    int findElem(const T e);
    bool deleteElem(int num);
    void Write();
};


template<class T>
LinkList<T>::LinkList(T v[], int n)
{
    node<T>* p;
    header = new node<T>(v[0],nullptr);
    p = header;
    length = n;
    for(int i = 2; i<=length;i++)
    {
        p->next = new node<T>(v[i-1],nullptr);
        p = p->next;
    }

}
template<class T>
int LinkList<T>::findElem(const T e)
{
    int cot = 1;
    node<T>* ptr = header;
    while(ptr!=nullptr)
    {
        if(ptr->info == e)
            return cot;
        ptr = ptr->next;
        cot++;
    }
    return 0;
}
template<class T>
bool LinkList<T>::deleteElem(int num)
{
    node<T>* ptr = header;
    if(num>length||num<1)
        return false;
    else if(num == 1)
    {
        header = header->next;
        length--;
        return true;
    }
    else if(num == length)
    {
        for(int i = 1;i<length-1;i++)
        {
            ptr = ptr->next;
        }
        ptr = nullptr;
        length--;
        return true;
    }
    else
    {
        for(int i = 1;i<length;i++)
        {
            if(i == num-1){
                ptr->next = ptr->next->next;length--;return true;}
            ptr = ptr->next;
        }
        return false;
    }
}
template<class T>
bool LinkList<T>::insertElem(int i, T e)
{
    if(i == 0){
        header = new node<T>(e,header);
        length++;
        return true;
    }
    else{
    node<T>* ptr = header;
    for(int j = 1;j<=length;j++)
    {
        if(j == i){
            ptr->next = new node<T>(e,ptr->next);length++;return true;}
        ptr = ptr->next;
    }
    return false;
    }
}
template<class T>
void LinkList<T>::Write()
{
    node<T>* ptr = header;
    for(int i = 1; i<=length; i++)
    {
        cout<<ptr->info<<" ";
        ptr = ptr->next;
    }
}
#endif // LIST_H_INCLUDED
