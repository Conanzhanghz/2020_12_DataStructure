#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
int IniSize = 100;
template<class T>
class myStack;
{
private:
    //栈顶指针下标，栈大小
    //top为-1代表栈为空
    int top,StackSize;
    //栈数组的头指针
    T* ptr;
public:
    //初始化
    myStack(Array& S, int length)
    {
        ptr = S;
        top = length-1;
        StackSize = length;
    }
    //判断空
    bool isEmpty();
    //判断满
    bool isFull();
    //压入栈
    void Push(T x);
    //扩容
    void OverFlow();

};

template<class T>
void myStack<T>::OverFlow()
{
    int newSize = StackSize+100;
    T* newPtr = new T[newSize];
    for(int i = 0;i<newSize;i++){
        *(newPtr+i) = *(ptr);
    }
    ptr = newPtr;
}




#endif // STACK_H_INCLUDED
