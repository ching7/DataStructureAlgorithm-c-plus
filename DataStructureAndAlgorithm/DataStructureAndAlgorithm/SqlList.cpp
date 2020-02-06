#define MaxSize 50
#include <iostream>
typedef int  Elemtype;
typedef struct
{
	Elemtype data[MaxSize];
	int length;
} SqlList;
using namespace std;
int main()
{
	SqlList sqlList = {NULL,10};

	cout << "Hello, world!" << endl;
	return 0;
}

