#include <iostream>
#include "Array.h"
#include "List.h"
int x,y;
int main() {
    try{
    int a[] = {1,2,3,4,5,6};

    LinearList<int> myLinearList(a, 6);
    cout<<"linear array par default:";
    myLinearList.Write();

    cout<<endl<<"insert element:";cin>>x;
    cout<<"number de index? range from 0~length:";cin>>y;
    if(!myLinearList.insertElem(y,x))
        throw("error of insert");
    else{
        cout<<"insert "<<x<<" at number "<<y<<" and then we have:";
        myLinearList.Write();
    }

    cout<<endl<<"input element and return index:";cin>>x;
    if(myLinearList.findElem(x)!=0){
        cout<<"the "<<x<<" index is "<<myLinearList.findElem(x);
    }
    else{
        throw("element doesn't exeist!");
    }

    cout<<endl<<"delete element with index:";cin>>x;
    if(!myLinearList.deleteElem(x))
        throw("index out of range!");
    else{
        cout<<endl<<"delete "<<x<<" then we have:";
        myLinearList.Write();
    }





    LinkList<int> myLinkList(a, 6);
    cout<<endl<<endl<<"LinkList par default:"<<endl;
    myLinkList.Write();

    cout<<endl<<"insert element:";cin>>x;
    cout<<"number de index? range from 0~length:";cin>>y;
    if(!myLinkList.insertElem(y,x))
        throw("error of insert");
    else{
        cout<<"insert "<<x<<" at number "<<y<<" and then we have:"<<endl;
        myLinkList.Write();
    }

    cout<<endl<<"input element and return index:";cin>>x;
    if(myLinkList.findElem(x)!=0){
        cout<<"the "<<x<<" index is "<<myLinkList.findElem(x);
    }
    else{
        throw("element doesn't exeist!");
    }

    cout<<endl<<"delete element with index:";cin>>x;
    if(!myLinkList.deleteElem(x))
        throw("index out of range!");
    else{
        cout<<endl<<"delete "<<x<<" then we have:"<<endl;
        myLinkList.Write();
    }





    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return 0;
}
