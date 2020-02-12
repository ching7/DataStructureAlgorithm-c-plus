#pragma once
#define MaxSizeSqStack 50

//顺序栈-参考顺序表
//typedef int Elemtype; // int 数据类型别名Elemtype，
typedef struct  {
	int data[MaxSizeSqStack];// 栈数据
	int top;//栈顶指针
} SqStack;

typedef struct  {
	//初始化栈
	void initStack(SqStack &s)
	{
		s.top = -1; //初始化栈顶指针
	}

	//栈空判断
	bool stackEmpty(SqStack s)
	{
		if (s.top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//进栈
	bool push(SqStack &s, int x)
	{
		//判断满
		if (s.top == MaxSizeSqStack - 1)
		{
			return false;
		}
		else
		{
			s.data[++s.top] = x;//先移动栈顶元素，再放入数据
			return true;
		}
	}
	//出栈
	bool pop(SqStack &s, int &x)
	{
		//判断空
		if (s.top == -1)
		{
			return false;
		}
		else
		{
			x = s.data[s.top--];//先取出栈顶元素，再移动栈顶指针
			return x;
		}
	}

	//获取栈顶元素
	bool getTop(SqStack s, int &x)
	{
		//判断空
		if (s.top == -1)
		{
			return false;
		}
		else
		{
			x = s.data[s.top];
			return true;
		}
	}

} SqStackFuc;
