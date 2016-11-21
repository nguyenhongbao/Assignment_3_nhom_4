#include "AVLTree.h"
using namespace std;

void E1()
{
	int n;
	cout << "Nhap N: ";	cin >> n;
	int *arr = new int[N];
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "arr[" << i + 1 << "]: ";
		cin >> arr[i];
	}
	for (int i = 0; i <= n - 1; i++)
	{
		AVLInsert(arr[i]);
	}
}