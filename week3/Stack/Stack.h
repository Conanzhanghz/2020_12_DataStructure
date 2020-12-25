#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
int IniSize = 100;
template<class T>
class myStack;
{
private:
    //ջ��ָ���±꣬ջ��С
    //topΪ-1����ջΪ��
    int top,StackSize;
    //ջ�����ͷָ��
    T* ptr;
public:
    //��ʼ��
    myStack(Array& S, int length)
    {
        ptr = S;
        top = length-1;
        StackSize = length;
    }
    //�жϿ�
    bool isEmpty();
    //�ж���
    bool isFull();
    //ѹ��ջ
    void Push(T x);
    //����
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
