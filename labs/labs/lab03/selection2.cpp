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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

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
	int *list;
	const int N = 10;

	list = (int*)malloc(sizeof(int)*N);

	assert(list != nullptr); // NULL은 c에서 나온 것인데 0을 나타냄 
				 // nullptr은 pointer 그 자체이고 NULL은 상수 값으로 인식됨 

	srand(time(NULL));

	for(int k = 0; k < N; k++)
		list[k] = rand() % 10;

	printf("UNSORTED(%d): \n", N);
  printList(list, N);

	S_sort(list, N);

	printf("SORTED(%d): \n", N);
  printList(list, N);

  printf("Happy Coding~~\n");
	free(list);
}
