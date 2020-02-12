#pragma once
#define _CRT_SECURE_NO_WARNINGS
//单链表节点
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkedList;

//单链表
//头插法创建单链表
LinkedList ListHeadInsert(LinkedList &L)
{
	int x;
	LNode *s; //临时节点
	L = (LinkedList)malloc(sizeof(LNode)); //初始化链表,创建L头节点
	L->next = NULL;
	scanf("%d", &x);
	while (x!=999)
	{
		s = (LNode *)malloc(sizeof(LNode)); //创建新节点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//尾插法
LinkedList ListTailInsert(LinkedList &L) 
{
	int x; //输入值
	LNode *s; //临时节点
	L = (LinkedList)malloc(sizeof(LNode));
	LNode *r = L; //r为尾节点
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

//按序号查找单链表
LNode * GetElem(LinkedList L,int i) 
{
	int j = 1;//初始位置
	LNode *p = L->next; //头节点指针
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

//按值查找
LNode * GetElemByVal(LinkedList L, int i)
{
	LNode *p = L->next; //头节点指针
	while (p!=NULL)
	{
		if (p->data == i)
		{
			return p;
		}
		p = p->next;
	}
}

//链表位置插入
bool InsertListByIndex(LinkedList &L , int index,int val) 
{
	if (index !=1)
	{
		//非表头插入
		//1 查找插入位置前驱节点是否存在
		LNode *p = GetElem(L, index - 1);
		if (p)
		{
			//2插入前驱位置存在
			LNode *s = (LNode *)malloc(sizeof(LNode));//新节点
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
		//表头插入
		LNode *s = (LNode *)malloc(sizeof(LNode)) ;//新节点
		s->data = val;
		s->next = L->next;
		L->next = s;
		return true;
	}


}

//链表节点删除
bool DelNodeByIndex(LinkedList &L, int index)
{

	if (index != 1)
	{
		//非表头删除
		//1判断删除节点前驱是否存在
		LNode *p = GetElem(L, index - 1);
		if (p)
		{
			//2删除节点q
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
		//表头删除
		LNode *q = L->next;
		L->next =q->next;
		free(q);
		return true;
	}
}

//获取链表长度
int GetListSize(LinkedList L)
{
	int count = 0;
	LNode * s = L->next;// 获取头节点
	while (s)
	{
		count++;
		s = s->next;
	}
	return count;
}