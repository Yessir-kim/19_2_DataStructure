// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
//	selection.cpp - This brute force version of Selection Sort that takes O(n^2).
/*************************************************************
    Lab03 - Understanding a better coding in C/C++
    - NMN(No magic number)
    - DRY(Don't repeat yourself)
    - malloc(), free()
    - assert()
    - rand()
    - mod operator %
    - #if macro
    - Learn about __a better coding__ after all.
***************************************************************/
#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

void S_sort(int *list, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min]) min = j;
		swap(list[i], list[min]); // Swap min found with the 1st data unsorted
	}
}

void printList(int *list, int n)
{
	for(int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[]) {
//	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	long n;

	if(argc != 1)
	{
		n = strtol(argv[1],NULL,10);
		if(n < 2 || argc > 2)
		{
			cout << "Usage : selection [N]" << endl;
			exit(0);
		}
	}
	else
	{
		while (n < 2) {
				cout << "Enter a number of samples : ";
				cin >> n;
				if(n < 2)
					cout << "Retry..." << endl;
		}
	}

	int *list = new int[n];

	srand(static_cast<unsigned int>(time(0)));

	for(int k = 0; k < n; k++)
		list[k] = rand() % 10;

	cout << "UNSORTED(" << n << "): " << endl;
	printList(list, n);

	S_sort(list, n);

	cout << "SORTED(" << n << "): " << endl;
	printList(list, n);

	cout << "Happy Coding~~" << endl;

	delete[] list;
}
