#ifndef __MAX_HEAP_H
#define __MAX_HEAP_H

constexpr int H_SIZE = 100;
#include "Pair.h"

class Max_heap {
private:
	Pair data[H_SIZE];
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Pair Max();
	Pair deleteMax();
	void insert(Pair item);
};

#endif

