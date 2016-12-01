void E10() {

	int *arr = NULL;
	int size = 0;

	if (ReadArrayInput("input/E10.txt", arr, size)){

		Heap h;
		h = h.ArrayToHeap(arr, size);
		int **edgeDataArr;

		edgeDataArr = new int*[size - 1];

		for (int i = 0; i < size - 1; i++)
			edgeDataArr[i] = new int[2];

		for (int i = 0; i < size - 1; i++) {
			edgeDataArr[i][0] = h[i / 2];
			edgeDataArr[i][1] = h[i + 1];
			edgeDataArr[0][i] = h[i / 2];
			edgeDataArr[1][i] = h[i + 1];
		}

		Graph g;

		for (int i = 0; i < size; i++) {
			g.InsertVertex(h[i]);
		}

		for (int i = 0; i < size - 1; i++) {
			g.InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
			g.InsertEdge(edgeDataArr[i][1], edgeDataArr[i][0]);
		}

		g.Print();

		delete edgeDataArr;
	}
}
