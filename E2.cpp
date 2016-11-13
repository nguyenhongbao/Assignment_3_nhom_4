#include <iostream>
#include "AVLTree.h"
#include "InputReader.h"
#include "Graph.h"
#include "Stack.h"
#include <string.h>
#include <math.h>

#define FILE2 "e1.txt"
#define FILE3 "e3.txt"
#define FILE11 "e11.txt"
#define FILE16 "e16.txt"
using namespace std;

struct BoolLinked {
	bool data;
	BoolLinked* next;
};

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

// ham MakeGraph tao graph tu 2 mang luu thong tin ve dinh va canh
void MakeGraph(Graph& graph, string file) {
	// doc file E11
	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	if (ReadArrayInputOfGraph(file, vertexDataArr, vertexCount, edgeDataArr, edgeCount)) {
		// insert dinh
		for (int i = 0; i < vertexCount; i++) 
			graph.InsertVertex(vertexDataArr[i]);
		// insert canh
		for (int i = 0; i < edgeCount; i++) 
			graph.InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
}

int** GraphToMatrix(Graph graph) {
	// tao ma tran
	int n = graph.size;
	// mang 2 chieu matrix de luu ma tran
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	// mang 1 chieu data de luu chi so cua cac vertex
	int* data = new int[n];
	// vong lap luu data vao mang 1 chieu
	Vertex* pTemp = graph.gHead;
	int i = 0;
	while (pTemp) {
		data[i] = pTemp->data;
		i++;
		pTemp = pTemp->nextVertex;
	}
	// vong lap lap ma tran lien ke
	pTemp = graph.gHead;
	Edge* pTemp1 = NULL;
	i = 0;
	// di het cac dinh
	while (pTemp) {
		pTemp1 = pTemp->firstEdge;
		// di het cac canh bat dau tu dinh nay
		while (pTemp1) {
			for (int j = 0; j < n; j++) {
				if (pTemp1->destination->data == data[j])
					matrix[i][j] = 1;
			}
			pTemp1 = pTemp1->nextEdge;
		}
		i++;
		pTemp = pTemp->nextVertex;
	}
	return matrix;
}

// E11
void E11GraphToMatrix() {
	Graph graph = Graph();
	// tao dinh va canh cho graph
	MakeGraph(graph, FILE11);
	// in graph
	//graph.Print();
	// chuyen graph sang dang ma tran lien ke
	int** matrix = GraphToMatrix(graph);
	// in ma tran
	int n = graph.size;
	cout << "ma tran lien ke cua graph : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "   ";
		cout << endl;
	}
}

// ham nay thuoc DFS, tim den het 1 chu trinh roi in ra
void RecursionE14(Vertex*& vertexroot, Stack& stack, int& countT, Vertex* vertexnow) {
	if (vertexnow->processed) {
		// neu quay tro lai goc dau tien thi ghi nhan 1 chu trinh
		if (vertexnow == vertexroot)
			stack.PrintStack(countT);
		// neu khong thi de quay tro lai buoc truoc
	}
	// neu di qua 1 dinh moi
	else {
		// danh dau da di qua
		vertexnow->processed = true;
		stack.Push(vertexnow->data);
		// tao vong lap cho Recursion
		Edge* pTemp = vertexnow->firstEdge;
		while (pTemp) {
			// buoc de qui phia sau khong can bao gi ve cho buoc de qui phia truoc
			RecursionE14(vertexroot, stack, countT, pTemp->destination);
			pTemp = pTemp->nextEdge;
		}
		// sua lai la chua di qua de tim them chu trinh moi
		vertexnow->processed = false;
		stack.Pop();
	}
}

// E14
void E14CircleGraph() {
	Graph graph = Graph();
	Stack stack = Stack();
	int countT = 0;
	// tao dinh va canh cho graph
	MakeGraph(graph, FILE11);
	// in graph
	//graph.Print();
	cout << "Cac chu trinh cua graph : " << endl;
	Vertex* pTemp = graph.gHead;
	while (pTemp) {
		RecursionE14(pTemp, stack, countT, pTemp);
		pTemp = pTemp->nextVertex;
	}
	cout << "Tong so chu trinh la " << countT << endl;
}

void RecursionE16(Vertex*& vertexroot, Vertex*& vertexnow, bool*& isconnected, int n) {
	Edge* pTemp = vertexnow->firstEdge;
	while (pTemp) {
		if (pTemp->destination->processed) {
			RecursionE16(vertexroot, pTemp->destination, isconnected, n + 1);
			if (isconnected[n + 1])
				isconnected[n] = true;
		}
		else
			if (pTemp->destination == vertexroot)
				isconnected[n] = true;
	}
}

// E16
// dua vao giai thuat Tajan de xet coi mot Graph co lien thong manh hay khong
void E16StronglyConnected() {
	Graph graph = Graph();
	MakeGraph(graph, FILE16);
	// ap dung thuat toan Tajan, bat dau tu 1 dinh, danh dau cac dinh lien thong manh vs dinh dau tien
	bool* isConnected = new bool[graph.size];
	isConnected[0] = true;
	for (int i = 1; i < graph.size; i++)
		isConnected[i] = false;
	RecursionE16(graph.gHead, graph.gHead, isConnected, 0);
	bool result = true;
	for (int i = 0; i < graph.size; i++)
		result = result & isConnected[i];
	if (result)
		cout << "Do thi nay la do thi lien thong manh" << endl;
	else
		cout << "Do thi nay khong phai la do thi lien thong manh" << endl;
}

int main() {
	E14CircleGraph();
	system("pause");
	return 0;
}