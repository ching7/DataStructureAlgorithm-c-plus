#define MaxSizeSqlQueue 50
typedef int Elemtype;
//˳��ѭ������
typedef struct SqlQueue {
	Elemtype data[MaxSizeSqlQueue]; //����Ԫ��
	int front, rear; //��ͷ��βλ��
};
//˳��ѭ�����л�������
typedef struct SqlQueueFuc
{
	//��ʼ��
	void initQueue(SqlQueue &Q)
	{
		Q.front = Q.rear = 0;
	}
	//�жϿ�
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
	//�ж���
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
	//�����
	bool enQueue(SqlQueue &Q, Elemtype val)
	{
		//1�ж���
		if (!(isFull(Q)))
		{
			//2��������ֵ
			Q.data[Q.rear] = val;
			//3βλ�ú���
			Q.rear = (Q.rear+1)%MaxSizeSqlQueue;
			return true;
		}
		else
		{
			return false;
		}
	}
	//������
	bool deQueue(SqlQueue &Q, Elemtype &val)
	{
		//1�жϿ�
		if (!(isEmpty(Q)))
		{
			//2�ǿգ���ֵ
			val = Q.data[Q.front] ;
			//3ͷλ�ú���
			Q.front = (Q.front + 1)%MaxSizeSqlQueue;
			return true;
		}
		else
		{
			return false;
		}
	}
};