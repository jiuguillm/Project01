#pragma once
#ifndef HEAP_H
#define HEAP_H

struct ELEMENT {

	int key;
};
class HEAP
{
public:
	int capacity = 0;
	int size;
	ELEMENT *H;
public:
	HEAP Initialize(int n);
	void BuildHeap(HEAP heap, ELEMENT A[], int n);
	void Insert(HEAP heap, int k, int flag);
	void DeleteMin(HEAP heap, int flag);
	void DecreaseKey(HEAP heap, int index, int value, int flag);
	void printHeap(HEAP heap);
};

#endif