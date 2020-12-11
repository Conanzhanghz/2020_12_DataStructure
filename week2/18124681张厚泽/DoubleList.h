#include<iostream>
using namespace std;
int defaultSize3 = 100;
template<class T>
class doublenode
{
public:
    T info;
    doublenode<T>* llink;
    doublenode<T>* rlink;
public:
    doublenode();
    doublenode(T e, doublenode<T>* llinkx = nullptr, doublenode<T>* rlinkx = nullptr);
};

template<class T>
doublenode<T>::doublenode()
{
    llink = rlink = nullptr;
}
template<class T>
doublenode<T>::doublenode(T e, doublenode<T>* llinkx, doublenode<T>* rlinkx)
{
    info = e;
    llink = llinkx;
    rlink = rlinkx;
}

template<class T>
class doubleLink
{
public:
    doublenode<T>* header;
    int length;
public:
    doubleLink() = default;
    doubleLink(T v[], int n);
    ~doubleLink();
    bool insertElem(int i, T e,int methode);
    T findElem(const int num,const int methode);
    bool deleteElem(const int num,const int methode);
    void Write();
};

template<class T>
doubleLink<T>::doubleLink(T v[], int n)
{
    length = n;
    doublenode<T>* ptr = header = new doublenode<T>(v[0], nullptr, nullptr);
    for (int i = 2; i <= length; i++)
    {
        ptr->rlink = new doublenode<T>(v[i - 1], ptr, nullptr);
        ptr = ptr->rlink;
    }
    ptr->rlink = header;
    header->llink = ptr;
}

template<class T>
doubleLink<T>::~doubleLink()
{
    doublenode<T>* ptr;
    while (header->rlink!=header)
    {
        ptr = header->rlink;
        header->rlink = ptr->rlink;
        delete ptr;
    }
    delete header;
}

//methode参数 = 1 顺序查找
//methode参数 = 0 逆序检索
template<class T>
T doubleLink<T>::findElem(const int num,const int methode)
{
    doublenode<T>* ptr = header;
    for (int i = 1; i != num; i++) { ptr = methode?ptr->rlink:ptr->llink; }
    return ptr->info;
}

//methode参数 = 1 顺序查找
//methode参数 = 0 逆序检索
template<class T>
bool doubleLink<T>::deleteElem(const int num,const int methode)
{
    doublenode<T>* ptr = header;
    if (num > length || num < 1){return false;}
    else
    {
        doublenode<T>* ptr = header;
        for (int i = 1; i != num; i++) { ptr = methode?ptr->rlink:ptr->llink; }
        ptr->llink->rlink = ptr->rlink;
        ptr->rlink->llink = ptr->llink;
        length--;
        delete ptr;
        return true;
    }
}

//顺序&逆序在第r位插入e节点
//插入失败返回false
template<class T>
bool doubleLink<T>::insertElem(int i, T e,int methode)
{
    doublenode<T>* ptr = header;
    if(i == 0){i = length;}
    else if(i<0 || i>length){return false;}
    else{for(int j = 1;j<i;j++){ptr = methode?ptr->rlink:ptr->llink;}}
    ptr->rlink->llink = new doublenode<T>(e, ptr, ptr->rlink);
    ptr->rlink = ptr->rlink->llink;
    length++;
    return true;
}

template<class T>
void doubleLink<T>::Write()
{
    cout<<endl;
    doublenode<T>* ptr = header;
    for (int i = 1; i <= length; i++)
    {
        cout << ptr->info << " ";
        ptr = ptr->rlink;
    }
}
