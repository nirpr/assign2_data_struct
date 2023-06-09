#ifndef __MIN_HEAP_H
#define __MIN_HEAP_H

#include "Pair.h"
#include <iostream>

constexpr int H_MIN_SIZE = 100;

class Min_heap {
private:
	Pair* data[H_MIN_SIZE];
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Min_heap();
	~Min_heap();
	Pair* Min();
	Pair* deleteMin();
	int insert(Pair* item);
	bool isEmpty() { return heapSize < 1; }
	int getSize() { return heapSize; }
	void setSize(int size) { heapSize = size; }
	Pair* delete_from_ind(int ind);
	void breakProgram();
	void heapFull();
};

#endif
