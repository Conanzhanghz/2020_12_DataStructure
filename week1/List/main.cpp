#include <iostream>
#include"Array.h"
#include"List.h"
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    //LinearList<int> myList(a, 6);
    LinkList<int> myList(a, 6);
    myList.Write();
    cout<<endl;
    myList.insertElem(3,100);
    myList.Write();
    cout<<endl;
    bool x = myList.deleteElem(5);
    myList.Write();
    return 0;
}
