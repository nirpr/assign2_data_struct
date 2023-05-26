#ifndef __MIN_HEAP_H
#define __MIN_HEAP_H

constexpr int H_SIZE = 100;
#include "Pair.h"

class Min_heap {
private:
	Pair data[H_SIZE];
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Pair Min();
	Pair deleteMin();
	void insert(Pair item);
};

#endif
