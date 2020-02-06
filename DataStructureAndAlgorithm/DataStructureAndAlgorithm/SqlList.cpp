//定义线性表的最大长度
#define InitSize 100

#include <iostream>
using namespace std;

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
} ;

//静态
class SqlList
{
public:
	//固定容量3
	int data[3];
	int length;
	int MaxSize;
	SqlList( ) {
		//当前位置
		this->length = 0;
		this->MaxSize = 3;
	}
} ;
/*
顺序表插入
*/
bool ListInsert(SqlList &L,int i, int e)
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
	//动态设置容量	
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


