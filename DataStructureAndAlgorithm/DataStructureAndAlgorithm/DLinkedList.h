#pragma once
#include "malloc.h"
#include <stdio.h>
//双链表
typedef struct DNode {
	int data; //数据
	struct DNode *piror, *next; //前驱指针 和后继指针
}DNode, *DLinKList;

//尾插法初始化双链表
DLinKList  initDLinKList(DLinKList &L) {
	L = (DLinKList)malloc(sizeof(DNode)); //初始化双链表
	DNode *t = L;//尾节点
	DNode *n; //临时节点
	//int x;
	//scanf("%d", &x);
	//while (x != 999)
	for (int i = 0; i < 4; i++)
	{
		//输入值
		//1 初始化
		//2 初始化新节点
		//3 新节点头指针执行头节点
		//3 头节点尾指针指向新节点
		n = (DNode *)malloc(sizeof(DNode));
		n->data = i;
		n->piror = t;
		t->next = n; //尾节点指针指向新节点
		t = n; //尾节点替换
	}
	//t->next = NULL;
	return L;
}