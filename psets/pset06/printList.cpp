// bubble sort by idebtor@gmail.com
// This brute force version of bubble sort that takes O(n^2).
// 2019/02/02: Created
//
// Compilation:
// g++ bubble.cpp -o sort
// g++ bubble.cpp -o sort -DDEBUG
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// To make the function included in other program, turn #if 0 off.

#include <iostream>
using namespace std;
void _printList(int *list, int N, int max_print, int per_line)
{
	int count = 1;
	if(max_print <= per_line)
	{
		cout << "\t";
		for(int i = 0; i < max_print; i++)
			cout << list[i] << "\t";

		cout << endl;
		cout << "\t";

		for(int j = N - max_print; j < N; j++)
			cout << list[j] << "\t";
	}
	else
	{
		cout << "\t";
		for(int i = 0; i < max_print; i++)
		{
			cout << list[i] << "\t";
			if(count % per_line == 0)
			{
				cout << endl;
				cout << "\t";
				count = 0;
			}
			count++;
		}

		cout << endl;
		cout << "\t";
		count = 1;

		for(int j = N - max_print; j < N; j++)
		{
			cout << list[j] << "\t";
			if(count % per_line == 0)
			{
				cout << endl;
				cout << "\t";
				count = 0;
			}
			count++;
		}
	}
}

void printList(int *list, int N, int max_print, int per_line) {
	if(N <= max_print)
	{
		max_print = N / 2;
		_printList(list,N,max_print,per_line);
	}
	else
	{
		_printList(list,N,max_print,per_line);
	}
}
