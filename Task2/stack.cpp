#include <iostream>

using namespace std;

#define maxsize 100
typedef struct SeqStack  //definition of sequence stack 
{
	int data[maxsize];
	int top;
}SeqStack;

//initialization
void InitStack(SeqStack &st)
{
	st.top = -1;
}

bool isEmpty(SeqStack st)
{
	if (st.top == -1)
		return true;
	else
		return false;
}
bool isFull(SeqStack st)
{
	if (st.top == maxsize-1)
	{
		return true;
	}
	else
		return false;
}

void push(SeqStack &st, int a)
{
	if (!isFull(st))
	{
		st.top++;
		st.data[st.top] = a;
	}
	else
	{
		cout << "full stack" << endl;
	}
}

void pop(SeqStack &st)
{
	if (!isEmpty(st))
	{
		st.top--;
	}
	else
	{
		cout<<"empty stack"<<endl;
	}
}

//取栈顶元素
int Top(SeqStack &st)
{
	if (!isEmpty(st))
	{
		return st.data[st.top];
	}
	else
	{
		cout << " empty stack " << endl;
	}
}

void Destroy(SeqStack &st)
{
	st.top = -1;
}

//链栈节点的定义
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

//初始化链栈
void initLNodeStack(LNode *&LS)
{
	LS = new LNode;
	LS->next = NULL;
}
//链栈判断栈空
bool isLNodeEmpty(LNode *LS)
{
	if (LS->next == NULL)
		return true;
	else
		return false;
}
//链栈进栈
void pushLNode(LNode *&LS, int a)
{
	LNode *p = new LNode;
	p->data = a;
	p->next = LS->next;
	LS->next = p;
}
//链栈的出栈
void popLNode(LNode *&LS, int &a)
{
	if (!isLNodeEmpty(LS))
	{
		LNode *p = new LNode;
		p = LS->next;
		LS->next = p->next;
		a = p->data;
		delete p;
	}
	else
		cout << "empty stack" << endl;
}


int main()
{
	int i = 0;
	SeqStack st1;
	cout << "##############初始化栈##################" << endl;
	InitStack(st1);
	cout << "##############入栈操作##################" << endl;
	for (i = 0; i <= 100; i++)
	{
		push(st1, i);
	}
	cout << "################取栈顶元素#############" << endl;
	cout << "top" << Top(st1) << endl;
	cout << "################出栈操作###############" << endl;
	for (i = 0; i <= 90; i++)
	{
		pop(st1);
	}
	cout << "################取栈顶元素#############" << endl;
	cout << "top" << Top(st1) << endl;
	cout << "##################销毁栈###############" << endl;
	Destroy(st1);
	cout << "################取栈顶元素#############" << endl;
	cout << "top" << Top(st1) << endl;
	system("pause");
	return 0;
}