#include  <limits>
#include <vector>
#include "Graph.h"
#include "InputReader.h"
#include "LStack.h"
class EdgeI : public Edge{
public:
	int weight;
	EdgeI(Vertex* _destination, int _weight) :Edge(_destination){
		this->weight = _weight;
	};

};
void ClearMarks(Graph &gG){
	if (!gG.gHead) return;
	Vertex* p = gG.gHead;
	while (p){
		p->processed = 0;
		p = p->nextVertex;
	}
}
void Dijkstra(int source, int* &dist, vector<int> &previous ,Graph &gG){
	dist = new int[gG.size];
	//Make an array to save from the src distance
	//dist[i] will hold the shortest
	previous = vector<int>(gG.size);
	// the array to hold the previous vertex of a vertex 
	for (int i = 0; i < gG.size; i++)
	{
		if (i == source - 1) dist[i] = 0; // if source vertex, dist[ source - 1] = 0 index  of array is from 0
		else dist[i] = INT_MAX; //set another to infinity
		previous[i] = -1; // previous = -1
	}
	Vertex* vTemp = gG.GetVertex(source); // get vertex from source
	while (vTemp){
		EdgeI* eTemp = (EdgeI*)vTemp->firstEdge;
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
			eTemp = (EdgeI*)eTemp->nextEdge;
			
		}
		int min = INT_MAX;
		int temp = 0;
		//get next vertex to process
		for (int i = 0; i < gG.size; i++){
			if (dist[i] != 0 && dist[i] < min && gG.GetVertex(i + 1)){
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

bool MarkVertex(Graph &gG ,int data){
	if (gG.VertexExist(data)){
		Vertex *vTemp = gG.GetVertex(data);
		vTemp->processed = 1;
		return true;
	}
	else return false;

}
bool MarkVertex(Graph &gG, Vertex* toMark){
	if (toMark){
		if (gG.VertexExist(toMark)){
			toMark->processed = 1;
			return true;
		}
		else return false;
	}
	return false;
}

void matrix2GraphWeight(int **mat, int count, Graph &gG){
	for (int i = 1; i <= count; i++){
		gG.InsertVertex(i);
	}
	for (int i = 0; i < count; i++){
		for (int j = 0; j < count; j++)
			if (mat[i][j] > 0) {
				Vertex* vGa = gG.GetVertex(i + 1);
				Vertex* vGb = gG.GetVertex(j + 1);
				EdgeI* I = new EdgeI(vGb, mat[i][j]);
				gG.InsertEdge(vGa, I);
			}
	}
}
void E18_problem(){
	int **mat, count;
	Graph myGraph;
	if (ReadAdjacencyMat("input/E18.txt", mat, count)){
		for (int i = 0; i < count; i++){
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
		
		Dijkstra(source,distance,previous,myGraph); //find shortest distance and save to distance array

		if (distance[destination - 1] != INT_MAX && 
			myGraph.VertexExist(source) && myGraph.VertexExist(destination)){
			cout << "Duong di tu dinh " << source << " toi dinh " 
				<< destination << " la: " << distance[destination - 1] << endl;
		}
		else cout << "Khong tim thay duong di tu dinh " << source << " toi dinh " << destination << ".\n";
	}
}
void E19_problem(){
	int **mat, count;
	Graph myGraph;
	if (ReadAdjacencyMat("input/E19.txt", mat, count)){
		for (int i = 0; i < count; i++){
			for (int j = 0; j < count; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		matrix2GraphWeight(mat, count, myGraph); //convert matrix to graph
		myGraph.Print();	//print the graph
		int source, destination;
		int *distance = NULL;
		vector<int> previous,exceptV;

		cout << "\nTim duong di ngan nhat:\n";
		cout << "Nhap dinh bat dau:\n";
		cin >> source;
		cout << "Nhap dinh can den:\n";
		cin >> destination;
		cout << "Cac dinh khong di qua:	(<0 to exit)\n";

		while(true){
			cout << "Nhap diem khong di qua:\n";
			int temp;
			cin >> temp;
			if (temp <= 0) break;
			if (temp == destination || temp == source){
				cout << "Khong the khong di qua diem dau va diem cuoi!!\n";
			}
			else if (!myGraph.VertexExist(temp)) cout << "Dinh nay khong co trong graph!\n";
			else if (find(exceptV.begin(), exceptV.end(), temp) != exceptV.end())
				cout << "Diem da nhap roi!\n";
			else {
				MarkVertex(myGraph, temp);
				exceptV.push_back(temp);
			}
			
		}
			
		Dijkstra(source, distance, previous,myGraph); //find shortest distance and save to distance array
		//previous array holds previous vertex
		if (distance[destination - 1] != INT_MAX && 
			myGraph.VertexExist(source) && myGraph.VertexExist(destination)){
			cout << "Duong di tu dinh " << source << " toi dinh "
				<< destination << " ma khong di qua dinh " ;
				for (int i = 0; i < exceptV.size(); i++)
					cout << exceptV[i] << ", ";
			cout << " la: " << distance[destination - 1] << endl;

			LStack<int> step;
			step.pushStack(destination);
			if (destination != source){
				int i = destination - 1;
				while (previous[i] != source){
					step.pushStack(previous[i]);
					i = previous[i] - 1;
				}
			}
			step.pushStack(source);

			cout << "Cac dinh da di qua la:\n";
			while (!step.isEmpty()){
				int dataOut;
				step.popStack(dataOut);
				cout << dataOut << " ";
			}
			cout << endl;
		}
		else cout << "Khong tim thay duong di tu dinh " << source << " toi dinh " << destination << ".\n";
	}

}
