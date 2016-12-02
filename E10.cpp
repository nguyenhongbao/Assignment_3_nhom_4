void E10() {

	int *arr = NULL;
	int size = 0;

	if (ReadArrayInput("input/E10.txt", arr, size)){

		Heap h;
		h = h.ArrayToHeap(arr, size);
		h.PrintHeapTree();
		int **edgeDataArr;

		edgeDataArr = new int*[size-1];

		for (int i = 0; i < size - 1; i++)
			edgeDataArr[i] = new int[2];

		for (int i = 0; i < size/2; i++) {
			edgeDataArr[i][0] = h[i*2+1];
			edgeDataArr[i][1] = h[i*2 +2];
		}
		Graph g;

		for (int i = 0; i < size; i++) {
			g.InsertVertex(h[i]);
		}

		for (int i = 0; i < size/2; i++) {
			g.InsertEdge(h[i], edgeDataArr[i][0]);
			g.InsertEdge(h[i], edgeDataArr[i][1]);
			g.InsertEdge(edgeDataArr[i][0] ,h[i]);
			g.InsertEdge(edgeDataArr[i][1],h[i]);
		}

		g.Print();

		delete edgeDataArr;
	}
}
