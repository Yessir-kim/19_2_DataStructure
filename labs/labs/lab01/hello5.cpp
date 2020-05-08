// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 1:
//  - C and C++ coding using g++
//  - a new line escape character and endl manipulator
//  - `using namespace std;`
//  - Understanding `int main(int argc, char *argv[])`
//  - Using functions and prototype
//  - Compiling multiple source files
//
// The following command line compiles a source files and builds
// an executable a.exe or with a given name. Modify it as you need
// 		g++ hello.cpp
//		./a john paul david
//		g++ hello.cpp -o hello
//		./hello john paul david

#include <iostream>
using namespace std;

// print argc & *argv[]

void print_strs(int n, char *strs[])
{
	cout << "argv[0] = " << strs[0] << endl;
	if(n == 1)
		cout << "Hello World!" << endl;
	else
	{
    for(int i = 1; i <= n; i++)
      cout << "Hello " << strs[i] << endl;
	}
}

int main(int argc, char *argv[])
{
	print_strs(argc, argv);
	return 0;
}
