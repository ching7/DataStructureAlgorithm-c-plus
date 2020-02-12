#include "malloc.h"
typedef  int Elemtype;
//��ʽ����
//��ʽ���нڵ�
typedef struct LinkQueueNode {
	Elemtype data;
	struct LinkQueueNode *next;
};
//��ʽ����
typedef struct LinkQueue {
	LinkQueueNode *front, *rear;
};
//��ʽ���в���
typedef struct LinkQueueFuc {
	//��ʽ���г�ʼ��
	void initQueue(LinkQueue &Q)
	{
		//��ʼ������
		//����ͷ�ڵ�
		Q.front = Q.rear = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
		Q.front->next = NULL;//��ʼͷ�ڵ�Ϊ��
	}
	//�п�
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
	//�����
	bool enQueue(LinkQueue &Q,Elemtype val)
	{
		//1 �����ڵ�
		LinkQueueNode *s  = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
		s->data = val;
		s->next = NULL;
		//2����β����ֵ
		Q.rear->next = s;
		//3β�ڵ��ƶ�
		Q.rear = s;
		return true;
	}
	//������
	bool deQueue1(LinkQueue &Q, Elemtype &out)
	{
		//�жϿ�
		if (Q.front == Q.rear)
		{
			return false;
		}
		else
		{
			//1��ȡͷ�ڵ�
			LinkQueueNode *f = Q.front->next;
			//2��ȡ������ֵ
			out = f->data;
			//3�ƶ�ͷ�ڵ�
			Q.front->next = f->next;
			//4�ж��Ƿ�ֻ��һ��Ԫ��
			if (Q.rear == f)
			{
				Q.front = Q.rear;
			}
			free(f);
			return true;
		}
	}
};