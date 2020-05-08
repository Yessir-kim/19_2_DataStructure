#include <iostream>

using namespace std;

void print_strs(int n, char *strs[])
{
	cout << "argv[0] = " << strs[0] << endl;
	if(n == 1)
		cout << "Hello World!" << endl;
	else
	{
    for(int i = 1; i < n; i++)
      cout << strs[i] << endl;
	}
}
