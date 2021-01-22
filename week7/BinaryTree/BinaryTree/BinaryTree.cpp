// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"BinaryTree.h"

int main()
{
    //初始化函数指针
    void (*ptr)(const int data);
    ptr = print;

    //初始化二叉树

    //参数列表中加T& a 的时候不能直接传常量进去，否则报错
    //必须新建一个变量，给变量赋值，然后再传变量
    int a = 0;
    BinaryTree<int> myTree(a);
    myTree.InsertLeftChild(myTree.root, 1);
    myTree.InsertRightChild(myTree.root, 2);

    myTree.InOrder(ptr);

    return 0;
}