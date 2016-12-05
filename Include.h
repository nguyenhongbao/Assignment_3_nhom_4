#pragma once
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

int** GraphToMatrix(Graph graph);

void MakeGraph(Graph& graph, string file);

void PrintMatrix(int** matrix, int n);

void PrintMatrixWithData(int** matrix, int* data, int n);

Graph& MatrixtoGraph(int** matrix, int n);

Graph& AVL2Graph(AVLTree& tree);

void ClearMarks(Graph &gG);

void Dijkstra(int source, int* &dist, vector<int> &previous, Graph &gG);

bool MarkVertex(Graph &gG, int data);

bool MarkVertex(Graph &gG, Vertex* toMark);

void matrix2GraphWeight(int **mat, int count, Graph &gG);