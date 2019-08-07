#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class LinkNode
{
public:
	int data;//存放当前节点的数据
	LinkNode  * next;//指向下一个节点
	LinkNode(const int el, LinkNode  *ptr = 0){//构造函数 传入数据值以及下一个节点
		data = el;
		next = ptr;
	}
};
class LinkQueue
{
private:
	LinkNode *rear;     //指向尾巴节点
	LinkNode *front;    //指向头节点
public:
	bool IsEmpty(); //判断是否为空
	LinkQueue();    //构造函数 无参
	bool EnQueue(const int item);   //进入队列
	bool DeQueue(int & item);       //取出队列的头部元素并且删除 传入引用 这样就可以将取出来的值储存在item中
	int size;                       //当前储存元素的个数
};

bool LinkQueue::IsEmpty(){
	return front == NULL; //通过头结点是否为空来确定队列链表为不为空
}
LinkQueue::LinkQueue(){
	size = 0;             //初始化的时候size赋值为0 即队列链表为空
	front = rear = NULL;    //头结点和尾节点相等 且均指向空
}


bool LinkQueue::EnQueue(const int item)
{
	if (IsEmpty())   //当链表为空时开辟新节点 并且让头指针和尾指针均指向该节点
	{
		front = rear = new LinkNode(item, NULL);
	}
	else            //不为空的时候 开辟新节点，将尾指针往下移
	{
		rear->next = new LinkNode(item, NULL);
		rear = rear->next;
	}
	size++;         //储存的个数加1
	return true;
}

bool LinkQueue::DeQueue(int &item)
{
	LinkNode * temp;            //创建一个中间节点 来完成节点的删除
	item = front->data;         //取出头结点的data值 放在item中
	temp = front;
	front = front->next;        //删除当前front
	delete temp;
	if (IsEmpty())
	{
		return false;           //链表队列为空的时候返回false 删除失败
	}
	size--;                     //储存元素个数减1
	return true;
}

int main(int argc, const char * argv[]) {
	LinkQueue queue;
	int i = 0;
	for (; i <100;i++)
	{
		queue.EnQueue(i);
	} //生成该链表队列的过程
	while (queue.DeQueue(i))      //挨个取出链表队列的成员进行操作
	{
		cout << "value" << i << endl;
	}
	system("pause");
	return 0;
}