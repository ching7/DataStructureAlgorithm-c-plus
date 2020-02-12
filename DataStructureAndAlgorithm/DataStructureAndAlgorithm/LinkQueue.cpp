#include "malloc.h"
typedef  int Elemtype;
//链式队列
//链式队列节点
typedef struct LinkQueueNode {
	Elemtype data;
	struct LinkQueueNode *next;
};
//链式队列
typedef struct LinkQueue {
	LinkQueueNode *front, *rear;
};
//链式队列操作
typedef struct LinkQueueFuc {
	//链式队列初始化
	void initQueue(LinkQueue &Q)
	{
		//初始化队列
		//建立头节点
		Q.front = Q.rear = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
		Q.front->next = NULL;//初始头节点为空
	}
	//判空
	bool isEmpty(LinkQueue Q)
	{
		if (Q.front == Q.rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//入队列
	bool enQueue(LinkQueue &Q,Elemtype val)
	{
		//1 新增节点
		LinkQueueNode *s  = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
		s->data = val;
		s->next = NULL;
		//2队列尾插入值
		Q.rear->next = s;
		//3尾节点移动
		Q.rear = s;
		return true;
	}
	//出队列
	bool deQueue1(LinkQueue &Q, Elemtype &out)
	{
		//判断空
		if (Q.front == Q.rear)
		{
			return false;
		}
		else
		{
			//1获取头节点
			LinkQueueNode *f = Q.front->next;
			//2获取出队列值
			out = f->data;
			//3移动头节点
			Q.front->next = f->next;
			//4判断是否只有一个元素
			if (Q.rear == f)
			{
				Q.front = Q.rear;
			}
			free(f);
			return true;
		}
	}
};