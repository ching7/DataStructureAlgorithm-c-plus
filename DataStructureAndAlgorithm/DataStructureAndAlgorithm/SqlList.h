#pragma once
#define InitSize 100

/*
	˳��洢
*/

//�������Ա����󳤶�
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
};

//��̬
class SqlList
{
public:
	//�̶�����3
	int data[3];
	int length;
	int MaxSize;
	SqlList() {
		//��ǰλ��
		this->length = 0;
		this->MaxSize = 3;
	}
};
/*
˳������
*/
bool ListInsert(SqlList &L, int i, int e)
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
	if (i<1 || i>L.length || L.length <= 0)
	{
		return false;
	}
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.data[i + 1] = NULL;
	L.length--;
	return true;
}

/*
˳������,��ֵ����
*/
int ListFindElem(SqlList &L, int e) {
	if (L.length <= 0)
	{
		return 0;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}
