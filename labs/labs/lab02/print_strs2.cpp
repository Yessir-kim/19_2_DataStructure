#include <iostream>
#include <vector>

using namespace std;

void print_strs(int n, char *strs[])
{    
	for(int i = 0; i < n; i++)
      		cout << strs[i] << endl;
}

void print_strs(int n, vector<string> v)
{
	for(int i = 0; i < n; i++)
		cout << v[i] << endl;
}
