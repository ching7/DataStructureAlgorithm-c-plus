#include <iostream>
#include "SqlList.h"
#include "SLinkedList.h"
#include "DLinkedList.h"
using namespace std;

void main()
{
	//// 顺序表
	////动态设置容量	
	///*SeqList L;
	//L.data = (Elemtype*)malloc(sizeof(Elemtype)*InitSize);*/
	//SqlList seqList;
	///*seqList.ListInsert(1, 13);
	//seqList.ListInsert(2, 23);
	//seqList.ListInsert(3, 33);
	//seqList.ListInsert(4, 43);*/
	//ListInsert(seqList, 1, 13);
	//ListInsert(seqList, 2, 23);
	//ListInsert(seqList, 3, 33);
	//ListDelete(seqList, 1);
	//int res = ListFindElem(seqList, 23);

	////单链表
	//LinkedList L;
	////尾插法插入
	////ListHeadInsert(L);
	//ListTailInsert(L);
	////按位查找
	//LNode *m =GetElem(L, 2);
	////按值查找
	//LNode *m1 = GetElemByVal(L, 22);
	////按位插入
	//bool t1 = InsertListByIndex(L, 1,123);
	////按位删除
	//bool t2 =  DelNodeByIndex(L,1);
	////获取链表长度
	//int size = GetListSize(L);
	DLinKList L;
	initDLinKList(L);
}
