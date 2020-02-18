#include <iostream>
#include "SqlList.cpp"
#include "SLinkedList.cpp"
#include "DLinkedList.cpp"
#include "SqlStack.cpp"
#include "LinkQueue.cpp"
#include "SqQueue.cpp"
#include "BitNode.cpp"
using namespace std;
int main()
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

	////双链表
	//DLinKList L;
	////双链表尾插法初始化
	//initDLinKList(L);
	////按位查找
	//DNode  *res = getElemByIndex(L,6);
	////按值查找
	//DNode  *res1 = getElemByVal(L, 12);
	////插入
	//bool res3 = insertDLinkList(L, 1,1112);
	//bool res4 = insertDLinkList(L,2, 1113);
	////删除
	//bool res5 = delDLinkList(L, 1);
	//bool res6 = delDLinkList(L, 2);

	////顺序栈
	//SqStack sqStack;
	//SqStackFuc sqStackFuc;
	////初始化栈
	//sqStackFuc.initStack(sqStack);
	////入栈
	//sqStackFuc.push(sqStack, 1);
	//sqStackFuc.push(sqStack, 2);
	////出栈
	//int x;
	//sqStackFuc.pop(sqStack, x);
	//sqStackFuc.push(sqStack, 3);
	////获取栈顶
	//sqStackFuc.getTop(sqStack, x);

	////链式栈
	//LinkStack lStack;
	//LinkStackFuc lStackFuc;
	//lStackFuc.initLinkStack(lStack);

	//循环队列
	/*SqlQueue sqlQueue;
	SqlQueueFuc sqlQueueFuc;
	sqlQueueFuc.initQueue(sqlQueue);
	sqlQueueFuc.enQueue(sqlQueue, 1);
	sqlQueueFuc.enQueue(sqlQueue, 2);
	sqlQueueFuc.enQueue(sqlQueue, 3);
	int out;
	sqlQueueFuc.deQueue(sqlQueue, out);*/

	////链式队列
	//LinkQueue q;
	//LinkQueueFuc LQFuc;
	//LQFuc.initQueue(q);
	//LQFuc.enQueue(q, 1);
	//LQFuc.enQueue(q, 2);
	//int out;
	//LQFuc.deQueue(q, out);
	//LQFuc.deQueue(q, out);
	//LQFuc.deQueue(q, out);
	//return 0;

	//链式二叉树
	BiTree bitree = NULL; //空树
	BitTreeFuc bitreeFuc;
	//插入
	bitreeFuc.insertBiTree(bitree, 10);
	bitreeFuc.insertBiTree(bitree, 9);
	bitreeFuc.insertBiTree(bitree, 6);
	bitreeFuc.insertBiTree(bitree, 7);
	bitreeFuc.insertBiTree(bitree, 8);
	//前序
	//bitreeFuc.PreOrder(bitree);
	//中序
	//bitreeFuc.InOrder(bitree);
	//后序
	bitreeFuc.PostOrder(bitree);

}
