#ifndef __MIN_HEAP_H
#define __MIN_HEAP_H

#include "Pair.h"

class Min_heap {
private:
	Pair data[100];
	int heapSize = 0;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Pair Min();
	Pair deleteMin();
	int insert(Pair& item);
	bool isEmpty() { return heapSize < 1; }
	int getSize() { return heapSize; }
	void setSize(int size) { heapSize = size; }
	void delete_from_ind(int ind);
};

#endif
