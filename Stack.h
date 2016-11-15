#pragma once

struct NodeStack {
	int data = 0;
	NodeStack* next = NULL;
};

class Stack {
public:
	int size = 0;
	NodeStack* head = NULL;
	void Push(int NewData);
	int Pop();
	// ham in cac chu trinh cua mot chu trinh tim thay
	void PrintStack(int& countT);
};