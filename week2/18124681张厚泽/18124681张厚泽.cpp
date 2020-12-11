#include <iostream>
#include"Array.h"
#include "DoubleList.h"
#include "List.h"
using namespace std;

template <class T>
T DeleteMiniElement(LinearList<T> *header);
template <class T>
void deleteAll(LinearList<T> &listx, T e);
template <class T>
node<T>* findAdress(LinkList<T> &listx, int i);
template<class T>
int statique(LinkList<T> &listx, T e);


int main()
{
    //顺序表
    int a[] = {1, 2, 3, 100, 4, 3, 5, 6, 7, 6, 8, 100, 100, 100};
    LinearList<int> myarray(a, 14);
    myarray.Write();

    //删除最小元素，并由函数返回被删除元素的值，空出的位置由最后一个元素填补
    int k = DeleteMiniElement(myarray);
    myarray.Write();

    //从顺序表中删除具有给定值e的所有元素
    deleteAll(myarray, 100);
    myarray.Write();

    //在一个顺序表中，如果一个数据值有重复出现，则留下第一个这样的数据值，并删除其他所有重复的元素，使得表中的元素的值均不相同
    deleteOthers(myarray);
    myarray.Write();

    cout << endl << "..........." << endl;

    LinkList<int> mylist(a, 14);
    mylist.Write();


    //带表头单链表增删改查
    cout << endl << mylist.findElem(3) << endl;
    bool b = mylist.deleteElem(3);
    mylist.Write();

    mylist.insertElem(4, 999);
    mylist.Write();

    //定位函数
    //在单链表中寻找第i个节点。若找到，则返回第i个节点的地址；否则则返回空指针

    cout<<endl<<findAdress(mylist,7);
    cout<<endl<<findAdress(mylist,20);

    //统计函数
    //统计单链表中等于给定值e的元素个数
    mylist.Write();
    cout<<endl<<statique(mylist,100)<<endl;
    cout<<statique(mylist,3)<<endl;







    //双向链表增删查
    doubleLink<int> myDoubleLink(a, 14);
    myDoubleLink.Write();

    cout<<endl<<myDoubleLink.findElem(3,0);
    cout<<endl<<myDoubleLink.findElem(3,1);

    myDoubleLink.insertElem(2, 777,0);
    myDoubleLink.Write();

    myDoubleLink.insertElem(2, 888,1);
    myDoubleLink.Write();

    myDoubleLink.deleteElem(2,0);
    myDoubleLink.Write();

    myDoubleLink.deleteElem(2,1);
    myDoubleLink.Write();

    return 0;
}
