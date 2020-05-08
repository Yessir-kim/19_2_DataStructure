// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file

#include<iostream>
#include<vector>
using namespace std;

void print_strs2(int n, char *strs[]);

int main(int argc, char *argv[]) {

	cout << "Using char arrays \n";
	print_strs2(argc - 1, &argv[1]);

	// copy *argv[] to a vector<string> object; use push_back() method (or
	// member function) in the vector class

	cout << "Copy *argv[] using vector<string> \n";
	// your code here
	vector<string> str_arr;

	for(int i = 1; i < argc; i++)
		str_arr.push_back(argv[i]);

	cout << "Print argv using indexing \n";
	for(int i = 0; i < int(str_arr.size()); i++)
		cout << str_arr[i] << endl;

	return 0;
}
