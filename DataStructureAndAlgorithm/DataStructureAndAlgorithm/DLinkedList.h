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
		//3 ͷ�ڵ�βָ��ָ���½ڵ�
		n = (DNode *)malloc(sizeof(DNode));
		n->data = i;
		n->piror = t;
		t->next = n; //β�ڵ�ָ��ָ���½ڵ�
		t = n; //β�ڵ��滻
	}
	//t->next = NULL;
	return L;
}