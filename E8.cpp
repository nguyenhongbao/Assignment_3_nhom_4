#include "Heap.h"
#include "InputReader.h"
using namesapce std;
void E8_problem(){
	int *arr;
	int count;
	if (ReadArrayInput("input/E8.txt", arr, count)){
		Heap myHeap;
		myHeap = myHeap.ArrayToHeap(arr, count);
		myHeap.PrintHeapTree();
		int h = (int)log2(count + 1) + 1; //height of tree
		int start = 0, end = 0;
		int sum;
		cout << "Trong so heap theo do cao:\n";
		for (int i = 0; i < h; i++){
			sum = 0; //rest sum
			end = pow(2, i) + start; // position to stop
			for (int j = start; j < end && j < count; j++){
				sum += myHeap[j];
				start = j + 1;
			}
			cout << "h = " << i << ": " << sum << endl;
		}
	}
};
