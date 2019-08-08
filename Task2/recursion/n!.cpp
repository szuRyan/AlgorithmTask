#include <iostream>  //一般阶乘都是在整数范围内的

using namespace std;

int recursion(int n)
{
	int result = 0;
	if( n==0 || n==1)
		return 1;
	else 
		result = recursion(n-1)*n;
	return result;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<n<<"!="<<recursion(n)<<endl;
	}
	return 0;
}