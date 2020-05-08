/*
* Lecture Note by idebtor@gmail.com
*
* This program is written to run the sort algorithms.
* It takes the number of data samples to sort from the user.
* Then, the int array is created and filled with random numbers.
* User may selection one of sort functions to be used. Then
* execution time and its output is displayed.
*
* History:
* 02/10/19:		Created in C++
*
* Before Compilation, you must have some files (static library and
* include file) ready as shown below:
*   src/selection.cpp, bubble.cpp ...
*   include/nowic.h
*	lib/libnowic.a        (nowic.lib for Visual Studio)
* Compilation:
*	g++ selection.cpp insertion.cpp quicksort.cpp bubble.cpp
*       sortDriver.cpp -I../include -L../lib -lnowic -o sort
*/

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);
void (*sortFn) (int *, int);

void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	int random;
	srand((unsigned)time(NULL));

	for(int i = 0; i < n; i++)
	{
	  do
		{
	  	random = rand() % 10;
	  } while(random > n);

		swap(list[i], list[random]);
	}
	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
//

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
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)
	if(N <= max_print)
	{
		max_print = N / 2;
		_printList(list,N,max_print,per_line);
	}
	else
	{
		_printList(list,N,max_print,per_line);
	}
	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	char line_copy;
	sortFn = selectionSort;
	DPRINT(cout << ">main...N=" << N << endl;)

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\ts - sort()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)
			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {

			// your code here
			case 'b':
				algorithm_chosen = BUBBLE;
				sortFn = bubbleSort;
				break;
			case 'i':
				algorithm_chosen = INSERTION;
				sortFn = insertionSort;
				break;
			case 's':
			 	algorithm_chosen = SELECTION;
				sortFn = selectionSort;
				break;
			case 'q':
				algorithm_chosen = QUICKSORT;
				sortFn = quickSort;
				break;

			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}
			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");
			if (keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}
			else
			{
				N = keyin; // set N with the new keyin value
				if(list != NULL) // before allocating the new list, free the old list if not NULL
					delete[] list;
				list = new int[N]; // allocate memory for new data samples
				assert(list != nullptr);
				for(int i = 0; i < N; i++)
					list[i] = i;
				printList(list, N, max_print, per_line);
				break;
			}

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}
			randomized = 'Y';
			randomize(list,N);
			printList(list, N, max_print, per_line);
			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			randomized = 'N';
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();

			sortFn(list, N);

			end = clock();

			printList(list, N, max_print, per_line);
			cout << "\n\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)
			max_print = GetInt("\tEnter max sample size to display: ");
			printList(list, N, max_print, per_line);
			break;

		case 'd': DPRINT(cout << "case = " << option_char << endl;)
			line_copy = per_line;
			per_line = GetInt("\tEnter max sample per line to display: ");
			if(per_line > 0)
			{
				printList(list, N, max_print, per_line);
				break;
			}
			per_line = line_copy;
			cout << "\tExpecting a number larger than 0\n"; break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) delete[] list;
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}
