#include <iostream>
#include "SqlList.h"
#include "SLinkedList.h"
#include "DLinkedList.h"
using namespace std;

void main()
{
	//// ˳���
	////��̬��������	
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

	////������
	//LinkedList L;
	////β�巨����
	////ListHeadInsert(L);
	//ListTailInsert(L);
	////��λ����
	//LNode *m =GetElem(L, 2);
	////��ֵ����
	//LNode *m1 = GetElemByVal(L, 22);
	////��λ����
	//bool t1 = InsertListByIndex(L, 1,123);
	////��λɾ��
	//bool t2 =  DelNodeByIndex(L,1);
	////��ȡ������
	//int size = GetListSize(L);
	DLinKList L;
	initDLinKList(L);
}
