#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MaxSizeSqStack 50
#include "malloc.h"

//顺序栈-参考顺序表
//typedef int Elemtype; // int 数据类型别名Elemtype，
typedef struct  {
	int data[MaxSizeSqStack];// 栈数据
	int top;//栈顶指针
} SqStack;
//顺序栈操作
typedef struct  {
	//初始化栈
	void initStack(SqStack &s)
	{
		s.top = -1; //初始化栈顶指针
	}

	//栈空判断
	bool stackEmpty(SqStack s)
	{
		if (s.top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//进栈
	bool push(SqStack &s, int x)
	{
		//判断满
		if (s.top == MaxSizeSqStack - 1)
		{
			return false;
		}
		else
		{
			s.data[++s.top] = x;//先移动栈顶元素，再放入数据
			return true;
		}
	}
	//出栈
	bool pop(SqStack &s, int &x)
	{
		//判断空
		if (s.top == -1)
		{
			return false;
		}
		else
		{
			x = s.data[s.top--];//先取出栈顶元素，再移动栈顶指针
			return x;
		}
	}

	//获取栈顶元素
	bool getTop(SqStack s, int &x)
	{
		//判断空
		if (s.top == -1)
		{
			return false;
		}
		else
		{
			x = s.data[s.top];
			return true;
		}
	}

} SqStackFuc;

//单链式栈
typedef struct LinkStackNode
{
	int data;//当前节点值
	struct LinkStackNode *next;//下个节点地址
} LinkStackNode,*LinkStack;

//链式栈操作
typedef struct LinkStackFuc
{
	void initLinkStack(LinkStack &L)
	{
		//1初始化链式栈
		LinkStackNode *s; //临时节点
		L =(LinkStack)malloc(sizeof(LinkStackNode)); //初始化链式栈 
		//LinkStackNode *t = L; //t为栈底
		for (int i = 0; i < 4; i++)
		{
			s = (LinkStackNode *)malloc(sizeof(LinkStackNode));
			s->data = i;
			s->next = L;
			L = s; //入栈新增
			//t = s; //移动栈底
		}
	};
}LinkStackFuc;
