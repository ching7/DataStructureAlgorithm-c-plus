//�������Ա����󳤶�
#define InitSize 100

#include <iostream>
using namespace std;

//��̬����
//�ٶ�˳����ڵ�Ԫ����int
class SeqList
{
public:
	//˳����Ԫ��
	int *data; 
	//����
	int length, MaxSize1;
	SeqList(int ListSize)
	{
		this->data = (int*)malloc(sizeof(int)*ListSize);
	}
} ;

//��̬
class SqlList
{
public:
	//�̶�����3
	int data[3];
	int length;
	int MaxSize;
	SqlList( ) {
		//��ǰλ��
		this->length = 0;
		this->MaxSize = 3;
	}
} ;
/*
˳������
*/
bool ListInsert(SqlList &L,int i, int e)
{
	//����λ���Ƿ�Ϸ�
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	//˳����Ƿ�����
	if (L.length >= L.MaxSize)
	{
		return false;
	}
	//�Ӻ�i λ��Ԫ�غ���
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	//iλ�� ��������Ԫ��
	L.data[i - 1] = e;
	//˳�������
	L.length++;
	return true;
}
/*
˳���ɾ��
*/
bool ListDelete(SqlList &L, int i) {
	if (i<1 || i>L.length || L.length<=0)
	{
		return false;
	}
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.data[i+1] = NULL;
	L.length --;
	return true;
}
int main()
{
	//��̬��������	
	/*SeqList L;
	L.data = (Elemtype*)malloc(sizeof(Elemtype)*InitSize);*/
	SqlList seqList;
	/*seqList.ListInsert(1, 13);
	seqList.ListInsert(2, 23);
	seqList.ListInsert(3, 33);
	seqList.ListInsert(4, 43);*/
	ListInsert(seqList, 1, 13);
	ListInsert(seqList, 2, 23);
	ListInsert(seqList, 3, 33);
	ListDelete(seqList, 1);

	cout << "Hello, world!" << endl;
	return 0;
}


