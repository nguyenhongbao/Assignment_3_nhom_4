#include "GraphW.h"
#include "LStack.h"
void matrix2GraphWeight(int **mat, int count, GraphW &gG){
	for (int i = 1; i <= count; i++){
		gG.InsertVertex(i);
	}
	for (int i = 0; i < count; i++){
		for (int j = 0; j < count; j++)
			if (mat[i][j] > 0) {
				gG.InsertEdge(i + 1, j + 1, mat[i][j]);
			}
	}
}
void E18_problem(){
	int **mat, count;
	GraphW myGraph;
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
		
		myGraph.Dijkstra(source,distance,previous); //find shortest distance and save to distance array

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
	GraphW myGraph;
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
		vector<int> previous;

		cout << "\nTim duong di ngan nhat:\n";
		cout << "Nhap dinh bat dau:\n";
		cin >> source;
		cout << "Nhap dinh can den:\n";
		cin >> destination;
		cout << "Cac dinh khong di qua:	(-1 to exit)\n";

		while(true){
			cout << "Nhap diem khong di qua:\n";
			int temp;
			cin >> temp;
			if (temp == -1) break;
			if (temp == destination || temp == source){
				cout << "Khong the khong di qua diem dau va diem cuoi!!\n";
			}
			else myGraph.MarkVertex(temp);
			
		}
			
		myGraph.Dijkstra(source, distance, previous); //find shortest distance and save to distance array
		//previous array holds previous vertex
		if (distance[destination - 1] != INT_MAX && 
			myGraph.VertexExist(source) && myGraph.VertexExist(destination)){

			cout << "Duong di tu dinh " << source << " toi dinh "
				<< destination << " la: " << distance[destination - 1] << endl;

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
