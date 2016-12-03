#include "Graph.h"
using namespace std;

bool Graph::RemoveEdge(Vertex* from, Vertex* to) 
{
	return false;
}

bool Graph::RemoveVertex(Vertex* del) 
{
	if (del == NULL) return false;
	Vertex* Pre = NULL;
	Vertex* Cur = this->gHead;
	Edge* Ed = this->gHead->firstEdge;	
	while (Cur)
	{
		if (del == this->gHead) 
		{
			// Xoa vertex hien tai		
			Edge* temp;
			while (this->gHead->firstEdge)
			{				
				temp = this->gHead->firstEdge;
				this->gHead->firstEdge = this->gHead->firstEdge->nextEdge;
				delete temp; temp = NULL;
				Ed = Ed->nextEdge;
			}
			// xoa dinh
			this->gHead = Cur->nextVertex;
			delete Cur; Cur = NULL;
			return true;
		}
		else if (Cur == del) // xac dinh vertex can xoa
		{
			// xoa danh sach cac canh cua dinh hien tai
			Edge* temp;
			while (this->gHead->firstEdge)
			{
				temp = this->gHead->firstEdge;
				this->gHead->firstEdge = this->gHead->firstEdge->nextEdge;
				delete temp; temp = NULL;
				Ed = Ed->nextEdge;
			}
			// xoa dinh
			Pre->nextVertex = Cur->nextVertex;
			delete Cur; Cur = NULL;
			return true;
		}
		// xoa cac canh noi tu cac dinh khac noi toi dinh can xoa
		Pre = Cur;
		Cur = Cur->nextVertex;
	}
	return false;
}

bool Graph::RemoveVertex(int reData) 
{
	Vertex* del = this->GetVertex(reData);
	if (del == NULL) return false;
	Vertex* Pre = NULL;
	Vertex* Cur = this->gHead;
	Edge* Ed = this->gHead->firstEdge;	
	Edge* cur = Cur->firstEdge;
	Edge* pre = NULL;
	Edge* temp = NULL;	
	while (Cur)
	{
		if (del == this->gHead)
		{
			// xoa danh sach cac canh cua dinh hien tai						
			while (this->gHead->firstEdge)
			{
				temp = this->gHead->firstEdge;
				this->gHead->firstEdge = this->gHead->firstEdge->nextEdge;
				delete temp; temp = NULL;
				Ed = Ed->nextEdge;
			}
			// xoa dinh
			this->gHead = Cur->nextVertex;
			delete Cur; Cur = NULL;
			return true;
		}
		else if (Cur == del) // da tim duoc vertex can xoa
		{
			// xoa danh sach cac canh cua dinh hien tai			
			while (this->gHead->firstEdge)
			{
				temp = this->gHead->firstEdge;
				this->gHead->firstEdge = this->gHead->firstEdge->nextEdge;
				delete temp; temp = NULL;
				Ed = Ed->nextEdge;
			}
			// xoa dinh
			Pre->nextVertex = Cur->nextVertex;
			delete Cur; Cur = NULL;
			return true;
		}		
		// xoa cac canh noi tu cac dinh khac noi toi dinh can xoa	
		cur = Cur->firstEdge;
		while (cur) 
		{
			if (reData == Cur->firstEdge->destination->data)
			{
				temp = Cur->firstEdge;
				Cur->firstEdge = temp->nextEdge;
				delete temp; temp = NULL;		
				break;
			}
			else if (reData == cur->destination->data) // da tim thay canh can xoa
			{
				pre->nextEdge = cur->nextEdge;
				delete cur; cur = NULL;			
				break;
			}
			pre = cur;
			cur = cur->nextEdge;
		}
		Pre = Cur;
		Cur = Cur->nextVertex;
	}
	return false;

}