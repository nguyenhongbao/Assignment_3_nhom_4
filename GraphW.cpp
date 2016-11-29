/***************************************************
Data Structure & Algorithm Assignment 3
GraphW.cpp
Purpose: Implementation of GraphW related classes

clone from Graph.cpp
***************************************************/

#include "GraphW.h"

//***************************//
//VertexW class implementation//
//***************************//

VertexW::VertexW() {
	data = 0;
	nextVertex = NULL;
	inDegree = 0;
	outDegree = 0;
	processed = 0;
	firstEdge = NULL;
}

VertexW::VertexW(int _data) {
	data = _data;
	nextVertex = NULL;
	inDegree = 0;
	outDegree = 0;
	processed = 0;
	firstEdge = NULL;
}

//*************************//
//EdgeW class implementation//
//*************************//

EdgeW::EdgeW(VertexW* _destination) {
	destination = _destination;
	nextEdge = NULL;
}
EdgeW::EdgeW(VertexW* _destination ,int weight) {
	destination = _destination;
	nextEdge = NULL;
	this->weight = weight;
}

//**************************//
//GraphW class implementation//
//**************************//

GraphW::GraphW() {
	gHead = NULL;
	size = 0;
}

GraphW::GraphW(VertexW* _gHead) {
	gHead = _gHead;
	size = 1;
}

bool GraphW::InsertVertex(VertexW* v) {
	if (gHead == NULL) {
		gHead = v;
		size++;
		return true;
	}

	VertexW* pTemp = gHead;
	VertexW* pTail = NULL;
	while (pTemp != NULL) {
		//To avoid confusion, we do not allow Nodes with same data in our GraphW
		if (pTemp->data == v->data) {
			cout << "\nDifferent Vertices in a GraphW should have different data\n";
			cout << "VertexW insertion with data = " << pTemp->data << " failed\n";
			return false;
		}
		pTail = pTemp;
		pTemp = pTemp->nextVertex;
	}

	size++;
	pTail->nextVertex = v;
	return true;
}

bool GraphW::InsertVertex(int vData) {
	VertexW* newVertex = new VertexW(vData);
	if (gHead == NULL) {
		gHead = newVertex;
		size++;
		return true;
	}

	VertexW* pTemp = gHead;
	VertexW* pTail = NULL;
	while (pTemp != NULL) {
		//To avoid confusion, we do not allow Nodes with same data in our GraphW
		if (pTemp->data == vData) {
			cout << "\nDifferent Vertices in a GraphW should have different data\n";
			cout << "VertexW insertion with data = " << pTemp->data << " failed\n";
			return false;
		}
		pTail = pTemp;
		pTemp = pTemp->nextVertex;
	}

	size++;
	pTail->nextVertex = newVertex;
	return true;
}


bool GraphW::VertexExist(VertexW* v) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == v->data) {
			return true;
		}
		tmp = tmp->nextVertex;
	}
	return false;
}

bool GraphW::VertexExist(int vData) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == vData) {
			return true;
		}
		tmp = tmp->nextVertex;
	}
	return false;
}

VertexW* GraphW::GetVertex(int vData) {
	VertexW* tmp = gHead;
	while (tmp != NULL) {
		if (tmp->data == vData) {
			return tmp;
		}
		tmp = tmp->nextVertex;
	}
	return NULL;
}

bool GraphW::InsertEdgeFromVertices(VertexW* from, VertexW* to ,int weight) {
	if (from->firstEdge == NULL) {
		if (from->data == to->data) {
			return false;
		}
		from->outDegree++;
		to->inDegree++;
		from->firstEdge = new EdgeW(to,weight);
		//from->firstEdge
		return true;
	}
	else {
		//Check if an EdgeW already exists
		EdgeW* eTmp = from->firstEdge;
		EdgeW* EdgeWTail = eTmp;

		if (from->data == to->data) {
			//We do not allow a VertexW to point to itself
			//(It would be difficult for students to manage)
			cout << "\nA VertexW should not point to itself\n";
			cout << "EdgeW insertion failed\n";
			return false;
		}

		while (eTmp != NULL) {
			if (eTmp->destination->data == to->data) {
				//This EdgeW already exists, nothing to do here
				cout << "\nEdgeW already exists\n";
				cout << "EdgeW insertion failed\n";
				return false;
			}
			EdgeWTail = eTmp;
			eTmp = eTmp->nextEdge;
		}
		EdgeW* newEdgeW = new EdgeW(to, weight);
		from->outDegree++;
		to->inDegree++;
		EdgeWTail->nextEdge = newEdgeW;
	}
	return true;
}

bool GraphW::InsertEdge(VertexW* from, VertexW* to ,int weight) {
	//Perform checking if [from] and [to] exist in the GraphW yet
	if (!VertexExist(from)) {
		InsertVertex(from);
	}

	if (!VertexExist(to)) {
		InsertVertex(to);
	}

	return InsertEdgeFromVertices(from, to ,weight);
}

bool GraphW::InsertEdge(int fromData, int toData ,int weight) {
	//Perform checking if [from] and [to] exist in the GraphW yet
	if (!VertexExist(fromData)) {
		InsertVertex(fromData);
	}

	if (!VertexExist(toData)) {
		InsertVertex(toData);
	}

	VertexW* from = GetVertex(fromData);
	VertexW* to = GetVertex(toData);

	return InsertEdgeFromVertices(from, to ,weight);
}

bool GraphW::InsertEdge(VertexW* from, EdgeW* from_to, int weight){
	if (!VertexExist(from)) {
		InsertVertex(from);
	}

	VertexW* to = from_to->destination;

	if (!VertexExist(to)) {
		InsertVertex(to);
	}

	if (from->firstEdge == NULL) {
		if (from->data == to->data) {
			return false;
		}
		from->outDegree++;
		to->inDegree++;
		from->firstEdge = from_to;
		from_to->weight = weight;
		return true;
	}
	else {
		//Check if an Edge already exists
		EdgeW* eTmp = from->firstEdge;
		EdgeW* EdgeTail = eTmp;

		if (from->data == to->data) {
			//We do not allow a VertexW to point to itself
			//(It would be difficult for students to manage)
			cout << "\nA VertexW should not point to itself\n";
			cout << "EdgeW insertion failed\n";
			return false;
		}

		while (eTmp != NULL) {
			if (eTmp->destination->data == to->data) {
				//This EdgeW already exists, nothing to do here
				cout << "\nEdgeW already exists\n";
				cout << "EdgeW insertion failed\n";
				return false;
			}
			EdgeTail = eTmp;
			eTmp = eTmp->nextEdge;
		}
		from->outDegree++;
		to->inDegree++;
		EdgeTail->nextEdge = from_to;
	}
	from_to->weight = weight;
	return true;
}
void GraphW::Print(){
	VertexW* pTemp = gHead;
	EdgeW* eTemp = (gHead) ? gHead->firstEdge : NULL;
	cout << "Print this Graph: \n";
	for (int i = 0; i < this->size; i++){
		if (pTemp){
			// print out the data of a Vertrices and its Edges to other Vertrices
			cout << pTemp->data;
			if (pTemp->firstEdge){
				eTemp = pTemp->firstEdge;
				while (eTemp){
					cout << "--" << eTemp->weight <<"-->" 
						<< eTemp->destination->data;
					//if edge temp is NULL print NULL and break
					if (!eTemp->nextEdge) {
						cout << "->NULL \n|\n";
						break;
					}
					else eTemp = eTemp->nextEdge;
				}
			}
			else  cout << "->NULL \n|\n";
		}
		// Jump to next vertex
		pTemp = pTemp->nextVertex;
	}
	cout << "NULL\n";
}
void printSolution(int dist[], int size)
{
	cout << "Vertex   Distance from Source\n";
	for (int i = 0; i < size; i++)
		cout << i + 1 << "\t\t" << dist[i] << endl;
}

void GraphW::Dijkstra(int source ,int* &dist, vector<int> &previous){
	dist = new int[this->size]; 
	//Make an array to save from the src distance
	//dist[i] will hold the shortest
	previous = vector<int>(this->size);
	// the array to hold the previous vertex of a vertex 
	for (int i = 0; i < this->size; i++)
	{
		if (i == source - 1) dist[i] = 0; // if source vertex, dist[ source - 1] = 0 index  of array is from 0
		else dist[i] = INT_MAX; //set another to infinity
		previous[i] = -1; // previous = -1
	}
	VertexW* vTemp = GetVertex(source); // get vertex from source
	while (vTemp){
		EdgeW* eTemp = vTemp->firstEdge;
		vTemp->processed = 1; // mark vertex is visited
		while (eTemp){
			//if a vertex is not visited , and distance from src is not inf 
			//and distance[previous vertex] + Edge Weight < distance[this vertex ], update its distance
			if (eTemp->destination->processed == 0 && dist[vTemp->data - 1] != INT_MAX &&
				dist[vTemp->data - 1] + eTemp->weight < dist[eTemp->destination->data - 1]) {
				dist[eTemp->destination->data - 1] = dist[vTemp->data - 1] + eTemp->weight;
				previous[eTemp->destination->data - 1] = vTemp->data; //update previous vertex of this vertex
				/*for (int i = 0; i < this->size; i++){
					cout << previous[i] << " ";
				}
				cout << endl;*/
			}
			eTemp = eTemp->nextEdge;
		}
		int min = INT_MAX;
		int temp = 0;
		//get next vertex to process
		for (int i = 0; i < this->size; i++){
			if (dist[i] != 0 && dist[i] < min && GetVertex(i + 1)){
				if (GetVertex(i + 1)->processed == 0) {
					temp = i + 1;
					min = dist[i];
				}
			}
		}
		vTemp = GetVertex(temp);
	}
	ClearMarks(); //Clear Marks
	//printSolution(dist, this->size);
}

bool GraphW::MarkVertex(int data){
	if (VertexExist(data)){
		VertexW *vTemp = GetVertex(data);
		vTemp->processed = 1;
		return true;
	}
	else return false;

}
bool GraphW::MarkVertex(VertexW* toMark){
	if (toMark){
		if (VertexExist(toMark)){
			toMark->processed = 1;
			return true;
		}
		else return false;
	}
	return false;
}
void GraphW::ClearMarks(){
	if (!gHead) return;
	VertexW* p = gHead;
	while (p){
		p->processed = 0;
		p = p->nextVertex;
	}
}
