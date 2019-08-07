#include <iostream>
using namespace std;
class Queue{
private:
	int *data;              //定义指向整型的指针，从而动态开辟内存
	int head, tail, length, count;   //head指向队首,tail指向队尾,length表示队列的长度,count用于记录队列中元素个数,从而判断队列是否已满
public:
	Queue(int length_input){       //构造函数,对新声明的队列对象进行初始化
		data = new int[length_input];      //动态开辟100个整型数据的空间
		length = length_input;              //为队列的长度赋初始值
		head = 0;                       //起初head为0，表示head值未改变的情况下,一直指向首元素
		tail = -1;                      //tail初始值为-1，表示此时队列为空,无任何数据元素
		count = 0;
	}
	~Queue(){
		delete[] data;             //析构函数,删除动态开辟的内存
	}
	void push(int element){            //入队操作,只能从队列的尾部插入数据元素
		if (count < length){             //队列未满的时候才能插入,否则则插入失败
			tail = (tail + 1) % length;     //分两种情况,如果队尾指针此时并未指向队列的最后一位,那么队尾指针直接前移,而当队尾指针此时指向最后一位时
			data[tail] = element;           //那么当队列未满时,则队尾指针将跳转至数组起始位置，再将数据元素插入队尾指针指向的位置
			++count;                    //入队成功,队列中元素数量加一
		}
	}
	void pop(){
		if (count < 0){     //队列为空,出队失败
			return;
		}
		head = (head + 1) % length;         //同样,根据循环队列的性质得出
		--count;            //出队成功,队列中元素数量减一
	}
	int top(){
		if (count > 0){      //队列不为空的情况下才能获取队首元素
			return data[head];
		}
	}
	void output(){
		for (int i = head; i != tail + 1; i = (i + 1) % length){     //从队首一直遍历到队尾,当遍历到最后一位时,跳转至数组起始位置
			//特别注意此时循环截止的条件应该是i != tail + 1，因此可能tail的值小于head
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	Queue queue(100);               //声明一个队列对象,并初始化
	for (int i = 1; i <= 10; ++i){
		queue.push(i);             //将1-10这10个数据元素依次插入队列中
	}
	queue.output();             //调用输出的方法
	cout << "当前的队首元素为:" << queue.top() << endl;
	queue.pop();               //出队
	queue.output();             //调用输出的方法
	cout << "出队操作后的队首元素为:" << queue.top() << endl;
	system("pause");
	return 0;
}