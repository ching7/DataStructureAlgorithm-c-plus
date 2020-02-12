#define MaxSizeSqlQueue 50
typedef int Elemtype;
//顺序循环队列
typedef struct SqlQueue {
	Elemtype data[MaxSizeSqlQueue]; //队列元素
	int front, rear; //对头队尾位置
};
//顺序循环队列基本操作
typedef struct SqlQueueFuc
{
	//初始化
	void initQueue(SqlQueue &Q)
	{
		Q.front = Q.rear = 0;
	}
	//判断空
	bool isEmpty(SqlQueue Q)
	{
		if (Q.rear = Q.front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//判断满
	bool isFull(SqlQueue Q)
	{
		if ((Q.rear+1)%MaxSizeSqlQueue == Q.front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//入队列
	bool enQueue(SqlQueue &Q, Elemtype val)
	{
		//1判断满
		if (!(isFull(Q)))
		{
			//2非满，插值
			Q.data[Q.rear] = val;
			//3尾位置后移
			Q.rear = (Q.rear+1)%MaxSizeSqlQueue;
			return true;
		}
		else
		{
			return false;
		}
	}
	//出队列
	bool deQueue(SqlQueue &Q, Elemtype &val)
	{
		//1判断空
		if (!(isEmpty(Q)))
		{
			//2非空，出值
			val = Q.data[Q.front] ;
			//3头位置后移
			Q.front = (Q.front + 1)%MaxSizeSqlQueue;
			return true;
		}
		else
		{
			return false;
		}
	}
};