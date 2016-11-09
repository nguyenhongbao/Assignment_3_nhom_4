#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
using namespace std;
/**
*\file LQueue.h
*/
template <class T>
class LQueue{
private:
	struct node{
		T data;
		node* next;
	};
	int size;
	node* qRear;
	node* qFront;
public:
	LQueue();
	~LQueue();
	bool isEmpty() const;
	bool isFull() const;
	bool enQueue(const T dataIn);
	bool deQueue(T& dataOut);
	void clearQueue();
	void printLQueue() const;
};

template <class T>
LQueue<T>::LQueue(){
	this->size = 0;
	this->qRear = NULL;
	this->qFront = NULL;
}
template <class T>
LQueue<T>::~LQueue(){
	this->clearQueue();
}
template <class T>
bool LQueue<T>::isEmpty()const{
	return size == 0;
}
template <class T>
bool LQueue<T>::isFull() const{
	node* pNew = new node();
	if (!pNew) return true;
	return false;
}
template <class T>
bool LQueue<T>::enQueue(const T dataIn){
	if (this->isFull()) return false;
	node* pNew = new node();
	pNew->data = dataIn;
	pNew->next = NULL;
	if (this->isEmpty()){
		this->qFront = pNew;
	}
	else{
		this->qRear->next = pNew;
	}
	this->size++;
	this->qRear = pNew;
	return true;
};
template <class T>
bool LQueue<T>::deQueue(T& dataOut){
	if (this->isEmpty()) return false;
	node* pDel = this->qFront;
	dataOut = this->qFront->data;
	this->qFront = this->qFront->next;
	if (size == 1) qRear = NULL;
	this->size--;
	delete pDel;
	return true;
}
template <class T>
void LQueue<T>::clearQueue(){
	if (this->isEmpty()) return;
	node* pDel;
	while (this->qFront != NULL)
	{
		pDel = this->qFront;
		this->qFront = this->qFront->next;
		delete pDel;
	}
	this->qRear = this->qFront = NULL;
}
#endif
