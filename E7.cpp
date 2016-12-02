#include "AVLTree.h"
#include "InputReader.h"
#include "LQueue.h"
#include "LStack.h"

void BFS2Stack(Node*pRoot, LStack<Node*>*&BFS){
	if (pRoot != NULL){
		Node *pTemp = pRoot;
		Node *nullNode = new Node(0);
		LQueue<Node*> *qTemp = new LQueue<Node*>();
		qTemp->enQueue(pTemp);
		while (!qTemp->isEmpty()){
			qTemp->deQueue(pTemp);
			Node* NewOne = new Node(pTemp->data);		
			BFS->pushStack(NewOne);
			if (pTemp->data != 0){				
				if (pTemp->left) qTemp->enQueue(pTemp->left);
				if (pTemp->right) qTemp->enQueue(pTemp->right);
				if (pTemp->left && !pTemp->right) qTemp->enQueue(nullNode);
				if (!pTemp->left && pTemp->right) qTemp->enQueue(nullNode);
				if (!pTemp->left && !pTemp->right){
					qTemp->enQueue(nullNode);
					qTemp->enQueue(nullNode);
				}
			}
		}
	}

}
void E7_problem(){
	int *arr;
	int count;
	if (ReadArrayInput("input/E7.txt", arr, count)){
		AVLTree myAVL;
		myAVL = myAVL.ArrayToAVL(arr, count);
		myAVL.PrintAVL();
		LStack<Node*> *sTemp = new LStack<Node*>();
		BFS2Stack(myAVL.root, sTemp);
		int h = 0, sum = 0;
		sTemp = sTemp->reverse();
		while (!sTemp->isEmpty()){
			sum = 0; //rest sum
			for (int i = 0; i < pow(2, h); i++){
				Node* pNode = NULL;
				if (sTemp->popStack(pNode)){
					sum += pNode->data;
				}

			}
			if (sum > 0) cout << sum << endl;		
			h++;
		}
	}
}
