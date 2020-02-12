#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MaxSizeSqStack 50
#include "malloc.h"

//˳��ջ-�ο�˳���
//typedef int Elemtype; // int �������ͱ���Elemtype��
typedef struct  {
	int data[MaxSizeSqStack];// ջ����
	int top;//ջ��ָ��
} SqStack;
//˳��ջ����
typedef struct  {
	//��ʼ��ջ
	void initStack(SqStack &s)
	{
		s.top = -1; //��ʼ��ջ��ָ��
	}

	//ջ���ж�
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

	//��ջ
	bool push(SqStack &s, int x)
	{
		//�ж���
		if (s.top == MaxSizeSqStack - 1)
		{
			return false;
		}
		else
		{
			s.data[++s.top] = x;//���ƶ�ջ��Ԫ�أ��ٷ�������
			return true;
		}
	}
	//��ջ
	bool pop(SqStack &s, int &x)
	{
		//�жϿ�
		if (s.top == -1)
		{
			return false;
		}
		else
		{
			x = s.data[s.top--];//��ȡ��ջ��Ԫ�أ����ƶ�ջ��ָ��
			return x;
		}
	}

	//��ȡջ��Ԫ��
	bool getTop(SqStack s, int &x)
	{
		//�жϿ�
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

//����ʽջ
typedef struct LinkStackNode
{
	int data;//��ǰ�ڵ�ֵ
	struct LinkStackNode *next;//�¸��ڵ��ַ
} LinkStackNode,*LinkStack;

//��ʽջ����
typedef struct LinkStackFuc
{
	void initLinkStack(LinkStack &L)
	{
		//1��ʼ����ʽջ
		LinkStackNode *s; //��ʱ�ڵ�
		L =(LinkStack)malloc(sizeof(LinkStackNode)); //��ʼ����ʽջ 
		//LinkStackNode *t = L; //tΪջ��
		for (int i = 0; i < 4; i++)
		{
			s = (LinkStackNode *)malloc(sizeof(LinkStackNode));
			s->data = i;
			s->next = L;
			L = s; //��ջ����
			//t = s; //�ƶ�ջ��
		}
	};
}LinkStackFuc;
