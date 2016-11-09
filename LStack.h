#ifndef LSTACK_H
#define LSTACK_H
#include <iostream>
using namespace std;
/**
*\file LStack.h
*/
template <class T>
class LStack{
private:
	struct node{
		T data;
		node* next;
	};
	int size;
	node* top;
public:

	LStack() :size(0), top(NULL){};
	~LStack(){ clearStack(); };
	bool isEmpty() const;
	bool isFull() const;
	bool pushStack(const T dataIn);
	bool popStack(T& dataOut);
	bool topStack(T& dataOut) const;
	void clearStack();
	void printStack() const;
	int getSize() const;
	LStack<T>* reverse();
};
template <class T>
int LStack<T>::getSize() const{
	return this->size;
};
template <class T>
bool LStack<T>::isEmpty() const{
	return size == 0;
}
template <class T>
bool LStack<T>::isFull() const{
	node* pNew = new node();
	if (!pNew) return true;
	return false;
}
template <class T>
LStack<T>* LStack<T>::reverse()
{
	LStack<T> *sTemp = new LStack<T>();
	while (!this->isEmpty())
	{
		T newOne;
		this->popStack(newOne);
		sTemp->pushStack(newOne);
	}
	return sTemp;
};
template <class T>
bool LStack<T>::pushStack(const T dataIn){
	if (this->isFull()) return false;
	node* pNew = new node();
	pNew->data = dataIn;
	pNew->next = NULL;
	if (this->isEmpty()){
		this->top = pNew;
	}
	else{
		pNew->next = this->top;
		this->top = pNew;
	}
	this->size++;
	return true;
};
template <class T>
bool LStack<T>::popStack(T& dataOut){
	if (this->isEmpty()) return false;
	node* pDel = this->top;
	dataOut = this->top->data;
	this->top = this->top->next;
	this->size--;
	delete pDel;
	pDel = NULL;
	return true;
}
template <class T>
void LStack<T>::clearStack(){
	if (this->isEmpty()) return;
	node* pDel;
	while (this->top != NULL)
	{
		pDel = this->top;
		this->top = this->top->next;
		delete pDel;
	}
	this->size = 0;
	this->top = NULL;
	pDel = NULL;
}
template <class T>
void LStack<T>::printStack() const
{
	cout << "Top ";
	if (isEmpty()) cout << " ";
	else {
		node* pTemp = this->top;
		while (pTemp != NULL){
			cout << pTemp->data << " ";
			pTemp = pTemp->next;
		}
	}
	cout << "Bottom" << endl;
};
template<class T>
bool LStack<T>::topStack(T& dataOut) const{
	if (this->isEmpty()) return NULL;
	return this->top->data;
};
#endif
