#pragma once
#include<iostream>
void print(const int data)
{
	std::cout << data << " ";
}


//二叉树节点
template<class T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode<T>* leftChild;
	BinaryTreeNode<T>* rightChild;
public:
	BinaryTreeNode();
	BinaryTreeNode(T d=0, BinaryTreeNode<T>* lChild = nullptr,BinaryTreeNode<T>* rChild = nullptr);
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	data = 0;
	leftChild = rightChild = nullptr;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T d, BinaryTreeNode<T>* lChild, BinaryTreeNode<T>* rChild)
{
	leftChild = lChild;
	rightChild = rChild;
	data = d;
}


//二叉树
template<class T>
class BinaryTree
{
protected:

	void PreOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data));
	void InOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data));
	void PostOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data));

public:
	BinaryTreeNode<T>* root;
	BinaryTree();
	BinaryTree(T data);
	void InsertLeftChild(BinaryTreeNode<T>* rt, const T data);
	void InsertRightChild(BinaryTreeNode<T>* rt, const T data);
	void PreOrder(void (*visitFonction)(const int data));
	void InOrder(void (*visitFonction)(const int data));
	void PostOrder(void (*visitFonction)(const int data));

	BinaryTreeNode<T>* getTree();
};

template<class T>
BinaryTree<T>::BinaryTree()
{
	BinaryTreeNode<T> newNode(0);
	root = &newNode;
}

template<class T>
BinaryTree<T>::BinaryTree(T data)
{
	BinaryTreeNode<T> newNode(data);
	root = &newNode;
}

template<class T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* rt, const T data)
{
	rt->leftChild = &(BinaryTreeNode<T>(data));
}

template<class T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* rt, const T data)
{
	rt->rightChild = &(BinaryTreeNode<T>(data));
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::getTree()
{
	return root;
}

//二叉树先序遍历
template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data)) {
	if (rt == nullptr) {
		return;
	}
	else {
		(*visitFonction)(rt->data);
		PreOrder(rt->leftChild, visitFonction);
		PreOrder(rt->rightChild, visitFonction);
	}
}


//二叉树中序遍历
template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data))
{
	if (rt == nullptr) {
		return;
	}
	else {
		InOrder(rt->leftChild, visitFonction);
		(*visitFonction)(rt->data);
		InOrder(rt->rightChild, visitFonction);
	}
}
//二叉树后序遍历
template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* rt, void (*visitFonction)(const int data))
{
	std::cout << rt << std::endl;
	if (rt == nullptr) {
		return;
	}
	else {
		std::cout << "OUIIIII" << std::endl;
		PostOrder(rt->leftChild, visitFonction);
		PostOrder(rt->rightChild, visitFonction);
		(*visitFonction)(rt->data);
	}
}

//二叉树先序遍历接口
template<class T>
void BinaryTree<T>::PreOrder(void (*visitFonction)(const int data))
{
	PreOrder(root, visitFonction);
}

//二叉树中序遍历接口
template<class T>
void BinaryTree<T>::InOrder(void (*visitFonction)(const int data))
{
	std::cout << "hey" << std::endl;
	InOrder(root, visitFonction);
}

//二叉树后序遍历接口
template<class T>
void BinaryTree<T>::PostOrder(void (*visitFonction)(const int data))
{
	PostOrder(root, visitFonction);
}
