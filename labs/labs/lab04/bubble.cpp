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

#ifdef DEBUG
#define DPRINT(func) func; //DPRINT(func)형식의 문장을 만나면 func;로 대체해라
#else
#define DPRINT(func) ; // DPRINT(func)형식의 문장을 만나면 ;으로 대체해라
#endif

void bubbleSort(int *list, int n) {
	DPRINT(cout << "BUBBLE SORTING...\n");
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) // last i elements are already in place
			if (list[j + 1] < list[j])
				swap(list[j + 1], list[j]);
		DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
	}
}

#if 1 // 1 is "true" 그래서 #if 1 ~ #endif 사이의 문장이 실행됨
			// 만약 0인 경우 실행되지 않음 
void printList(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main() {
	int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8};
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	printList(list, N);

	bubbleSort(list, N);

	cout << "BUBBLE SORTED: " << endl;
	printList(list, N);
}
#endif
