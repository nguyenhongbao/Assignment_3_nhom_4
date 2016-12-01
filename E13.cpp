void E13() {
	
	int *arr = NULL;
	int size = 0;

	ReadArrayInput("input/E13.txt", arr, size);

	Heap h;						//Khai bao heap

	h = h.ArrayToHeap(arr, size);

	h.PrintHeapTree();			//In heap
	
	//Chuyen heap thanh ma tran lien ke
	int **arraymatrix;
	arraymatrix = new int*[size];
	
	cout << "Heap chuyen sang ma tran lien ke : " << endl;

	cout << setw(5) << left << " ";
	for (int i = 0; i <= size - 1; i++)
	{
		arraymatrix[i][1] = h[i];
		cout << setw(5) << left << h[i];
	}

	cout << endl;

	for (int i = 0; i <= size - 1; i++)
	{
		arraymatrix[i][2] = h[1];
		cout << setw(5) << left << h[i];
		for (int j = 0; j <= size - 1; j++)
		{
			if (i * 2 + 1 == j || i * 2 + 2 == j)
			{
				cout << setw(5) << left << 1;
			}
			else
			{
				cout << setw(5) << left << 0;
			}

		}
		cout << endl;
	}

	delete[] arr;
}
