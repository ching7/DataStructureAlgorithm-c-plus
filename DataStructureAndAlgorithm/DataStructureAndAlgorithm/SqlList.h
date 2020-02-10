#pragma once
#define InitSize 100

/*
	顺序存储
*/

//定义线性表的最大长度
//动态容量
//假定顺序表内的元素是int
class SeqList
{
public:
	//顺序表的元素
	int *data;
	//长度
	int length, MaxSize1;
	SeqList(int ListSize)
	{
		this->data = (int*)malloc(sizeof(int)*ListSize);
	}
};

//静态
class SqlList
{
public:
	//固定容量3
	int data[3];
	int length;
	int MaxSize;
	SqlList() {
		//当前位置
		this->length = 0;
		this->MaxSize = 3;
	}
};
/*
顺序表插入
*/
bool ListInsert(SqlList &L, int i, int e)
{
	//插入位置是否合法
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	//顺序表是否以满
	if (L.length >= L.MaxSize)
	{
		return false;
	}
	//从后到i 位置元素后移
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	//i位置 插入新增元素
	L.data[i - 1] = e;
	//顺序表新增
	L.length++;
	return true;
}
/*
顺序表删除
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
顺序表查找,按值查找
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
