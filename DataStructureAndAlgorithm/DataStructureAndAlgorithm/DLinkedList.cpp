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
		//4 头节点尾指针指向新节点
		//5 尾节点替换
		n = (DNode *)malloc(sizeof(DNode));
		n->data = i;
		n->piror = t;
		t->next = n; //尾节点指针指向新节点
		t = n; //尾节点替换
	}
	t->next = NULL; // 注意尾指针的置空，否则无法判断链表是否为空
	return L;
}

//序号查找
DNode * getElemByIndex(DLinKList L,int index)
{
	int cursor = 1;
	DNode *t = L->next; // 尾节点
	while (t && cursor<index)
	{
		t = t->next;
		cursor++;
	}
	return t;
}

//按值查找
DNode * getElemByVal(DLinKList L, int val)
{
	DNode *t = L->next; // 尾节点
	while (t && t->data!= val)
	{
		t = t->next;
	}
	return t;
}

//位置插入
bool insertDLinkList(DLinKList &L,int index,int val)
{
	if (index>1)
	{
		//非插入头节点
		//1 查找插入前驱节点是否存在
		DNode * pirorNode = getElemByIndex(L, index - 1);
		if (pirorNode)
		{
			//2新增节点
			DNode * insertNode = (DNode *)malloc(sizeof(DNode));
			//3插入节点
			DNode *midNode = pirorNode->next;
			// 新增节点赋值
			insertNode->data = val;
			insertNode->next = midNode;
			//移动节点位置
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
		//插入头节点
		// 1 新建节点
		DNode * insertNode = (DNode *)malloc(sizeof(DNode));
		insertNode->data = val;
		//2 头节点替换
		DNode *headNode = L->next;
		insertNode->piror = L; 
		insertNode->next = headNode;
		headNode->piror = insertNode;
		//链表头
		L->next = insertNode;
		return true;
	}
}

//位置删除
bool delDLinkList(DLinKList &L, int index)
{
	if (index>1)
	{
		//非表头删除
		//1删除位置前驱节点是否存在
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
		//表头删除
		DNode *headNode = L->next; //表头
		L->next = headNode->next;
		headNode->next->piror = L;
		free(headNode);
		return true;
	}
	
}