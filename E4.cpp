#include "Heap.h"
using namespace std;
void E4_problem(){
	int N = 0;
	while (N < 1)
	{
		cout << "Nhap so phan tu cua mang:" << endl;
		cin >> N;
	}
	int *arr = new int[N];
	for (int i = 0; i < N; i++){
		cout << "Nhap so phan tu arr[" << i <<"]:" << endl;
		cin >> arr[i];
	}
	Heap p;
	for (int i = 0; i < N; i++)
		p.InsertHeap(arr[i]);
	cout << "Heap duoc tao thanh:\n";
	p.PrintHeapTree();
}
