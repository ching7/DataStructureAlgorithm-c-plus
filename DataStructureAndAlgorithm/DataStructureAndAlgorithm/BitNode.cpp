#include "malloc.h"
#include <iostream>
using namespace std;
typedef int Elemtype;
//二叉树链式存储
typedef struct BitNode {
	Elemtype data;
	struct BitNode *lchild, *rchild;
}BitNode,*BiTree ;

typedef struct BitTreeFuc {
	//二叉树插值-以完全二叉树举例子
	// 1）如果二叉树查找树为空节点，则插入节点就为根节点
	// 2）如果二叉查找树为非空节点，就需要先找到待插入节点，
	// 查找原则就是从根节点开始，如果大于根就右边走，小于根就左边走，直到找到合适节点，
	BitNode* insertBiTree(BiTree &T,Elemtype input) {
		// 1 判断二叉树节点是否为空
		if (T ==NULL)
		{
			//T = new BitNode;
			T = (BitNode *)malloc(sizeof(BitNode));
			T->data = input;
			T->lchild = NULL;
			T->rchild = NULL;
		}
		else if (input <= T->data)
		{
			T->lchild = insertBiTree(T->lchild, input);
		}
		else
		{
			T->rchild = insertBiTree(T->rchild, input);
		}
		return T;
	}
	
	//递归法遍历
	//前序遍历
	void PreOrder(BiTree T)
	{
		if (T)
		{
			visit(T);
			PreOrder(T->lchild);
			PreOrder(T->rchild);
		}
	
	}
	//中序遍历
	void InOrder(BiTree T)
	{	
		if (T)
		{
			InOrder(T->lchild);
			visit(T);
			InOrder(T->rchild);
		}	
	}

	//后序遍历
	void PostOrder(BiTree T)
	{
		if (T)
		{
			PostOrder(T->lchild);
			PostOrder(T->rchild);
			visit(T);
		}
	}
	void visit(BiTree &T)
	{	
		if (T)
		{
			cout << T->data << endl;
		}

	}

};