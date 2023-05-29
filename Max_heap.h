#ifndef __MAX_HEAP_H
#define __MAX_HEAP_H

#include "Pair.h"
#include <iostream>

constexpr int H_MAX_SIZE = 100;

class Max_heap {
private:
	Pair* data[H_MAX_SIZE];
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Max_heap();
	~Max_heap();
	Pair* Max();
	Pair* deleteMax();
	int insert(Pair* item);
	bool isEmpty() { return heapSize < 1; }
	int getSize() { return heapSize; }
	void setSize(int size) { heapSize = size; }
	Pair* delete_from_ind(int ind);
	void breakProgram();
	void heapFull();
};

#endif

