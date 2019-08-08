//最直观的做法 按照公式直接写代码

long long Fibonacci (unsigned int n)
{
	if(n<0)
		return 0;
	if(n==1)
		return 1;
	retrun Fibonacci(n-1)+Fibonacci(n-2);
}

//上述代码会导致大量重复计算，提出改进算法如下

long long Fibonacci(unsigned n)
{
	int result[2] = {0,1};
	if(n<2)
		return result[n];
	long long fib_n_one = 1;
	long long fib_n_two = 0;
	long long fibM = 0;
	for (unsigned int i =2;i<+n;++i)
	{
		fibM = fib_n_one+fib_n_two;
		fib_n_two = fib_n_one;
		fib_n_one = fibM;
	}
	return fibM;
}