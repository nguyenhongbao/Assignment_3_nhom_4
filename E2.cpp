#include <iostream>
#include "AVLTree.h"
#include "InputReader.h"
#include <string.h>
#include <math.h>

#define FILE2 "e1.txt"
#define FILE3 "e3.txt"
using namespace std;

// E2
void DeleteAVL() {
	// doc file
	int* arr = NULL;
	int count = 0;
	bool Readed = ReadArrayInput(FILE2, arr, count);

	if (Readed) {
		// chuyen mang sang cay AVL
		AVLTree avltree = AVLTree();
		avltree = avltree.ArrayToAVL(arr, count);

		// vong lap xoa
		string numberstr = "0";
		int number = 0;
		avltree.PrintAVL();
		cout << "Moi ban nhap chi so cua node can xoa (neu khong muon xoa nua nhap -1) : ";
		cin >> numberstr;
		number = atoi(numberstr.c_str());
		while (number != -1) {
			if (!avltree.AVLDelete(number))
				cout << "chi so ban nhap khong co trong cay" << endl;
			avltree.PrintAVL();
			cout << "Moi ban nhap chi so cua node can xoa (neu khong muon xoa nua nhap -1) : ";
			cin >> numberstr;
			number = atoi(numberstr.c_str());
		}
	}
}

bool IsIng(int N) {
	bool ising = true;
	int max = (int)sqrt(N);
	for (int i = 3; i <= max; i++) {
		if (N % i == 0) {
			ising = false;
			break;
		}
	}
	return ising;
}

// ham de qui duyet cay va dem so chan le nguyen to
void LNRcount(Node*& subroot, int& even, int& odd, int& ing) {
	if (subroot) {
		LNRcount(subroot->left, even, odd, ing);
		// kiem tra so
		if (subroot->data > 0) {
			if (subroot->data % 2 == 0)
				even++;
			else {
				odd++;
				if (IsIng(subroot->data))
					ing++;
			}
			LNRcount(subroot->right, even, odd, ing);
		}
	}
}
// E3
void EvenOddIng() {
	// doc file
	int* arr = NULL;
	int count = 0;
	bool Readed = ReadArrayInput(FILE3, arr, count);
	if (Readed) {
		// chuyen mang sang cay AVL
		AVLTree avltree = AVLTree();
		avltree = avltree.ArrayToAVL(arr, count);
		int even = 0, odd = 0, ing = 0;
		LNRcount(avltree.root, even, odd, ing);
		cout << "Cay AVL nay co " << even << " so chan, " << odd << " so le va " << ing << " so nguyen to" << endl;
	}
}

int main() {
	EvenOddIng();
	system("pause");
	return 0;
}