#pragma once
#include "malloc.h"
#include <stdio.h>
//˫����
typedef struct DNode {
	int data; //����
	struct DNode *piror, *next; //ǰ��ָ�� �ͺ��ָ��
}DNode, *DLinKList;

//β�巨��ʼ��˫����
DLinKList  initDLinKList(DLinKList &L) {
	L = (DLinKList)malloc(sizeof(DNode)); //��ʼ��˫����
	DNode *t = L;//β�ڵ�
	DNode *n; //��ʱ�ڵ�
	//int x;
	//scanf("%d", &x);
	//while (x != 999)
	for (int i = 0; i < 4; i++)
	{
		//����ֵ
		//1 ��ʼ��
		//2 ��ʼ���½ڵ�
		//3 �½ڵ�ͷָ��ִ��ͷ�ڵ�
		//4 ͷ�ڵ�βָ��ָ���½ڵ�
		//5 β�ڵ��滻
		n = (DNode *)malloc(sizeof(DNode));
		n->data = i;
		n->piror = t;
		t->next = n; //β�ڵ�ָ��ָ���½ڵ�
		t = n; //β�ڵ��滻
	}
	t->next = NULL; // ע��βָ����ÿգ������޷��ж������Ƿ�Ϊ��
	return L;
}

//��Ų���
DNode * getElemByIndex(DLinKList L,int index)
{
	int cursor = 1;
	DNode *t = L->next; // β�ڵ�
	while (t && cursor<index)
	{
		t = t->next;
		cursor++;
	}
	return t;
}

//��ֵ����
DNode * getElemByVal(DLinKList L, int val)
{
	DNode *t = L->next; // β�ڵ�
	while (t && t->data!= val)
	{
		t = t->next;
	}
	return t;
}

//λ�ò���
bool insertDLinkList(DLinKList &L,int index,int val)
{
	if (index>1)
	{
		//�ǲ���ͷ�ڵ�
		//1 ���Ҳ���ǰ���ڵ��Ƿ����
		DNode * pirorNode = getElemByIndex(L, index - 1);
		if (pirorNode)
		{
			//2�����ڵ�
			DNode * insertNode = (DNode *)malloc(sizeof(DNode));
			//3����ڵ�
			DNode *midNode = pirorNode->next;
			// �����ڵ㸳ֵ
			insertNode->data = val;
			insertNode->next = midNode;
			//�ƶ��ڵ�λ��
			midNode->piror = insertNode;
			pirorNode->next = insertNode;
			insertNode->piror = pirorNode;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		//����ͷ�ڵ�
		// 1 �½��ڵ�
		DNode * insertNode = (DNode *)malloc(sizeof(DNode));
		insertNode->data = val;
		//2 ͷ�ڵ��滻
		DNode *headNode = L->next;
		insertNode->piror = L; 
		insertNode->next = headNode;
		headNode->piror = insertNode;
		//����ͷ
		L->next = insertNode;
		return true;
	}
}

//λ��ɾ��
bool delDLinkList(DLinKList &L, int index)
{
	if (index>1)
	{
		//�Ǳ�ͷɾ��
		//1ɾ��λ��ǰ���ڵ��Ƿ����
		DNode *pirorNode = getElemByIndex(L, index - 1);
		if (pirorNode)
		{
			DNode *delNode = pirorNode->next;
			pirorNode->next = delNode->next;
			delNode->piror = pirorNode;
			free(delNode);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		//��ͷɾ��
		DNode *headNode = L->next; //��ͷ
		L->next = headNode->next;
		headNode->next->piror = L;
		free(headNode);
		return true;
	}
	
}