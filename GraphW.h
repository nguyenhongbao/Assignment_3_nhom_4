#ifndef GraphW_H
#define GraphW_H
#include <cassert>
#include <iostream>
#include  <limits>
#include <vector>
using namespace std;

//For circular usage
/**
* \class EdgeW
* \brief Class EdgeW for GraphW structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* We don't allow duplicate EdgeWs in this assignment since there is no weight. \n
* Each EdgeW instance has two member: \c destination and \c nextEdgeW. \n
* \c destination is the VertexW that this EdgeW will point to. \n
* \c nextEdgeW is another EdgeW came from the same source of this EdgeW. \n
*/
class EdgeW;

/**
* \class VertexW
* \brief Class VertexW for GraphW structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* This ADT is actually just a linked list. \n
* <b>Note that two vertices connected by nextVertexW DOESN'T MEAN that they are connected in the GraphW G.</b> \n
* <b>VertexW A actually connects to VertexW B only if and only if there is an EdgeW in \c firstEdgeW linked list that point to B.</b> \n
*/

class VertexW {
public:
	/**
	* \var data
	* \brief VertexW data
	*/
	int data;

	/**
	* \var inDegree
	* \brief Number of EdgeWs that point to this VertexW
	*/
	int inDegree;


	/**
	* \var outDegree
	* \brief Number of EdgeWs that point out from this VertexW
	*/
	int outDegree;

	/**
	* \var nextVertexW
	* \brief Linked list, point to the next VertexW added into the GraphW (or NULL). \n
	* This does not mean that they are connected by an EdgeW in the GraphW. \n
	*/
	VertexW* nextVertex;

	/**
	* \var firstEdgeW
	* \brief Linked list, point to the first EdgeW of this VertexW (or NULL). \n
	* In this linked list, if there is an EdgeW that point to another VertexW then this VertexW and that VertexW are connected in GraphW G. \n
	*/
	EdgeW* firstEdge;

	/**
	* \var processed
	* \brief For traversal purpose, tell us if a node was pushed in the processing stack or not. \n
	*/
	int processed;

	/**
	* \brief Default constructor. \n Create a VertexW with data=0
	*/
	VertexW();

	/**
	* \brief Create a VertexW with \c data.
	*/
	VertexW(int data);
};

//Linked list that contains EdgeWs from a VertexW to other Vertices
//This class helps we to connect Vertices in a GraphW
class EdgeW {
public:
	/**
	* \var destination
	* \brief The VertexW that this EdgeW will point to.
	*/
	VertexW* destination;
	int weight;

	/**
	* \var nextEdgeW
	* \brief Another EdgeW came from the same source VertexW with this EdgeW.
	*/
	EdgeW* nextEdge;

	/**
	* \brief Default constructor. \n
	* This is illegal because an EdgeW should always come with a destination. \n
	* Use the other constructor instead. \n
	*/
	//DEPRECATED(EdgeW(), "Constructor error, an EdgeW should always come with a destination (VertexWW), try the other constructor instead");

	/**
	* \brief Create an EdgeW that point to \c destination.
	*/
	EdgeW(VertexW*);
	EdgeW(VertexW* _destination, int weight);
};

/**
* \class GraphW
* \brief Class GraphW data structure
*
* This is implemented accordingly to the book Data Structures: A Pseudocode Approach with C. \n
* Note that in this implementation, we do not allow data duplication.\n
* Although data duplication is common in real-life applications, it is avoided here to ease the workload of this assignment.\n
*/
class GraphW {
public:
	/**
	* \var gHead
	* \brief Store the first VertexW inserted into this GraphW. \N
	* Brought gHead back to public to allow easier coding for students
	*/
	VertexW* gHead;

	/**
	* \var size
	* \brief Number of Vertices in the GraphW
	*/
	int size;

	/**
	* \brief Helper function created to remove duplicate codes
	*/
	bool InsertEdgeFromVertices(VertexW* from, VertexW* to ,int weight);

	/**
	* \brief Default constructor.
	*/
	GraphW();

	/**
	* \brief Constructor that takes a VertexW as the first VertexW to this GraphW
	*/
	GraphW(VertexW* gHead);

	/**
	* \brief Insert new VertexW into the GraphW
	*/
	bool InsertVertex(VertexW*);

	/**
	* \brief Create a new VertexW with \c data and insert it into the GraphW.
	*/
	bool InsertVertex(int data);

	/**
	* \brief Remove VertexW from the GraphW.
	*/
	bool RemoveVertex(VertexW*);

	/**
	* \brief Remove VertexW with \c data=reData from the GraphW.
	*/
	bool RemoveVertex(int reData);

	/**
	* \brief Check if a VertexW exists in the GraphW
	*/
	bool VertexExist(VertexW* v);

	/**
	* \brief Check if a VertexW exists in the GraphW using the VertexW data
	*/
	bool VertexExist(int vData);

	/**
	* \brief Return Vettex* given \c data
	*/
	VertexW* GetVertex(int);

	/**
	* \brief Insert new EdgeW into the GraphW using 2 VertexW
	*/
	bool InsertEdge(VertexW* from, VertexW* to ,int weight);

	/**
	* \brief Create an EdgeW betweem two nodes with \c fromData and \c toData
	*/
	bool InsertEdge(int fromData, int toData ,int weight);

	/**
	* \brief Insert new EdgeW into the GraphW using a VertexW and an EdgeW
	*/
	bool InsertEdge(VertexW* from, EdgeW* from_to,int weight);

	/**
	* \brief Remove an EdgeW from the GraphW using 2 VertexW
	*/
	bool RemoveEdge(VertexW* from, VertexW* to);

	/**
	* \brief Remove the EdgeW betweem two nodes with \c fromData and \c toData
	*/
	bool RemoveEdge(int fromData, int toData);

	/**
	* \brief Remove an EdgeW using a VertexW and an EdgeW
	*/
	bool RemoveEdge(VertexW* from, EdgeW* from_to);

	/**
	* \brief Print the GraphW
	*/
	void Print();
	/**
	* \brief Mark a vertex is visited
	*/
	bool MarkVertex(int data);
	/**
	* \brief Mark a vertex is visited
	*/
	bool MarkVertex(VertexW* toMark);
	/**
	* \brief Clear marks 
	*/
	void ClearMarks(); 
	/**
	* \brief Dijkstra find shortest distance from source to another vertrices
	*/
	void Dijkstra(int source, int* &dist, vector<int> &previous);
};

#endif
