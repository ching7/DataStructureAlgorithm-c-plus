#include "malloc.h"
#include <iostream>
using namespace std;
typedef int Elemtype;
//��������ʽ�洢
typedef struct BitNode {
	Elemtype data;
	struct BitNode *lchild, *rchild;
}BitNode,*BiTree ;

typedef struct BitTreeFuc {
	//��������ֵ-����ȫ������������
	// 1�����������������Ϊ�սڵ㣬�����ڵ��Ϊ���ڵ�
	// 2��������������Ϊ�ǿսڵ㣬����Ҫ���ҵ�������ڵ㣬
	// ����ԭ����ǴӸ��ڵ㿪ʼ��������ڸ����ұ��ߣ�С�ڸ�������ߣ�ֱ���ҵ����ʽڵ㣬
	BitNode* insertBiTree(BiTree &T,Elemtype input) {
		// 1 �ж϶������ڵ��Ƿ�Ϊ��
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
	
	//�ݹ鷨����
	//ǰ�����
	void PreOrder(BiTree T)
	{
		if (T)
		{
			visit(T);
			PreOrder(T->lchild);
			PreOrder(T->rchild);
		}
	
	}
	//�������
	void InOrder(BiTree T)
	{	
		if (T)
		{
			InOrder(T->lchild);
			visit(T);
			InOrder(T->rchild);
		}	
	}

	//�������
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