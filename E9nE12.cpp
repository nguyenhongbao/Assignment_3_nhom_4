#include <iostream>
#include "AVLTree.h"
#include "InputReader.h"
#include "Graph.h"
#include "LStack.h"
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
Graph AVL2Graph(AVLTree tree ){
	Graph graph;
	Node *p = tree.root;
	LStack<Node*> sTemp;
	sTemp.pushStack(p);
	Node *pTemp;
	//traverse các node của cây và thêm vào graph
	while (!sTemp.isEmpty()){
		sTemp.popStack(pTemp);
		if (!graph.VertexExist(pTemp->data)) graph.InsertVertex(pTemp->data); // thêm node vào graph nếu node chưa tồn tại
		if (pTemp->left) { 
			if (!graph.VertexExist(pTemp->left->data)) graph.InsertVertex(pTemp->left->data); // thêm node con vào graph nếu node chưa tồn tại
			graph.InsertEdge(pTemp->data, pTemp->left->data); // chèn cạnh từ node cha tới node con bên trái
			sTemp.pushStack(pTemp->left); // thêm node con vào stack
		}
		if (pTemp->right){ 
			if (!graph.VertexExist(pTemp->right->data)) graph.InsertVertex(pTemp->right->data); // thêm node con vào graph nếu node chưa tồn tại
			graph.InsertEdge(pTemp->data, pTemp->right->data);  // chèn cạnh từ node cha tới node con bên phải
			sTemp.pushStack(pTemp->right); // thêm node con vào stack
		}
	}
	return graph;
}
void E9_problem(){
	int *arr;
	int count;
	if (ReadArrayInput("input/E9.txt", arr, count)){
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();  // in AVL Tree
		Graph graph = AVL2Graph(myAVL); //chuyển  AVL Tree sang graph
		graph.Print(); //in graph
	}

}
void E12_problem(){
	int *arr;
	int count;
	if (ReadArrayInput("input/E12.txt", arr, count)){
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();
		Graph graph = AVL2Graph(myAVL); // chuyển AVL Tree sang graph
		//graph.Print();
		int **mat = GraphToMatrix(graph);  // chuyển graph sang ma trận
		// in ma trận
		for (int i = 0; i < graph.size ; i++){
			for (int j = 0; j < graph.size ; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		
	}
}
