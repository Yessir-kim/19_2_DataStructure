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
#include <time.h>
#include <algorithm>

using namespace std;

void S_sort(int *list, int n) {
	int i, j, min, temp;
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
		printf("%d ", list[i]);
	printf("\n");
}

int main(int argc, char *argv[]) {
//	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int n;

  cout << "Enter a number of samples to sort : ";
  cin >> n;

	if(n < 2)
	{
		cout << "The number must be greater than 1.";
		exit(0);
	}
	
	int *list = new int[n];

	srand(time(NULL));

	for(int k = 0; k < n; k++)
		list[k] = rand() % 10;

	printf("UNSORTED(%d): \n", n);
	printList(list, n);

	S_sort(list, n);

	printf("SORTED(%d): \n", n);
	printList(list, n);

	printf("Happy Coding~~\n");

	delete[] list;
}
