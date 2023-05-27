#ifndef __MAX_HEAP_H
#define __MAX_HEAP_H
//constexpr int H_SIZE = 100;


#include "Pair.h"

class Max_heap {
private:
	Pair data[100];
	int heapSize = 0;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Pair Max();
	Pair deleteMax();
	int insert(Pair item);
	bool isEmpty() { return heapSize < 1; }
	int getSize() { return heapSize; }
	void setSize(int size) { heapSize = size; }
	void delete_from_ind(int ind);
};

#endif

