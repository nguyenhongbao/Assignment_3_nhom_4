#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::Push(int NewData) {
	NodeStack* NewNode = new NodeStack;
	NewNode->data = NewData;
	NewNode->next = head;
	head = NewNode;
	this->size++;
}

int Stack::Pop() {
	if (head) {
		NodeStack* pTemp = head;
		head = head->next;
		this->size--;
		return pTemp->data;
	}
	else
		return 0;
}

void Stack::PrintStack(int& countT) {
	if (head) {
		countT ++;
		NodeStack* pTemp = head;
		while (pTemp) {
			cout << " - " << pTemp->data;
			pTemp = pTemp->next;
		}
		cout << endl;
	}
}