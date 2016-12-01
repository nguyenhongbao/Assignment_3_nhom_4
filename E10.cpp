void E10() {

	int *arr = NULL;
	int size = 0;

	ReadArrayInput("input/E10.txt", arr, size);

	Heap h;
	h = h.ArrayToHeap(arr, size);
	int **edgeDtArr;

	edgeDtArr = new int*[size - 1];

	for (int i = 0; i < size - 1; i++)
		edgeDataArr[i] = new int[2];

	for (int i = 0; i < size - 1; i++) {
		edgeDtArr[i][0] = h[i / 2];
		edgeDtArr[i][1] = h[i + 1];
		edgeDtArr[0][i] = h[i / 2];
		edgeDtArr[1][i] = h[i + 1];
	}

	Graph g;

	for (int i = 0; i < size; i++) {
		g.InsertVertex(h[i]);
	}

	for (int i = 0; i < size - 1; i++) {
		g.InsertEdge(edgeDtArr[i][0], edgeDtArr[i][1]);
	}

	g.Print();

	delete edgeDtArr;
}