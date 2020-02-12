#pragma once
#define _CRT_SECURE_NO_WARNINGS
//������ڵ�
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkedList;

//������
//ͷ�巨����������
LinkedList ListHeadInsert(LinkedList &L)
{
	int x;
	LNode *s; //��ʱ�ڵ�
	L = (LinkedList)malloc(sizeof(LNode)); //��ʼ������,����Lͷ�ڵ�
	L->next = NULL;
	scanf("%d", &x);
	while (x!=999)
	{
		s = (LNode *)malloc(sizeof(LNode)); //�����½ڵ�
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//β�巨
LinkedList ListTailInsert(LinkedList &L) 
{
	int x; //����ֵ
	LNode *s; //��ʱ�ڵ�
	L = (LinkedList)malloc(sizeof(LNode));
	LNode *r = L; //rΪβ�ڵ�
	scanf("%d", &x);
	while (x!=999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//����Ų��ҵ�����
LNode * GetElem(LinkedList L,int i) 
{
	int j = 1;//��ʼλ��
	LNode *p = L->next; //ͷ�ڵ�ָ��
	if (i == 0)
	{
		return NULL;
	}
	if (i==1)
	{
		return p;
	}
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ����
LNode * GetElemByVal(LinkedList L, int i)
{
	LNode *p = L->next; //ͷ�ڵ�ָ��
	while (p!=NULL)
	{
		if (p->data == i)
		{
			return p;
		}
		p = p->next;
	}
}

//����λ�ò���
bool InsertListByIndex(LinkedList &L , int index,int val) 
{
	if (index !=1)
	{
		//�Ǳ�ͷ����
		//1 ���Ҳ���λ��ǰ���ڵ��Ƿ����
		LNode *p = GetElem(L, index - 1);
		if (p)
		{
			//2����ǰ��λ�ô���
			LNode *s = (LNode *)malloc(sizeof(LNode));//�½ڵ�
			s->data = val;
			s->next = p->next;
			p->next = s;
			return true;
		}
		else
		{
			return false;
		}
	}
	else 
	{
		//��ͷ����
		LNode *s = (LNode *)malloc(sizeof(LNode)) ;//�½ڵ�
		s->data = val;
		s->next = L->next;
		L->next = s;
		return true;
	}


}

//����ڵ�ɾ��
bool DelNodeByIndex(LinkedList &L, int index)
{

	if (index != 1)
	{
		//�Ǳ�ͷɾ��
		//1�ж�ɾ���ڵ�ǰ���Ƿ����
		LNode *p = GetElem(L, index - 1);
		if (p)
		{
			//2ɾ���ڵ�q
			LNode *q = p->next;
			p->next = q->next;
			free(q);
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		//��ͷɾ��
		LNode *q = L->next;
		L->next =q->next;
		free(q);
		return true;
	}
}

//��ȡ������
int GetListSize(LinkedList L)
{
	int count = 0;
	LNode * s = L->next;// ��ȡͷ�ڵ�
	while (s)
	{
		count++;
		s = s->next;
	}
	return count;
}