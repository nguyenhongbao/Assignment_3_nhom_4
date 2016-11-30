#include <iostream>
#include "AVLTree.h"
#include "InputReader.h"
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <math.h>

#define FILE2 "e1.txt"
#define FILE3 "e3.txt"
#define FILE11 "e11.txt"
#define FILE15 "e15.txt"
#define FILE16 "e16.txt"
#define FILE17 "e17.txt"
#define FILE20a "e20a.txt"
#define FILE20b "e20b.txt"
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

void PrintMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "   ";
		cout << endl;
	}
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
	PrintMatrix(matrix, n);
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
void E16StronglyConnected() {
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

// E20
// y tuong la dua ve dang ma tran roi so sanh 2 ma tran voi nhau
void E20Isomorphous() {
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
		//graph.Print();
	}
}

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

void testAVL(int** matrix, int& n, Node*& root, int father, bool* processed, bool& result, Queue& queue) {
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
							queue.push(i + 1);
					}
				}
			}
			if (queue.front != 0)
				testAVL(matrix, n, root, queue.pop(), processed, result, queue);
		}
		else {
			father = father;
			result = false;
		}
 	}
}

void LNRtoQueue(Node* AVLroot, Queue& queue) {
	if (AVLroot) {
		LNRtoQueue(AVLroot->left, queue);
		queue.push(AVLroot->data);
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
		Queue queue;
		testAVL(matrix, n, AVLroot, zero, processed, result, queue);
		// tuy nhien, phep thu tren van chua xac dinh duoc co phai cay theo dung thu tu cua cay AVL hay khong 
		// va cay co chua day du dinh cua Graph hay khong
		// de lam duoc dieu do can duyet LNR cay AVL vua tao
		if (result) {
			Queue queue2;
			LNRtoQueue(AVLroot, queue2);
			int i = 0;
			while (queue2.size) {
				i++;
				if (queue2.pop() != i) {
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

int main() {
	//////////Head();
	//////////bool stop = false;
	//////////stop = getStop();
	//////////if (!stop) {
	//////////	while (!stop) {
	//////////		system("clr");
	//////////		int n = 0;
	//////////		bool redo = true;
	//////////		while (redo) {
	//////////			cout << "Moi thay nhap ma so cua bai tap nho (20 bai tap): ";
	//////////			cin >> n;
	//////////			redo = false;
	//////////			switch (n) {
	//////////			case 1:
	//////////				// thao tac co ban voi AVL tree (Insert)
	//////////				Exercise1();
	//////////				break;
	//////////			case 2:
	//////////				// thao tac co ban voi AVL tree (Delete)
	//////////				Exercise2();
	//////////				break;
	//////////			case 3:
	//////////				// dem so nut chan le, nguyen to co trong cay AVL
	//////////				Exercise3();
	//////////				break;
	//////////			case 4:
	//////////				// thao tac co ban voi Heap (Insert)
	//////////				Exercise4();
	//////////				break;
	//////////			case 5:
	//////////				// thao tac co ban voi Graph (in Graph)
	//////////				Exercise5();
	//////////				break;
	//////////			case 6:
	//////////				
	//////////				Exercise6();
	//////////				break;
	//////////			case 7:
	//////////				Exercise7();
	//////////				break;
	//////////			case 8:
	//////////				Exercise8();
	//////////				break;
	//////////			case 9:
	//////////				Exercise9();
	//////////				break;
	//////////			case 10:
	//////////				Exercise10();
	//////////				break;
	//////////			case 11:
	//////////				Exercise11();
	//////////				break;
	//////////			case 12:
	//////////				Exercise12();
	//////////				break;
	//////////			case 13:
	//////////				Exercise13();
	//////////				break;
	//////////			case 14:
	//////////				Exercise14();
	//////////				break;
	//////////			case 15:
	//////////				Exercise15();
	//////////				break;
	//////////			case 16:
	//////////				Exercise16();
	//////////				break;
	//////////			case 17:
	//////////				Exercise17();
	//////////				break;
	//////////			case 18:
	//////////				Exercise18();
	//////////				break;
	//////////			case 19:
	//////////				Exercise19();
	//////////				break;
	//////////			case 20:
	//////////				Exercise20();
	//////////				break;
	//////////			default:
	//////////				cout << "thay da nhap sai, moi thay nhap lai trong it phut..." << endl;
	//////////				redo = true;
	//////////				break;
	//////////			}
	//////////		}
	//////////		// hoi thay coi co tiep tuc test cac E con lai khong
	//////////		stop = getStop();
	//////////	}
	//////////}
	//E11GraphToMatrix();
	//E20Isomorphous();
	Exercise17();
	system("pause");
	return 0;
}