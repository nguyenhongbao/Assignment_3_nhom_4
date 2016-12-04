bool Graph::RemoveEdge(Vertex* from, Edge* from_to){
	if (!from || !from_to) return false;
	if (!this->VertexExist(from)) return false;
	Edge* eG = from->firstEdge, *ePre = from->firstEdge;
	if (from->firstEdge == from_to){
		from->firstEdge = from->firstEdge->nextEdge;
		eG->destination->inDegree--;
		delete eG;
		eG = NULL;
		from->outDegree--;
		return true;
	}
	while (eG){
		if (eG == from_to)
		{
			if (eG->nextEdge) {
				ePre->nextEdge = eG->nextEdge;
			}
			else {
				ePre->nextEdge = eG = NULL;
			}
			from_to->destination->inDegree--;
			delete from_to;
			from_to = NULL;
			from->outDegree--;
			return true;
		}
		ePre = eG;
		eG = eG->nextEdge;
	}
	return false;

};
bool  Graph::RemoveEdge(Vertex* from, Vertex* to){
	if (!from || !to) return false;
	if (!this->VertexExist(from) || !this->VertexExist(to)) return false;
	Edge* eG = from->firstEdge;
	while (eG){
		if (eG->destination == to) {
			return this->RemoveEdge(from, eG);
		}
		eG = eG->nextEdge;
	}
	return false;
}
bool Graph::RemoveEdge(int fromData, int toData){
	//if (this->VertexExist(fromData) && this->VertexExist(toData))
	return RemoveEdge(GetVertex(fromData), GetVertex(toData));
	//return false;
}

bool Graph::RemoveVertex(Vertex* del)
{
	if (del == NULL) return false;
	//xoa Edge tu Vertex can xoa
	Vertex* vTemp = gHead;
	Edge* eG = NULL;
	while (vTemp)
	{
		eG = vTemp->firstEdge;
		while (eG && vTemp->firstEdge){
			if (eG->destination == del){ 
				RemoveEdge(vTemp, del); 
			}
			eG = eG->nextEdge;
		}
		vTemp = vTemp->nextVertex;
	}
	vTemp = gHead;
	Vertex *vPre = gHead;
	if (gHead == del){
		gHead = gHead->nextVertex;
		delete del;
		del = NULL;
		this->size--;
		return true;
	}
	while (vTemp != NULL){
		if (vTemp->data == del->data)
		{
			if (vTemp->nextVertex) {
				vPre->nextVertex = vTemp->nextVertex;
			}
			else {
				vPre->nextVertex =  NULL;
			}
			this->size--;
			delete vTemp;
			vTemp = del = NULL;
			return true;
		}
		vPre = vTemp;
		vTemp = vTemp->nextVertex;
	}
	return false;
}

bool Graph::RemoveVertex(int reData)
{
	if (!VertexExist(reData)) return false;
	return RemoveVertex(GetVertex(reData));

}
void E6() {
	Graph graph;
	MakeGraph(graph, "input/E6.txt");
	graph.Print();
	// vong lap xoa
	while (true){
		int delVertex;
		cout << "Moi ban nhap chi so cua vertex can xoa (neu khong muon xoa nua nhap -1) : ";
		cin >> delVertex;
		if (delVertex == -1) break;
		if (!graph.VertexExist(delVertex)) cout << "Chi so dinh ban nhap khong co trong graph! Vui long nhap lai!\n" << endl;
		else {
			graph.RemoveVertex(delVertex);
			graph.Print();
		}
	}
}
