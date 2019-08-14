#include <iostream>

using namespace std;

void Naive_String_Matching(string T, string P)
{
	int n = T.size();
	int m = P.size();
	int i;
	for (int s = 0; s<n - m; s++)
	{
		for (i = 0; i<m; i++)
		{
			if (P[i] != T[s + i])
			{
				break;
			}
		}
		if (i == m)
		{
			cout << "pattern occurs with shift  " << s << endl;
		}
	}
}


void main()
{
	string T = "BBC ABCDAB ABCDABCDABDEFABCDABDff";
	string P = "ABCDABD";
	cout << "NAIVE:" << endl;
	Naive_String_Matching(T, P);
	system("pause");
}