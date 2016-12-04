#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include "source/AVLTree.h"
#include "source/InputReader.h"
#include "source/Graph.h"
#include "source/Stack.h"
#include "source/Queue.h"
#include "source/Heap.h"
#include <string.h>
#include <math.h>

#define FILE2 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E2.txt"
#define FILE3 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E3.txt"
#define FILE5 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E5.txt"
#define FILE6 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E6.txt"
#define FILE7 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E7.txt"
#define FILE8 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E8.txt"
#define FILE9 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E9.txt"
#define FILE10 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E10.txt"
#define FILE11 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E11.txt"
#define FILE12 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E12.txt"
#define FILE13 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E13.txt"
#define FILE14 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E14.txt"
#define FILE15 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E15.txt"
#define FILE16 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E16.txt"
#define FILE17 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E17.txt"
#define FILE18 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E18.txt"
#define FILE19 "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E19.txt"
#define FILE20a "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E20a.txt"
#define FILE20b "D:\\CAU TRUC DU LIEU VA GIAI THUAT\\assignment3-1.3\\assignment3-1.3\\input\\E20b.txt"
using namespace std;

struct BoolLinked {
	bool data;
	BoolLinked* next;
};
/////////////////////////////////////////////////////////////////////////
// E1
void Exercise1() {
	int n;
	cout << "Nhap N: ";	cin >> n;
	int *arr = new int[n];
	AVLTree avltree;
	for (int i = 0; i <= n - 1; i++) {
		cout << "arr[" << i + 1 << "]: ";
		cin >> arr[i];
		avltree.AVLInsert(arr[i]);
	}
	avltree.PrintAVL();
}
/////////////////////////////////////////////////////////////////////////
// E2
void Exercise2() {
	// doc file
	int* arr = NULL;
	int count = 0;
	if (ReadArrayInput(FILE2, arr, count)) {
		// chuyen mang sang cay AVL
		AVLTree avltree = AVLTree();
		avltree = avltree.ArrayToAVL(arr, count);

		// vong lap xoa
		string numberstr = "0";
		int number = 0;
		avltree.PrintAVL();
		cout << "Moi ban nhap chi so cua node can xoa (neu khong muon xoa nua nhap -1) : ";
		getline(cin, numberstr);
		number = atoi(numberstr.c_str());
		while (number != -1) {
			if (!avltree.AVLDelete(number))
				cout << "chi so ban nhap khong co trong cay" << endl;
			avltree.PrintAVL();
			cout << "Moi ban nhap chi so cua node can xoa (neu khong muon xoa nua nhap -1) : ";
			getline(cin, numberstr);
			number = atoi(numberstr.c_str());
		}
	}
}
/////////////////////////////////////////////////////////////////////////
// E3
// ham kiem tra so nguyen to
bool IsIng(int N) {
	if (N >= 3) {
		bool ising = true;
		// chi can kiem tra so co chia het cho nhung so nho hon can bac 2 cua no thoi
		int max = (int)sqrt((double)N);
		for (int i = 3; i <= max; i++) {
			if (N % i == 0) {
				ising = false;
				break;
			}
		}
		return ising;
	}
	else
		return false;
}

// ham de qui duyet cay va dem so chan le nguyen to
void LNRcount(Node*& subroot, int& even, int& odd, int& ing) {
	if (subroot) {
		LNRcount(subroot->left, even, odd, ing);
		// kiem tra so
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

void Exercise3() {
	// doc file
	int* arr = NULL;
	int count = 0;
	if (ReadArrayInput(FILE3, arr, count)) {
		// chuyen mang sang cay AVL
		AVLTree avltree = AVLTree();
		avltree = avltree.ArrayToAVL(arr, count);
		int even = 0, odd = 0, ing = 0;
		LNRcount(avltree.root, even, odd, ing);
		cout << "Cay AVL nay co " << even << " so chan, " << odd << " so le va " << ing << " so nguyen to" << endl;
	}
}
///////////////////////////////////////////////////////////////////////

void Exercise4() {
	int N = 0;
	while (N < 1) {
		cout << "Nhap so phan tu cua mang:" << endl;
		cin >> N;
	}
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "Nhap phan tu arr[" << i << "]:" << endl;
		cin >> arr[i];
	}
	Heap p;
	p = p.ArrayToHeap(arr, N);
	p.PrintHeapTree();
}
////////////////////////////////////////////////////////////////////////
void Graph::Print() {

	Vertex* pTemp = gHead;
	Edge* eG = (gHead) ? gHead->firstEdge : NULL;

	cout << "Print this Graph: \n";

	for (int i = 0; i < this->size; i++) {
		if (pTemp) {
			cout << pTemp->data;
			if (pTemp->firstEdge) {
				eG = pTemp->firstEdge;
				while (eG) {
					cout << "->" << eG->destination->data;

					if (!eG->nextEdge) {
						cout << "->NULL \n|\n";
						break;
					}
					else
						eG = eG->nextEdge;
				}
			}
			else
				cout << "->NULL \n|\n";
			pTemp = pTemp->nextVertex;
		}
	}

	cout << "NULL\n";
}

void Exercise5() {

	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	Graph myGraph;
	if (ReadArrayInputOfGraph(FILE5, vertexDataArr, vertexCount, edgeDataArr, edgeCount)) {
		// insert dinh
		for (int i = 0; i < vertexCount; i++)
			myGraph.InsertVertex(vertexDataArr[i]);
		// insert canh
		for (int i = 0; i < edgeCount; i++)
			myGraph.InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	myGraph.Print();
}
////////////////////////////////////////////////////////////////////////

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

// ham xoa 1 canh, return true neu xoa duoc va false neu khong
bool Graph::RemoveEdge(Vertex* from, Vertex* to) {
	if (from->firstEdge) {
		Edge* pTemp = from->firstEdge;
		// neu ngay canh dau tien la canh can xoa
		if (from->firstEdge->destination == to) {
			from->firstEdge = pTemp->nextEdge;
			pTemp->nextEdge = NULL;
			delete pTemp;
			return true;
		}
		else {
			while (pTemp->nextEdge) {
				if (pTemp->nextEdge->destination == to)
					break;
				pTemp = pTemp->nextEdge;
			}
			// bay gio pTemp se chi vao node phia truoc node can xoa hoac node phia sau pTemp la NULL
			// neu tim ra canh can xoa
			if (pTemp->nextEdge) {
				Edge* pDelete = pTemp->nextEdge;
				pTemp->nextEdge = pDelete->nextEdge;
				pDelete->nextEdge = NULL;
				delete pDelete;
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}

bool Graph::RemoveEdge(int fromData, int toData) {
	Vertex* from = GetVertex(fromData);
	if (from->firstEdge) {
		Edge* pTemp = from->firstEdge;
		// neu ngay canh dau tien la canh can xoa
		if (from->firstEdge->destination->data == toData) {
			from->firstEdge = pTemp->nextEdge;
			pTemp->nextEdge = NULL;
			delete pTemp;
			return true;
		}
		else {
			while (pTemp->nextEdge) {
				if (pTemp->nextEdge->destination->data == toData)
					break;
				pTemp = pTemp->nextEdge;
			}
			// bay gio pTemp se chi vao node phia truoc node can xoa hoac node phia sau pTemp la NULL
			// neu tim ra canh can xoa
			if (pTemp->nextEdge) {
				Edge* pDelete = pTemp->nextEdge;
				pTemp->nextEdge = pDelete->nextEdge;
				pDelete->nextEdge = NULL;
				delete pDelete;
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}

// 
bool Graph::RemoveVertex(int reData) {
	bool result = true;
	Vertex* pTemp = this->gHead;
	if (this->gHead) {
		while (pTemp) {
			RemoveEdge(pTemp->data, reData);
			pTemp = pTemp->nextVertex;
		}
		pTemp = this->gHead;
		if (this->gHead->data == reData) {
			this->gHead = pTemp->nextVertex;
			pTemp->nextVertex = NULL;
			delete pTemp;
		}
		else {
			while (pTemp->nextVertex) {
				if (pTemp->nextVertex->data == reData)
					break;
				pTemp = pTemp->nextVertex;
			}
			// bay gio pTemp se chi vao node phia truoc node can xoa hoac node phia sau pTemp la NULL
			// neu tim ra canh can xoa
			if (pTemp->nextVertex) {
				Vertex* pDelete = pTemp->nextVertex;
				pTemp->nextVertex = pDelete->nextVertex;
				pDelete->nextVertex = NULL;
				delete pDelete;
			}
			else
				result = false;
		}
	}
	return result;
}

// E6
void Exercise6() {
	Graph graph;
	MakeGraph(graph, FILE6);
	// vong lap xoa
	string numberstr = "0";
	int number = 0;
	cout << "Moi ban nhap chi so cua vertex can xoa (neu khong muon xoa nua nhap -1) : ";
	getline(cin, numberstr);
	number = atoi(numberstr.c_str());
	while (number != -1) {
		if (!graph.RemoveVertex(number))
			cout << "chi so ban nhap khong co trong graph" << endl;
		graph.Print();
		cout << "Moi ban nhap chi so cua vertex can xoa (neu khong muon xoa nua nhap -1) : ";
		getline(cin, numberstr);
		number = atoi(numberstr.c_str());
		graph.RemoveVertex(number);
	}
}
///////////////////////////////////////////////////////////////////

void BFS2Stack(Node*pRoot, LStack<Node*>*&BFS) {
	if (pRoot != NULL) {
		Node *pTemp = pRoot;
		Node *nullNode = new Node(0);
		LQueue<Node*> *qTemp = new LQueue<Node*>();
		qTemp->enQueue(pTemp);
		while (!qTemp->isEmpty()) {
			qTemp->deQueue(pTemp);
			Node* NewOne = new Node(pTemp->data);
			BFS->pushStack(NewOne);
			// 4 truong hop
			if (pTemp->left) {
				qTemp->enQueue(pTemp->left);
				// co ca 2 canh con
				if (pTemp->right)
					qTemp->enQueue(pTemp->right);
				// chi co canh con ben trai
				else
					qTemp->enQueue(nullNode);
			}
			else {
				// chi co canh con ben phai
				if (pTemp->right) {
					qTemp->enQueue(pTemp->right);
					qTemp->enQueue(nullNode);
				}
				// la node la
				else {
					// neu co data
					if (pTemp->data) {
						qTemp->enQueue(nullNode);
						qTemp->enQueue(nullNode);
					}
					// neu khong co data thi no la node ao
				}
			}
		}
	}
}

void Exercise7() {
	int *arr;
	int count;
	if (ReadArrayInput(FILE7, arr, count)) {
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();
		LStack<Node*> *sTemp = new LStack<Node*>();
		BFS2Stack(myAVL.root, sTemp);
		int h = 0, sum = 0;
		sTemp = sTemp->reverse();
		while (!sTemp->isEmpty()) {
			for (int i = 0; i < pow(2, h); i++) {
				Node* pNode = NULL;
				if (sTemp->popStack(pNode)) {
					sum += pNode->data;
				}
			}
			if (!sTemp->isEmpty())
				cout << sum << endl;
			sum = 0;
			h++;
		}
	}
}
/////////////////////////////////////////////////////////////////////
void Exercise8() {
	int *arr;
	int count = 0;
	if (ReadArrayInput(FILE8, arr, count)) {
		Heap myHeap;
		myHeap = myHeap.ArrayToHeap(arr, count);
		myHeap.PrintHeapTree();
		int h = (int)log2(count) + 1; //height of tree
		int start = 0, end = 0;
		int sum;
		cout << "Trong so heap theo do cao:\n";
		for (int i = 0; i < h; i++) {
			sum = 0; //rest sum
			end = pow(2, i) + start; // position to stop
			for (int j = start; j < end && j < count; j++) {
				sum += myHeap[j];
				start = j + 1;
			}
			cout << "h = " << i + 1 << ": " << sum << endl;
		}
	}
}
/////////////////////////////////////////////////////////////////////
Graph& AVL2Graph(AVLTree& tree) {
	Graph graph;
	Node *p = tree.root;
	LStack<Node*> sTemp;
	sTemp.pushStack(p);
	Node *pTemp;
	//traverse các node c?a cây và thêm vào graph
	while (!sTemp.isEmpty()) {
		sTemp.popStack(pTemp);
		if (pTemp) {
			if (!graph.VertexExist(pTemp->data))
				graph.InsertVertex(pTemp->data); // thêm node vào graph n?u node ch?a t?n t?i
			if (pTemp->left) {
				if (!graph.VertexExist(pTemp->left->data)) graph.InsertVertex(pTemp->left->data); // thêm node con vào graph n?u node ch?a t?n t?i
				graph.InsertEdge(pTemp->data, pTemp->left->data); // chèn c?nh t? node cha t?i node con bên trái
				sTemp.pushStack(pTemp->left); // thêm node con vào stack
			}
			if (pTemp->right) {
				if (!graph.VertexExist(pTemp->right->data)) graph.InsertVertex(pTemp->right->data); // thêm node con vào graph n?u node ch?a t?n t?i
				graph.InsertEdge(pTemp->data, pTemp->right->data);  // chèn c?nh t? node cha t?i node con bên ph?i
				sTemp.pushStack(pTemp->right); // thêm node con vào stack
			}
		}
	}
	return graph;
}
void Exercise9() {
	int *arr;
	int count;
	if (ReadArrayInput(FILE9, arr, count)) {
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();  // in AVL Tree
		Graph graph = AVL2Graph(myAVL); //chuy?n  AVL Tree sang graph
		graph.Print(); //in graph
	}

}
///////////////////////////////////////////////////////////////////
void Exercise10() {
	int *arr = NULL;
	int size = 0;
	if (ReadArrayInput(FILE10, arr, size)) {

		Heap h;
		h = h.ArrayToHeap(arr, size);
		// in cay
		h.PrintHeapTree();

		Graph g;
		// insert dinh
		for (int i = 0; i < size; i++) {
			g.InsertVertex(h[i]);
		}
		// insert canh
		for (int i = 0; i < size; i++) {
			if (2 * i + 1 < size) {
				g.InsertEdgeFromVertices(g.GetVertex(h[i]), g.GetVertex(h[2 * i + 1]));
				g.InsertEdgeFromVertices(g.GetVertex(h[2 * i + 1]), g.GetVertex(h[i]));
			}
			if (2 * i + 2 < size) {
				g.InsertEdgeFromVertices(g.GetVertex(h[i]), g.GetVertex(h[2 * i + 2]));
				g.InsertEdgeFromVertices(g.GetVertex(h[2 * i + 2]), g.GetVertex(h[i]));
			}
		}
		// in graph
		g.Print();
	}
}
///////////////////////////////////////////////////////////////////
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

void PrintMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "   ";
		cout << endl;
	}
}

void PrintMatrixWithData(int** matrix, int* data, int n) {
	cout << "     ";
	for (int i = 0; i < n; i++)
		cout << setw(5) << data[i];
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(5) << data[i];
		for (int j = 0; j < n; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}
}

// E11
void Exercise11() {
	Graph graph = Graph();
	// tao dinh va canh cho graph
	MakeGraph(graph, FILE11);
	// in graph
	graph.Print();
	// chuyen graph sang dang ma tran lien ke
	int** matrix = GraphToMatrix(graph);
	// in ma tran
	// tao mang data luu cac chi so cua cac Vertex
	int n = graph.size;
	int* data = new int[n];
	// vong lap luu data vao mang 1 chieu
	Vertex* pTemp = graph.gHead;
	int i = 0;
	while (pTemp) {
		data[i] = pTemp->data;
		i++;
		pTemp = pTemp->nextVertex;
	}
	cout << "ma tran lien ke cua graph : " << endl;
	PrintMatrixWithData(matrix, data, n);
}
/////////////////////////////////////////////////////////////////////
void Exercise12() {
	int *arr;
	int count;
	if (ReadArrayInput(FILE12, arr, count)) {
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();
		Graph graph = AVL2Graph(myAVL); // chuy?n AVL Tree sang graph
										//graph.Print();
		int **mat = GraphToMatrix(graph);  // chuy?n graph sang ma tr?n
										   // in ma tr?n
										   // in ma tran
										   // tao mang data luu cac chi so cua cac Vertex
		int n = graph.size;
		int* data = new int[n];
		// vong lap luu data vao mang 1 chieu
		Vertex* pTemp = graph.gHead;
		int i = 0;
		while (pTemp) {
			data[i] = pTemp->data;
			i++;
			pTemp = pTemp->nextVertex;
		}
		cout << "ma tran lien ke cua cay AVL : " << endl;
		PrintMatrixWithData(mat, data, n);
	}
}
///////////////////////////////////////////////////////////////////////

void Exercise13() {
	Heap heap;
	// doc file vao 1 mang
	int* arr;
	int count = 0;
	ReadArrayInput(FILE13, arr, count);
	// chuyen mang vao Heap
	heap.ArrayToHeap(arr, count);
	// ma tran lien ke luu heap, gia tri ban dau deu bang 0
	int** matrix = new int*[count];
	for (int i = 0; i < count; i++) {
		matrix[i] = new int[count];
		for (int j = 0; j < count; j++)
			matrix[i][j] = 0;
	}
	int* data = new int[count];
	// khong can biet data cua no, chi dua vao chi so
	for (int i = 0; i < count; i++) {
		// neu co canh ben trai thi tao lien ket cha con
		if (2 * i < count) {
			matrix[i][2 * i + 1] = 1;
			matrix[2 * i + 1][i] = 1;
		}
		// neu co canh ben phai thi tao lien ket cha con
		if (2 * i + 1 < count) {
			matrix[i][2 * i + 2] = 1;
			matrix[2 * i + 2][i] = 1;
		}
		// luu key vao data
		data[i] = heap[i];
	}
	PrintMatrixWithData(matrix, data, count);
}

////////////////////////////////////////////////////////////////////////////////
// ham nay thuoc DFS, tim den het 1 chu trinh roi in ra
void RecursionE14(Vertex*& vertexroot, LStack<int>& stack, int& countT, Vertex* vertexnow) {
	if (vertexnow->processed) {
		// neu quay tro lai goc dau tien thi ghi nhan 1 chu trinh
		countT++;
		// neu khong thi de quay tro lai buoc truoc
	}
	// neu di qua 1 dinh moi
	else {
		// danh dau da di qua
		vertexnow->processed = true;
		stack.pushStack(vertexnow->data);
		// tao vong lap cho Recursion
		Edge* pTemp = vertexnow->firstEdge;
		while (pTemp) {
			// buoc de qui phia sau khong can bao gi ve cho buoc de qui phia truoc
			RecursionE14(vertexroot, stack, countT, pTemp->destination);
			pTemp = pTemp->nextEdge;
		}
		// sua lai la chua di qua de tim them chu trinh moi
		vertexnow->processed = false;
		stack.popStack();
	}
}

// E14
void Exercise14() {
	Graph graph = Graph();
	LStack<int> stack = LStack<int>();
	int countT = 0;
	// tao dinh va canh cho graph
	MakeGraph(graph, FILE14);
	// in graph
	graph.Print();
	Vertex* pTemp = graph.gHead;
	while (pTemp) {
		RecursionE14(pTemp, stack, countT, pTemp);
		pTemp = pTemp->nextVertex;
	}
	cout << "Tong so chu trinh la " << countT << endl;
}
/////////////////////////////////////////////////////////////////////////
Graph& MatrixtoGraph(int** matrix, int n) {
	Graph graph;
	// tao dinh
	for (int i = 0; i < n; i++) {
		graph.InsertVertex(i + 1);
	}
	// tao canh
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j])
				graph.InsertEdgeFromVertices(graph.GetVertex(i + 1), graph.GetVertex(j + 1));
		}
	}
	return graph;
}

// E15
void Exercise15() {
	int** matrix;
	int count = 0;
	if (ReadAdjacencyMat(FILE15, matrix, count)) {
		cout << "Ma tran : " << endl;
		PrintMatrix(matrix, count);
		Graph graph;
		graph = MatrixtoGraph(matrix, count);
		graph.Print();
	}
}
/////////////////////////////////////////////////////////////////////
void RecursionE16(Vertex*& vertexroot, Vertex*& vertexnow) {
	Edge* pTemp = vertexnow->firstEdge;
	vertexnow->processed = true;
	while (pTemp) {
		if (!pTemp->destination->processed) {
			RecursionE16(vertexroot, pTemp->destination);
			if (pTemp->destination->inDegree)
				vertexnow->inDegree = 1;
		}
		else
			if (pTemp->destination->inDegree)
				vertexnow->inDegree = 1;
		pTemp = pTemp->nextEdge;
	}
}

// E16
// dua vao giai thuat Tajan de xet coi mot Graph co lien thong manh hay khong
void Exercise16() {
	Graph graph = Graph();
	MakeGraph(graph, FILE16);
	// dung inDegree cua Vertex de luu thong tin ve lien thong
	// sao luu lai inDegree nay trong mang inDegreeTemp
	int* inDegreeTemp = new int[graph.size];
	Vertex* pTemp = graph.gHead;
	int i = 0;
	while (pTemp) {
		inDegreeTemp[i] = pTemp->inDegree;
		i++;
		pTemp = pTemp->nextVertex;
	}
	// ap dung thuat toan Tajan, bat dau tu 1 dinh, danh dau cac dinh lien thong manh vs dinh dau tien
	RecursionE16(graph.gHead, graph.gHead);
	bool result = true;
	pTemp = graph.gHead;
	i = 0;
	while (pTemp) {
		result = result & (bool)pTemp->inDegree;
		pTemp->inDegree = inDegreeTemp[i];
		i++;
		pTemp = pTemp->nextVertex;
	}
	if (result)
		cout << "Do thi nay la do thi lien thong manh" << endl;
	else
		cout << "Do thi nay khong phai la do thi lien thong manh" << endl;
}
////////////////////////////////////////////////////////////////////////////////
/* mot so luu y:
+ ta da biet dinh co the la root
+ ta biet rang khong co dinh nao trung key voi nhau
Vay,cong viec can lam la:
+ kiem tra so dinh con cua moi dinh
+ kiem tra balance cua moi dinh
+ kiem tra thu tu
*/
////void testAVL(Vertex* vnow, bool& result) {
////	if (result) {
////		if (!vnow->processed) {
////			Edge* pTemp = vnow->firstEdge;
////			int count = 0;
////			while (pTemp) {
////				count++;
////				testAVL(pTemp->destination, result);
////				if (count == 2) {
////					// neu ma co mot dinh con thu 3
////					if (pTemp->nextEdge) {
////						result = false;
////						return;
////					}
////					// neu cay co 2 dinh con thi khong can lam gi ca
////				}
////				// neu cay chi co 1 dinh con
////				else {
////
////				}
////				pTemp = pTemp->nextEdge;
////			}
////		}
////		else
////			result = false;
////	}
////}

// ham nay tao hinh cay theo dung nhung gi ma tran mieu ta, dong thoi check coi no co phai la cay AVL hay khong
bool InsertAVLtest(Node*& root, int newdata, int father, bool& taller) {
	bool result = true;
	if (root == NULL) {
		root = new Node(newdata);
		taller = true;
		return true;
	}
	else if (father < root->data) {
		result = InsertAVLtest(root->left, newdata, father, taller);
		if (result) {
			//AVLinsert(newNode, taller);
			if (taller) {
				if (root->balance == LEFT) {
					return false;
				}
				else if (root->balance == EQUAL) {
					root->balance = LEFT;
				}
				else {
					root->balance = EQUAL;
					taller = false;
				}
			}
			return true;
		}
		else
			return false;
	}
	else if (father > root->data) {
		result = InsertAVLtest(root->right, newdata, father, taller);
		if (result) {
			if (taller) {
				if (root->balance == LEFT) {
					root->balance = EQUAL;
					taller = false;
				}
				else if (root->balance == EQUAL) {
					root->balance = RIGHT;
				}
				else {
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}
	// luc root la con tro chi den father
	else {
		// neu gan newdata ve ben phai
		if (newdata > father)
			if (root->right)
				return false;
			else {
				root->right = new Node(newdata);
				if (root->left)
					taller = false;
				else
					taller = true;
				return true;
			}
		else if (root->left)
			return false;
		else {
			root->left = new Node(newdata);
			if (root->right)
				taller = false;
			else
				taller = true;
			return true;
		}
	}
}

void testAVL(int** matrix, int& n, Node*& root, int father, bool* processed, bool& result, LQueue<int>& queue) {
	if (result) {
		if (!processed[father - 1]) {
			processed[father - 1] = true;
			int count = 0;
			int dataleft = 0, dataright = 0;
			for (int i = 0; i < n; i++) {
				if (matrix[father - 1][i]) {
					count++;
					// neu co 3 con
					if (count == 3) {
						result = false;
						return;
					}
					else {
						bool taller = true;
						// neu khong phai cay AVL
						if (!InsertAVLtest(root, i + 1, father, taller)) {
							result = false;
							return;
						}
						else
							queue.enQueue(i + 1);
					}
				}
			}
			if (!queue.isEmpty())
				testAVL(matrix, n, root, queue.deQueue(), processed, result, queue);
		}
		else {
			father = father;
			result = false;
		}
	}
}

void LNRtoQueue(Node* AVLroot, LQueue<int>& queue) {
	if (AVLroot) {
		LNRtoQueue(AVLroot->left, queue);
		queue.enQueue(AVLroot->data);
		LNRtoQueue(AVLroot->right, queue);
	}
}

// ham kiem tra ma tran la cay AVL
bool isMatrixaAVL(int** matrix, int n) {
	bool result = false;
	// B1 : tim dinh nao khong co dinh cha thi no co the la root cua cay AVL
	// nghia la tim cot nao toan la so khong
	int count = -1;
	bool allzero = true;
	int i = 0;
	for (i = 0; i < n; i++) {
		allzero = true;
		for (int j = 0; j < n; j++) {
			if (matrix[j][i]) {
				allzero = false;
				break;
			}
		}
		if (allzero)
			break;
	}
	if (allzero) {
		int zero = i + 1;
		Node* AVLroot = new Node(zero);
		bool* processed = new bool[n];
		for (int i = 0; i < n; i++) {
			processed[i] = false;
		}
		result = true;
		LQueue<int> queue;
		testAVL(matrix, n, AVLroot, zero, processed, result, queue);
		// tuy nhien, phep thu tren van chua xac dinh duoc co phai cay theo dung thu tu cua cay AVL hay khong 
		// va cay co chua day du dinh cua Graph hay khong
		// de lam duoc dieu do can duyet LNR cay AVL vua tao
		if (result) {
			LQueue<int> queue2;
			LNRtoQueue(AVLroot, queue2);
			int i = 0;
			while (!queue2.isEmpty()) {
				i++;
				if (queue2.deQueue() != i) {
					result = false;
					break;
				}
			}
			// kiem tra cay co chua tat ca cac dinh khong
			if (i != n)
				result = false;
		}
	}
	return result;
}


// E17
// kiem tra ma tran la cay AVL
void Exercise17() {
	int** matrix;
	int count = 0;
	if (ReadAdjacencyMat(FILE17, matrix, count)) {
		cout << "Ma tran : " << endl;
		PrintMatrix(matrix, count);
		if (isMatrixaAVL(matrix, count))
			cout << "Ma tran nay bieu dien cho mot cay AVL" << endl;
		else
			cout << "Ma tran nay KHONG THE bieu dien cho mot cay AVL" << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
class EdgeI : public Edge {
public:
	int weight;
	EdgeI(Vertex* _destination, int _weight) :Edge(_destination) {
		this->weight = _weight;
	};

};
void ClearMarks(Graph &gG) {
	if (!gG.gHead) 
		return;
	Vertex* p = gG.gHead;
	while (p) {
		p->processed = 0;
		p = p->nextVertex;
	}
}
void Dijkstra(int source, int* &dist, vector<int> &previous, Graph &gG) {
	dist = new int[gG.size];
	//Make an array to save from the src distance
	//dist[i] will hold the shortest
	previous = vector<int>(gG.size);
	// the array to hold the previous vertex of a vertex 
	for (int i = 0; i < gG.size; i++) {
		if (i == source - 1)
			dist[i] = 0; // if source vertex, dist[ source - 1] = 0 index  of array is from 0
		else
			dist[i] = INT_MAX; //set another to infinity
		previous[i] = -1; // previous = -1
	}
	Vertex* vTemp = gG.GetVertex(source); // get vertex from source
	while (vTemp) {
		EdgeI* eTemp = (EdgeI*)vTemp->firstEdge;
		vTemp->processed = 1; // mark vertex is visited
		while (eTemp) {
			//if a vertex is not visited , and distance from src is not inf 
			//and distance[previous vertex] + Edge Weight < distance[this vertex ], update its distance
			if (eTemp->destination->processed == 0 && dist[vTemp->data - 1] != INT_MAX && dist[vTemp->data - 1] + eTemp->weight < dist[eTemp->destination->data - 1]) {
				dist[eTemp->destination->data - 1] = dist[vTemp->data - 1] + eTemp->weight;
				previous[eTemp->destination->data - 1] = vTemp->data; //update previous vertex of this vertex
																	  /*for (int i = 0; i < this->size; i++){
																	  cout << previous[i] << " ";
																	  }
																	  cout << endl;*/
			}
			eTemp = (EdgeI*)eTemp->nextEdge;
		}
		int min = INT_MAX;
		int temp = 0;
		//get next vertex to process
		for (int i = 0; i < gG.size; i++) {
			if (dist[i] != 0 && dist[i] < min && gG.GetVertex(i + 1)) {
				if (gG.GetVertex(i + 1)->processed == 0) {
					temp = i + 1;
					min = dist[i];
				}
			}
		}
		vTemp = gG.GetVertex(temp);
	}
	ClearMarks(gG); //Clear Marks
					//printSolution(dist, this->size);
}

bool MarkVertex(Graph &gG, int data) {
	if (gG.VertexExist(data)) {
		Vertex *vTemp = gG.GetVertex(data);
		vTemp->processed = 1;
		return true;
	}
	else return false;

}
bool MarkVertex(Graph &gG, Vertex* toMark) {
	if (toMark) {
		if (gG.VertexExist(toMark)) {
			toMark->processed = 1;
			return true;
		}
		else return false;
	}
	return false;
}


void matrix2GraphWeight(int **mat, int count, Graph &gG) {
	for (int i = 1; i <= count; i++) {
		gG.InsertVertex(i);
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
			if (mat[i][j] > 0) {
				Vertex* vGa = gG.GetVertex(i + 1);
				Vertex* vGb = gG.GetVertex(j + 1);
				EdgeI* I = new EdgeI(vGb, mat[i][j]);
				gG.InsertEdge(vGa, I);
			}
	}
}
void Exercise18() {
	int **mat, count;
	Graph myGraph;
	if (ReadAdjacencyMat(FILE18, mat, count)) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		matrix2GraphWeight(mat, count, myGraph); //convert matrix to graph
		myGraph.Print(); // print out the graph

		int source, destination;
		int *distance = NULL;
		vector<int> previous;

		cout << "\nTim duong di ngan nhat:\n";
		cout << "Nhap dinh bat dau:\n";
		cin >> source;
		cout << "Nhap dinh can den:\n";
		cin >> destination;

		Dijkstra(source, distance, previous, myGraph); //find shortest distance and save to distance array

		if (distance[destination - 1] != INT_MAX && myGraph.VertexExist(source) && myGraph.VertexExist(destination)) {
			cout << "Duong di tu dinh " << source << " toi dinh "
				<< destination << " la: " << distance[destination - 1] << endl;
		}
		else cout << "Khong tim thay duong di tu dinh " << source << " toi dinh " << destination << ".\n";
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void Exercise19() {
	int **mat, count;
	Graph myGraph;
	if (ReadAdjacencyMat(FILE19, mat, count)) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		matrix2GraphWeight(mat, count, myGraph); //convert matrix to graph
		myGraph.Print();	//print the graph
		int source, destination;
		int *distance = NULL;
		vector<int> previous, exceptV;

		cout << "\nTim duong di ngan nhat:\n";
		cout << "Nhap dinh bat dau:\n";
		cin >> source;
		cout << "Nhap dinh can den:\n";
		cin >> destination;
		cout << "Cac dinh khong di qua:	(< 0 to exit)\n";

		while (true) {
			cout << "Nhap diem khong di qua:\n";
			int temp;
			cin >> temp;
			if (temp < 0) break;
			if (temp == destination || temp == source) {
				cout << "Khong the khong di qua diem dau va diem cuoi!!\n";
			}
			else if (!myGraph.VertexExist(temp))
				cout << "Dinh nay khong co trong graph!\n";
			else if (find(exceptV.begin(), exceptV.end(), temp) != exceptV.end())
				cout << "Diem da nhap roi!\n";
			else {
				MarkVertex(myGraph, temp);
				exceptV.push_back(temp);
			}
		}

		Dijkstra(source, distance, previous, myGraph); //find shortest distance and save to distance array
													   //previous array holds previous vertex
		if (distance[destination - 1] != INT_MAX && myGraph.VertexExist(source) && myGraph.VertexExist(destination)) {
			cout << "Duong di tu dinh " << source << " toi dinh " << destination << " ma khong di qua dinh ";
			for (int i = 0; i < exceptV.size(); i++)
				cout << exceptV[i] << ", ";
			cout << " la: " << distance[destination - 1] << endl;

			LStack<int> step;
			step.pushStack(destination);
			if (destination != source) {
				int i = destination - 1;
				while (previous[i] != source) {
					step.pushStack(previous[i]);
					i = previous[i] - 1;
				}
			}
			step.pushStack(source);

			cout << "Cac dinh da di qua la:\n";
			while (!step.isEmpty()) {
				int dataOut;
				step.popStack(dataOut);
				cout << dataOut << " ";
			}
			cout << endl;
		}
		else cout << "Khong tim thay duong di tu dinh " << source << " toi dinh " << destination << ".\n";
	}

}
/////////////////////////////////////////////////////////////////////////////////
// E20
// y tuong la dua ve dang ma tran roi so sanh 2 ma tran voi nhau
void Exercise20() {
	// tao graph va chuyen sang dang ma tran
	Graph grapha = Graph();
	MakeGraph(grapha, FILE20a);
	int** Matrixa = GraphToMatrix(grapha);
	Graph graphb = Graph();
	MakeGraph(graphb, FILE20b);
	int** Matrixb = GraphToMatrix(graphb);

	// so sanh lan luot cac hang ma tran a so voi ma tran b
	if (grapha.size == graphb.size) {
		// mang nay de luu thong tin ve nhung hang da xet roi trong Matrixb
		int n = grapha.size;
		int i = 0;
		int k = 0;
		int j = 0;
		bool* Given = new bool[n];
		for (i = 0; i < n; i++) {
			Given[i] = false;
		}
		// vong lap Matrix a
		for (i = 0; i < n; i++) {
			if (i == 2)
				i = 2;
			// vong lap Matrix b
			for (j = 0; j < n; j++) {
				// neu hang nay chua bang bat ki mot hang nao cua ma tran a
				if (!Given[j]) {
					for (k = 0; k < n; k++) {
						if (Matrixa[i][k] != Matrixb[j][k])
							break;
					}
				}
				// neu canh nay trung voi canh dang xet cua a
				if (k == n) {
					k = 0;
					// thi chap nhan canh nay
					Given[j] = true;
					break;
				}
				// nguoc lai thi den canh tiep theo
			}
			// neu khong co hang nao giong hang nay
			if (j == n) {
				// thi ket thuc thuat toan, ket luan khong dang cau
				break;
			}
		}
		if (i == n)
			cout << "2 do thi nay dang cau voi nhau." << endl;
		else
			cout << "2 do thi nay khong dang cau." << endl;
	}
}

void Head() {
	cout << "                                    =====Dai hoc Bach Khoa thanh pho Ho Chi Minh=====" << endl
		<< "                                           Khoa Khoa Hoc va Ky Thuat May Tinh" << endl
		<< "                                                Nganh Khoa Hoc May Tinh" << endl << endl << endl << endl
		<< "                                                 BAO CAO BAI TAP LON" << endl
		<< "                                         mon cau truc du lieu va giai thuat" << endl
		<< "                                                giang vien huong dan: " << endl
		<< "                                                  Lop L01, Nhom 4: " << endl
		<< "                                             1510175_Nguyen Hong Bao (Nhom truong)" << endl
		<< "                                             1510580_Trinh Minh Dung" << endl
		<< "                                             1510612_Nguyen Truong Duy" << endl;
}

bool getStop() {
	char y = ' ';
	cout << "De tiep tuc, xin moi thay bam Y (hoac y) : ";
	cin >> y;
	bool stop = true;
	if ((y == 'Y') || (y == 'y'))
		stop = false;
	return stop;
}



int main() {
	Head();
	bool stop = false;
	stop = getStop();
	if (!stop) {
		while (!stop) {
			system("cls");
			int n = 0;
			bool redo = true;
			while (redo) {
				fflush(stdin);
				cin.ignore(1000,'\n');
				cout << "Moi thay nhap ma so cua bai tap nho (20 bai tap): ";
				cin >> n;
				if ((n > 0) && (n <= 20)) {
					redo = false;
					switch (n) {
					case 1:
						// thao tac co ban voi AVL tree (Insert)
						Exercise1();
						break;
					case 2:
						// thao tac co ban voi AVL tree (Delete)
						Exercise2();
						break;
					case 3:
						// dem so nut chan le, nguyen to co trong cay AVL
						Exercise3();
						break;
					case 4:
						// thao tac co ban voi Heap (Insert)
						Exercise4();
						break;
					case 5:
						// thao tac co ban voi Graph (in Graph)
						Exercise5();
						break;
					case 6:
						// thao tac co ban voi Graph (xoa Vertex)
						Exercise6();
						break;
					case 7:
						// tinh trong so cua cay AVL theo do cao
						Exercise7();
						break;
					case 8:
						// tinh trong so cua heap thoe do cao
						Exercise8();
						break;
					case 9:
						// chuyen cay AVL snag Graph
						Exercise9();
						break;
					case 10:
						// chuyen 1 heap sang Graph
						Exercise10();
						break;
					case 11:
						// chuyen 1 graph sang ma tran lien ke
						Exercise11();
						break;
					case 12:
						// chuyen 1 cay AVL sang ma tran lien ke
						Exercise12();
						break;
					case 13:
						// chuyen 1 heap sang ma tran lien ke
						Exercise13();
						break;
					case 14:
						// dem tong so chu trinh trong Graph
						Exercise14();
						break;
					case 15:
						// chuyen ma tran lien ke sang graph
						Exercise15();
						break;
					case 16:
						// kiem tra xem 1 graph co lien thong manh hay khong
						Exercise16();
						break;
					case 17:
						// kiem tra xem 1 ma tran lien ke co bieu dien cho 1 cay AVL hay khong
						Exercise17();
						break;
					case 18:
						// tim duong di ngan nhat cua graph
						Exercise18();
						break;
					case 19:
						// tim duong di ngan nhat cua graph khong di qua 1 so dinh
						Exercise19();
						break;
					case 20:
						// kiem tra 2 do thi dang cau
						Exercise20();
						break;
					default:
						break;
					}
				}
				else {
					cout << "thay da nhap sai, moi thay nhap lai.." << endl;
					_flushall();
					redo = true;
					continue;
				}
			}
			// hoi thay coi co tiep tuc test cac E con lai khong
			stop = getStop();
		}
	}
	
	return 0;
}