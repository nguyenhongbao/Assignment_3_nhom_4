#include "Graph.h"
#include "InputReader.h"

void Graph::Print(){
	
	Vertex* pTemp = gHead;
	Edge* eG = (gHead) ? gHead->firstEdge : NULL;

	cout << "Print this Graph: \n";

	for (int i = 0; i < this->size; i++){
		if (pTemp) {
			if (pTemp){
				cout << pTemp->data;
				if (pTemp->firstEdge){
					eG = pTemp->firstEdge; 
					while (eG){

						cout << "->" << eG->destination->data;

						if (!eG->nextEdge) {
							cout << "->NULL \n|\n";
							break;
						}
						else eG = eG->nextEdge;

					}
				}
				else  cout << "->NULL \n|\n";
			}
		}

		pTemp = pTemp->nextVertex;
	}

	cout << "NULL\n";	
}
void E5_problem(){

	int *vertexDataArr;
	int vertexCount;
	int **edgeDataArr;
	int edgeCount;
	Graph myGraph;
	if (ReadArrayInputOfGraph("input/E5.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount)) {
		// insert dinh
		for (int i = 0; i < vertexCount; i++)
			myGraph.InsertVertex(vertexDataArr[i]);
		// insert canh
		for (int i = 0; i < edgeCount; i++)
			myGraph.InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	}
	myGraph.Print();
}
